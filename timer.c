/*
 * timer.c : タイマープログラム（デフォルトでは3分タイマー）
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include "font.h"               /* 文字データ                     */
#define TRUE  1
#define FALSE 0

volatile sig_atomic_t almflag;  /* SIGALRMが発生した              */
volatile sig_atomic_t intflag;  /* SIGINTが発生した               */

/*
 *  花文字出力ルーチン
 */
void wfputs(char *str) {
  while (*str!='\0') {
    putchar(*str);
    putchar(*str++);
  }
}

/*
 * タイマー表示
 */
void tprint(int time) {              /* 時刻表示用 */
  int m,s,mu,ml,su,sl;

  fputs("\033[2J\033[5;0H",stdout);  /* 画面クリア */
  if (time<=0) {
    time *= -1;
    fputs("\033[31m",stdout);        /* 赤色に     */
  }  else {
    fputs("\033[32m",stdout);        /* 緑色に     */
  }

  m = time / 60;
  s = time % 60;
  mu = m / 10;
  ml = m % 10;
  su = s / 10;
  sl = s % 10;

  for (int i=0; i<16; i++) {
    putchar(' ');
    fputs(font[mu][i],stdout);
    putchar(' ');
    putchar(' ');
    fputs(font[ml][i],stdout);
    putchar(' ');
    putchar(' ');
    fputs(font[10][i],stdout);
    putchar(' ');
    putchar(' ');
    fputs(font[su][i],stdout);
    putchar(' ');
    putchar(' ');
    fputs(font[sl][i],stdout);
    putchar('\n');
  }

  fputs("\033[0m",stdout);  /* 既定の属性へもどす */
}
  
/*
 *  SIGINT の処理ルーチン
 */
void sigint(int sig) {
  intflag=TRUE;
}

/*
 *  SIGALRM の処理ルーチン
 */
void sigalarm(int sig) {
  almflag = TRUE;
}

/*
 * main ルーチン
 */
int main(int argc, char *argv[]) {
  int time = 180;                /* 標準では３分タイマー */

  if (argc>2) {
    fprintf(stderr, "Usage : %s [<second>]\n", argv[0]);
    exit(1);
  }

  if (argc==2) {
    time = atoi(argv[1]);
  }

  if (signal(SIGALRM, sigalarm)==SIG_ERR) {
    perror("signal1");
    exit(1);
  }

  if (signal(SIGINT, sigint)==SIG_ERR) {
    perror("signal2");
    exit(1);
  }

  almflag = FALSE;
  intflag = FALSE;

  /* 初期画面 */
  tprint(time);
  alarm(1);
  
  while(1) {
    /* シグナルが発生するまで待つ */
    pause();

    /* ^Cが押された */
    if (intflag) break;

    /* タイマー割込みが発生した */
    if (almflag) {
      time--;
      tprint(time);
      if (time==0) {
        fputs("\a\a\a",stderr);    /* ベルを鳴らす */
      }
      almflag = FALSE;
      alarm(1);
    }
  }

  /* 終了処理 */
  fputs("\033[2J\033[1;1H",stdout);  /* 画面クリア */
  return 0;
}
