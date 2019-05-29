.LOG

041203、試運転。ver1.0
常にch5を測定している状態なので、結構重い。
CheckBoxとかで測定する条件を温度にするか時間にするか。

headerの電圧値よむ命令文"measure:volt:dc?"を":READ?"に変更
V-Limitについて
   V1 から V3 (上限3V)に変更。温度計の電圧値が1.6V以上になるので
measure,upについて
   upからでも始めれるようにした。

測定する温度の条件について
   温度最低で3k、最高で280kとか。それ以外にいったら測定終わる。
   down：300Kから100Kまで1K刻み、100～50Kまで0.5K刻み、50K以下0.1K刻みとかに
   したほうがよいのではと思う。上の50Kのところユーザが指定できるように？
   測定自動に終わる温度も指定
   up：上同様、
      測定するコマンドを関数にまとめる


17:11 2004/12/25

ver1.1
修正点
121行目に測定のプログラムを関数としてまとめた
   if(Lasttemperature-TemperatureX>=TemR){
143行目
      Lasttemperature=TemperatureX;
16行目
   #include <stdlib.h>      //絶対値abs()を使うだけのためにある
の削除。abs()は値を整数で返すことがわかった

38行目
   float FTem,Tem,TemR1,TemR2,Lasttemperature;
421行目のButton1Clickも変更


15:57 2005/06/01

ver1.2
任意のチャンネルを温度計に設定できるようにした。
チャンネルを表わすn 、そのcomboBoxのItemIndexの変数i[n]をグローバル変数じゃないようにした。　
電流値も任意に、せめて選択数を増やせるようにしたい。
