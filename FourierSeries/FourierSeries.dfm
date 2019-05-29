object Form1: TForm1
  Left = 30
  Top = 177
  Caption = 'Fourier series'
  ClientHeight = 555
  ClientWidth = 952
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object Label1: TLabel
    Left = 11
    Top = 56
    Width = 24
    Height = 12
    Caption = #25391#24133
  end
  object Label2: TLabel
    Left = 11
    Top = 32
    Width = 50
    Height = 12
    Caption = 'frequency'
  end
  object Label3: TLabel
    Left = 16
    Top = 10
    Width = 45
    Height = 12
    Caption = 'a*sin(fx)'
  end
  object Label4: TLabel
    Left = 8
    Top = 80
    Width = 48
    Height = 12
    Caption = #21021#26399#20301#30456
  end
  object Label5: TLabel
    Left = 88
    Top = 10
    Width = 6
    Height = 12
    Caption = '1'
  end
  object Label6: TLabel
    Left = 144
    Top = 10
    Width = 6
    Height = 12
    Caption = '2'
  end
  object Label7: TLabel
    Left = 208
    Top = 10
    Width = 6
    Height = 12
    Caption = '3'
  end
  object Label8: TLabel
    Left = 272
    Top = 10
    Width = 6
    Height = 12
    Caption = '4'
  end
  object Label9: TLabel
    Left = 336
    Top = 10
    Width = 6
    Height = 12
    Caption = '5'
  end
  object Label10: TLabel
    Left = 400
    Top = 10
    Width = 6
    Height = 12
    Caption = '6'
  end
  object Label12: TLabel
    Left = 528
    Top = 10
    Width = 6
    Height = 12
    Caption = '8'
  end
  object Label11: TLabel
    Left = 464
    Top = 10
    Width = 6
    Height = 12
    Caption = '7'
  end
  object Label13: TLabel
    Left = 592
    Top = 10
    Width = 6
    Height = 12
    Caption = '9'
  end
  object Label14: TLabel
    Left = 656
    Top = 10
    Width = 12
    Height = 12
    Caption = '10'
  end
  object Label15: TLabel
    Left = 784
    Top = 10
    Width = 12
    Height = 12
    Caption = '12'
  end
  object Label16: TLabel
    Left = 720
    Top = 10
    Width = 12
    Height = 12
    Caption = '11'
  end
  object Label18: TLabel
    Left = 451
    Top = 107
    Width = 34
    Height = 12
    Caption = 'X max:'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 64
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    Ctl3D = True
    ParentBiDiMode = False
    ParentCtl3D = False
    TabOrder = 1
    Text = '0'
  end
  object Edit2: TEdit
    Left = 64
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 2
    Text = '0'
  end
  object Button1: TButton
    Left = 8
    Top = 104
    Width = 49
    Height = 18
    Caption = '&Draw'
    Default = True
    TabOrder = 45
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 767
    Top = 104
    Width = 57
    Height = 18
    Caption = '&Close'
    TabOrder = 47
    OnClick = Button2Click
  end
  object CheckBox1: TCheckBox
    Left = 99
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 0
    OnClick = CheckBox1Click
  end
  object Chart1: TChart
    Left = 8
    Top = 128
    Width = 937
    Height = 425
    BackWall.Brush.Style = bsClear
    Legend.Font.Charset = SHIFTJIS_CHARSET
    Legend.Font.Name = #65325#65331' '#65328#26126#26397
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    Title.AdjustFrame = False
    BottomAxis.Axis.Width = 1
    BottomAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
    BottomAxis.LabelsFormat.Font.Color = clWhite
    BottomAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
    BottomAxis.Title.Font.Charset = SHIFTJIS_CHARSET
    BottomAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
    DepthAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
    DepthAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
    DepthAxis.Title.Font.Charset = SHIFTJIS_CHARSET
    DepthAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
    LeftAxis.Axis.Width = 1
    LeftAxis.ExactDateTime = False
    LeftAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
    LeftAxis.LabelsFormat.Font.Color = clWhite
    LeftAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
    LeftAxis.Title.Font.Charset = SHIFTJIS_CHARSET
    LeftAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
    RightAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
    RightAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
    RightAxis.Title.Font.Charset = SHIFTJIS_CHARSET
    RightAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
    TopAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
    TopAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
    TopAxis.Title.Font.Charset = SHIFTJIS_CHARSET
    TopAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
    View3D = False
    View3DWalls = False
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = clWindowText
    TabOrder = 44
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TFastLineSeries
      HoverElement = []
      Legend.Visible = False
      Marks.Font.Charset = SHIFTJIS_CHARSET
      Marks.Font.Name = #65325#65331' '#65328#26126#26397
      SeriesColor = clWhite
      ShowInLegend = False
      LinePen.Color = clWhite
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TFastLineSeries
      HoverElement = []
      Legend.Visible = False
      Marks.Font.Charset = SHIFTJIS_CHARSET
      Marks.Font.Name = #65325#65331' '#65328#26126#26397
      SeriesColor = clRed
      ShowInLegend = False
      LinePen.Color = clRed
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series3: TFastLineSeries
      HoverElement = []
      Legend.Visible = False
      Marks.Font.Charset = SHIFTJIS_CHARSET
      Marks.Font.Name = #65325#65331' '#65328#26126#26397
      SeriesColor = clGreen
      ShowInLegend = False
      LinePen.Color = clGreen
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object Edit3: TEdit
    Tag = 2
    Left = 64
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 3
    Text = '0'
  end
  object Edit4: TEdit
    Left = 128
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 5
    Text = '0'
  end
  object Edit5: TEdit
    Left = 128
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 6
    Text = '0'
  end
  object CheckBox2: TCheckBox
    Left = 160
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 4
    OnClick = CheckBox2Click
  end
  object Edit6: TEdit
    Left = 128
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 7
    Text = '0'
  end
  object Edit7: TEdit
    Left = 192
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 9
    Text = '0'
  end
  object Edit8: TEdit
    Left = 192
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 10
    Text = '0'
  end
  object CheckBox3: TCheckBox
    Left = 224
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 8
    OnClick = CheckBox3Click
  end
  object Edit9: TEdit
    Left = 192
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 11
    Text = '0'
  end
  object Edit10: TEdit
    Left = 256
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 13
    Text = '0'
  end
  object Edit11: TEdit
    Left = 256
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 14
    Text = '0'
  end
  object CheckBox4: TCheckBox
    Left = 288
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 12
    OnClick = CheckBox4Click
  end
  object Edit12: TEdit
    Left = 256
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 15
    Text = '0'
  end
  object Edit13: TEdit
    Left = 320
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 17
    Text = '0'
  end
  object Edit14: TEdit
    Left = 320
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 18
    Text = '0'
  end
  object CheckBox5: TCheckBox
    Left = 352
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 16
    OnClick = CheckBox5Click
  end
  object Edit15: TEdit
    Left = 320
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 19
    Text = '0'
  end
  object Edit16: TEdit
    Left = 384
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 21
    Text = '0'
  end
  object Edit17: TEdit
    Left = 384
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 22
    Text = '0'
  end
  object CheckBox6: TCheckBox
    Left = 416
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 20
    OnClick = CheckBox6Click
  end
  object Edit18: TEdit
    Left = 384
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 23
    Text = '0'
  end
  object Edit19: TEdit
    Left = 448
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 25
    Text = '0'
  end
  object Edit20: TEdit
    Left = 448
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 26
    Text = '0'
  end
  object CheckBox7: TCheckBox
    Left = 480
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 24
    OnClick = CheckBox7Click
  end
  object Edit21: TEdit
    Left = 448
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 27
    Text = '0'
  end
  object Edit22: TEdit
    Left = 512
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 29
    Text = '0'
  end
  object Edit23: TEdit
    Left = 512
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 30
    Text = '0'
  end
  object CheckBox8: TCheckBox
    Left = 544
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 28
    OnClick = CheckBox8Click
  end
  object Edit24: TEdit
    Left = 512
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 31
    Text = '0'
  end
  object Button3: TButton
    Left = 64
    Top = 104
    Width = 57
    Height = 18
    Caption = 'c&lear'
    TabOrder = 46
    OnClick = Button3Click
  end
  object Edit25: TEdit
    Left = 576
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 32
    Text = '0'
  end
  object Edit26: TEdit
    Left = 576
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 33
    Text = '0'
  end
  object Edit27: TEdit
    Left = 576
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 34
    Text = '0'
  end
  object Edit28: TEdit
    Left = 640
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 35
    Text = '0'
  end
  object Edit29: TEdit
    Left = 640
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 36
    Text = '0'
  end
  object Edit30: TEdit
    Left = 640
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 37
    Text = '0'
  end
  object Edit31: TEdit
    Left = 704
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 38
    Text = '0'
  end
  object Edit32: TEdit
    Left = 704
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 39
    Text = '0'
  end
  object Edit33: TEdit
    Left = 704
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 40
    Text = '0'
  end
  object Edit34: TEdit
    Left = 768
    Top = 32
    Width = 57
    Height = 20
    BiDiMode = bdRightToLeftNoAlign
    ParentBiDiMode = False
    TabOrder = 41
    Text = '0'
  end
  object Edit35: TEdit
    Left = 768
    Top = 56
    Width = 57
    Height = 20
    BiDiMode = bdLeftToRight
    ImeMode = imClose
    ParentBiDiMode = False
    TabOrder = 42
    Text = '0'
  end
  object Edit36: TEdit
    Left = 768
    Top = 80
    Width = 57
    Height = 20
    TabOrder = 43
    Text = '0'
  end
  object Button4: TButton
    Left = 128
    Top = 104
    Width = 57
    Height = 18
    Caption = '&All Check'
    TabOrder = 48
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 192
    Top = 104
    Width = 57
    Height = 18
    Caption = '&No Check'
    TabOrder = 49
    OnClick = Button5Click
  end
  object CheckBox9: TCheckBox
    Left = 608
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 50
    OnClick = CheckBox9Click
  end
  object CheckBox10: TCheckBox
    Left = 672
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 51
    OnClick = CheckBox10Click
  end
  object CheckBox11: TCheckBox
    Left = 736
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 52
    OnClick = CheckBox11Click
  end
  object CheckBox12: TCheckBox
    Left = 800
    Top = 8
    Width = 17
    Height = 17
    State = cbGrayed
    TabOrder = 53
    OnClick = CheckBox12Click
  end
  object CheckBox13: TCheckBox
    Left = 264
    Top = 104
    Width = 49
    Height = 17
    Caption = 'cos'
    TabOrder = 54
    OnClick = CheckBox13Click
  end
  object CheckBox14: TCheckBox
    Left = 319
    Top = 104
    Width = 123
    Height = 17
    Caption = #21152#31639#12391#12399#12394#12367#20055#31639
    TabOrder = 55
  end
  object Panel1: TPanel
    Left = 831
    Top = 6
    Width = 114
    Height = 116
    TabOrder = 56
    object Label17: TLabel
      Left = 3
      Top = 71
      Width = 77
      Height = 12
      Caption = #31890#24230' (max:100)'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #65325#65331' '#65328#12468#12471#12483#12463
      Font.Style = []
      ParentFont = False
    end
    object Button6: TButton
      Left = 0
      Top = -1
      Width = 89
      Height = 18
      Caption = 'Sawtooth Wave'
      TabOrder = 0
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 0
      Top = 23
      Width = 89
      Height = 18
      Caption = 'Square Wave'
      TabOrder = 1
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 0
      Top = 47
      Width = 89
      Height = 18
      Caption = 'Triangle Wave'
      TabOrder = 2
      OnClick = Button8Click
    end
    object Edit37: TEdit
      Left = 84
      Top = 68
      Width = 25
      Height = 20
      TabOrder = 3
      Text = '12'
    end
    object Button9: TButton
      Left = 46
      Top = 90
      Width = 49
      Height = 17
      Caption = 'Button9'
      TabOrder = 4
      OnClick = Button9Click
    end
    object Edit38: TEdit
      Left = 0
      Top = 89
      Width = 40
      Height = 20
      TabOrder = 5
      Text = '1.1'
    end
  end
  object Edit39: TEdit
    Left = 491
    Top = 102
    Width = 49
    Height = 20
    TabOrder = 57
    Text = '4'
  end
end
