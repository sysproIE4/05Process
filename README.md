# プロセスとジョブ

課題5-1，2，3を行い操作手順と結果表示を
`kekka.txt`に貼り付けて（ターミナルからコピペして）提出する．

1. 課題の準備<br>
レポジトリをダウンロードし
実験用プログラム（3分タイマー）が実行できるようにする．
```
$ git clone https://....
$ cd 05Process
$ make
$ ./alarm             <---- 3分タイマープログラムが起動
タイマーの画面が表示される．
^C                    <---- Ctrl-Cで終了
画面をクリアして終了する．
$
```

2. 課題5-1

    - システム内の全プロセスの個数を調べなさい．
    - システム内の全ての自分のプロセスの個数を調べなさい．

3. 課題5-2<br>
上で準備した３分タイマープログラムを用いて以下を行いなさい．<br>
    - 「第１のターミナル」でタイマープログラムを起動します．<br>
    - 「第２のターミナル」を操作し以下のことをします．<br>
   （提出する操作手順・結果は「第２のターミナル」側だけで良い．）
  
    1. タイマープログラムのPIDとSTATを確認する．
    2. タイマープログラムを一時停止させる．
    3. タイマープログラムのSTATを確認する．<br>
     （上で確認した時と変化しているか？）
    4. タイマープログラムを再開させる．
    5. タイマープログラムを終了させる．<br>
      タイマープログラムは画面をクリアして終了したか？<br>
      クリアされていないようなら終了方法を考え直す．

4. 課題5-3<br>
タイマープログラムを起動したターミナルだけを用いて以下を行いなさい．<br>

    1. タイマープログラムを一時停止する．
    2. 一時停止したタイマープログラムを再開させる．
    3. タイマープログラムを終了させる．

以上

