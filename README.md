昔に作ったプログラムを置いておきます。

# 当時の開発環境
- 2003～2006年ごろ作成
- Windows XP
- Borland C++ Builder 6.0（BCB6）

※現在（2019年）は、C++ Builderは、エンバカデロ・テクノロジーズのものらしいです。  
Wikipediaでは、「Delphi」のC/C++版とも言えるRAD(Rapid Application Development)ツールと紹介されていました。

# アップにあたって行ったこと
- プロジェクトファイルの拡張子や内容が変わっている
  - BCB6:*.bpr
  - Embarcadero RAD Studio 10.3:*.cbproj  
  -> 対策：新しいC++ Builderで新規プロジェクトを作成して、必要コードを追記  

一部、GPIB (General Purpose Interface Bus) を使うプログラムが存在しております。  
それらはビルドするためにはdllやヘッダファイルが必要だったりするため、確認していないです。
