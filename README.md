昔2003～2006年ごろに作ったプログラムを置いておきます。  
今見るとすごい駄コードですね。

# なぜ今更
今でこそ、KotlinやSwift、Pythonなどいろいろな言語を扱えるようになっていますが、その最初ってどんな感じだったかというのを思い出とともに残そうかと思いました。  
社会人になる前で、独学だったので、変数名が"a"とか"x"とかだったり、コピペコードを多用していたり、、、プログラムとしては参考にはならないと思います。  

何事も初心者な時期があり、小さなことの積み重ねが大事ですね。

# 当時の開発環境
- 2003～2006年ごろ作成
- Windows XP
- Borland C++ Builder 6.0（BCB6）
- Adobe Illustrator CS2（バージョン 12）
- Adobe Photoshop CS2 (9.0)

※現在（2019年）は、C++ Builderは、エンバカデロ・テクノロジーズのものらしいです。  
Wikipediaでは、「Delphi」のC/C++版とも言えるRAD(Rapid Application Development)ツールと紹介されていました。

# 各プログラムについて
- 1_homework1  
  sort機能や基本的なGUIパーツの扱いを練習したソフト
- 2_homework2  
  九九と平方根の計算を行うソフト
- 3_PlotTrigonometricFunction  
  Chart（グラフ）へ三角関数やその微分データをプロットしたりデータの保存・読込処理を行うソフト
- 4tansiVer1.4  
  GPIBというインタフェースを扱った計測器ソフト
- FourierSeries  
  フーリエ変換。矩形波、のこぎり波、三角波をプロットするソフト  
  院生の時に学生実験で説明する補助ツールとして作成
- GmSampleProgram  
  GPIBというインタフェースを扱うために作ったサンプルソフト
- gmFile  
  ファイル読込からのデータ整形ツール
- image_sample  
  illustratorで作成した分子図など

# C++プログラムのアップにあたって行ったこと
- プロジェクトファイルの拡張子や内容が変わっている
  - BCB6:*.bpr
  - Embarcadero RAD Studio 10.3:*.cbproj  
  -> 対策：新しいC++ Builderで新規プロジェクトを作成して、必要コードを追記  
- ビルドエラーとなった箇所の修正  
  AnsiString周りなど
- インデントの一部修正  
  すべては直しきれていないです

一部、GPIB (General Purpose Interface Bus) を使うプログラムが存在しております。  
それらはビルドするためにはdllやヘッダファイルが必要だったりする（おそらく有料）ため、確認していないです。
