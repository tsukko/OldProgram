object Form1: TForm1
  Left = 276
  Top = 114
  Anchors = []
  Caption = 'Plot Trigonometric Function'
  ClientHeight = 449
  ClientWidth = 705
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  DesignSize = (
    705
    449)
  PixelsPerInch = 96
  TextHeight = 12
  object PLabel: TLabel
    Left = 8
    Top = 251
    Width = 36
    Height = 12
    Caption = #28857#12398#25968
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object XLabel2: TLabel
    Left = 111
    Top = 276
    Width = 30
    Height = 12
    Caption = '< x < '
  end
  object XLabel: TLabel
    Left = 7
    Top = 276
    Width = 42
    Height = 12
    Caption = 'x'#12398#31684#22258
  end
  object XLabel3: TLabel
    Left = 7
    Top = 326
    Width = 6
    Height = 12
    Caption = 'x'
  end
  object YLabel: TLabel
    Left = 8
    Top = 300
    Width = 42
    Height = 12
    Caption = 'y'#12398#31684#22258
    OnClick = YLabelClick
  end
  object YLabel2: TLabel
    Left = 112
    Top = 300
    Width = 26
    Height = 12
    Caption = '< y <'
  end
  object YLabel3: TLabel
    Left = 8
    Top = 350
    Width = 6
    Height = 12
    Caption = 'y'
  end
  object dYLabel: TLabel
    Left = 8
    Top = 374
    Width = 12
    Height = 12
    Caption = 'dy'
  end
  object aLabel: TLabel
    Left = 72
    Top = 402
    Width = 12
    Height = 12
    Caption = 'a='
  end
  object bLabel: TLabel
    Left = 136
    Top = 402
    Width = 12
    Height = 12
    Caption = 'b='
  end
  object GraphButton: TButton
    Left = 0
    Top = 0
    Width = 97
    Height = 33
    Hint = #12368#12425#12405#12434#25551#12365#12414#12377#12290
    Caption = '&Graph'
    Default = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    TabStop = False
    OnClick = GraphButtonClick
  end
  object BitBtn1: TBitBtn
    Left = 104
    Top = 0
    Width = 89
    Height = 33
    Hint = #12362#12431#12426#12290
    Kind = bkClose
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
    TabStop = False
  end
  object FunctionRadioGroup: TRadioGroup
    Left = 2
    Top = 40
    Width = 191
    Height = 161
    Caption = 'Function'
    Columns = 2
    Items.Strings = (
      'sin(x)'
      'cos(x)'
      'tan(x)'
      'ax*sin(bx)'
      'sinh(x)'
      'cosh(x)'
      'tanh(x)')
    TabOrder = 0
    TabStop = True
    OnClick = FunctionRadioGroupClick
  end
  object SaveButton: TButton
    Left = 65
    Top = 421
    Width = 65
    Height = 26
    Hint = #12487#12540#12479#20445#23384
    Caption = '&Save'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    OnClick = SaveButtonClick
  end
  object OpenButton: TButton
    Left = 136
    Top = 421
    Width = 57
    Height = 26
    Hint = #12501#12449#12452#12523#38283#12367
    Caption = '&Open'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    OnClick = OpenButtonClick
  end
  object PEdit: TEdit
    Left = 72
    Top = 248
    Width = 65
    Height = 20
    Hint = #28857#12398#25968
    ImeMode = imClose
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnChange = PEditChange
  end
  object XMinEdit: TEdit
    Left = 56
    Top = 272
    Width = 50
    Height = 20
    Hint = 'x'#12398#26368#23567#20516
    ImeMode = imClose
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnChange = XMinEditChange
  end
  object XMaxEdit: TEdit
    Left = 143
    Top = 272
    Width = 50
    Height = 20
    Hint = 'x'#12398#26368#22823#20516
    ImeMode = imClose
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    OnChange = XMaxEditChange
  end
  object GraphChart: TChart
    Left = 200
    Top = 0
    Width = 513
    Height = 462
    BackWall.Brush.Style = bsClear
    BackWall.Color = -1
    BottomWall.Color = -1
    Gradient.Direction = gdBottomTop
    Gradient.EndColor = 15925228
    Gradient.Visible = True
    Legend.Font.Charset = ANSI_CHARSET
    Legend.Font.Name = 'Arial'
    Legend.Visible = False
    MarginBottom = 2
    MarginLeft = 2
    MarginRight = 2
    MarginTop = 2
    Title.Font.Charset = ANSI_CHARSET
    Title.Font.Name = 'Arial'
    Title.Text.Strings = (
      'Chart')
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Axis.Width = 1
    BottomAxis.Axis.Visible = False
    BottomAxis.ExactDateTime = False
    BottomAxis.Increment = 1.570000000000000000
    BottomAxis.LabelsFormat.Font.Charset = ANSI_CHARSET
    BottomAxis.LabelsFormat.Font.Name = 'Arial'
    BottomAxis.Maximum = 25.000000000000000000
    BottomAxis.Title.Caption = 'x'
    BottomAxis.Title.Font.Charset = ANSI_CHARSET
    BottomAxis.Title.Font.Height = -16
    BottomAxis.Title.Font.Name = 'Arial'
    DepthAxis.LabelsFormat.Font.Charset = ANSI_CHARSET
    DepthAxis.LabelsFormat.Font.Name = 'Arial'
    DepthAxis.Title.Font.Charset = ANSI_CHARSET
    DepthAxis.Title.Font.Name = 'Arial'
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Axis.Width = 1
    LeftAxis.Axis.Visible = False
    LeftAxis.Grid.Color = 12615808
    LeftAxis.Grid.Style = psDashDot
    LeftAxis.LabelsFormat.Font.Charset = ANSI_CHARSET
    LeftAxis.LabelsFormat.Font.Name = 'Arial'
    LeftAxis.Maximum = 701.000000000000000000
    LeftAxis.Minimum = 306.000000000000000000
    LeftAxis.Title.Caption = 'y'
    LeftAxis.Title.Font.Charset = ANSI_CHARSET
    LeftAxis.Title.Font.Height = -15
    LeftAxis.Title.Font.Name = 'Arial'
    RightAxis.Automatic = False
    RightAxis.AutomaticMaximum = False
    RightAxis.AutomaticMinimum = False
    RightAxis.Axis.Width = 1
    RightAxis.Axis.Visible = False
    RightAxis.LabelsFormat.Font.Charset = ANSI_CHARSET
    RightAxis.LabelsFormat.Font.Name = 'Arial'
    RightAxis.Maximum = 664.000000000000000000
    RightAxis.Minimum = 449.000000000000000000
    RightAxis.Ticks.Style = psDot
    RightAxis.Title.Caption = 'dy'
    RightAxis.Title.Font.Charset = ANSI_CHARSET
    RightAxis.Title.Font.Height = -15
    RightAxis.Title.Font.Name = 'Arial'
    TopAxis.Axis.Width = 1
    TopAxis.LabelsFormat.Font.Charset = ANSI_CHARSET
    TopAxis.LabelsFormat.Font.Name = 'Arial'
    TopAxis.Title.Font.Charset = ANSI_CHARSET
    TopAxis.Title.Font.Name = 'Arial'
    View3D = False
    View3DWalls = False
    Color = 15663080
    ParentShowHint = False
    PopupMenu = GPop
    ShowHint = True
    TabOrder = 8
    Anchors = [akLeft, akTop, akRight, akBottom]
    OnMouseMove = GraphChartMouseMove
    ExplicitHeight = 449
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TPointSeries
      HoverElement = [heCurrent]
      Marks.Font.Charset = ANSI_CHARSET
      Marks.Font.Name = 'Arial'
      Marks.Style = smsValue
      SeriesColor = clAqua
      ClickableLine = False
      Pointer.Brush.Color = clRed
      Pointer.Draw3D = False
      Pointer.HorizSize = 2
      Pointer.InflateMargins = True
      Pointer.Pen.Visible = False
      Pointer.Style = psCircle
      Pointer.VertSize = 2
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TPointSeries
      HoverElement = [heCurrent]
      Marks.Font.Charset = ANSI_CHARSET
      Marks.Font.Name = 'Arial'
      Marks.Style = smsValue
      Marks.Callout.Length = 8
      SeriesColor = clGreen
      VertAxis = aRightAxis
      ClickableLine = False
      Pointer.Brush.Color = 10485760
      Pointer.HorizSize = 1
      Pointer.InflateMargins = True
      Pointer.Pen.Visible = False
      Pointer.Style = psRectangle
      Pointer.VertSize = 1
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
  object YMinEdit: TEdit
    Left = 56
    Top = 296
    Width = 49
    Height = 20
    Hint = 'y'#12398#26368#23567#20516
    ImeMode = imClose
    ParentShowHint = False
    ShowHint = True
    TabOrder = 9
    OnChange = YMinEditChange
  end
  object YMaxEdit: TEdit
    Left = 144
    Top = 296
    Width = 49
    Height = 20
    Hint = 'y'#12398#26368#22823#20516
    ImeMode = imClose
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
    OnChange = YMaxEditChange
  end
  object RadioGroup1: TRadioGroup
    Left = 0
    Top = 208
    Width = 193
    Height = 33
    Caption = #24494#20998#65311
    Columns = 3
    Items.Strings = (
      'y'
      'y'#39
      #20001#26041)
    TabOrder = 11
    OnClick = RadioGroup1Click
  end
  object aEdit: TEdit
    Left = 88
    Top = 398
    Width = 41
    Height = 20
    ParentShowHint = False
    ShowHint = False
    TabOrder = 12
  end
  object bEdit: TEdit
    Left = 152
    Top = 398
    Width = 41
    Height = 20
    TabOrder = 13
  end
  object ChangeButton: TButton
    Left = 144
    Top = 248
    Width = 49
    Height = 17
    Hint = #20182#12398'Form'#35501#12415#36796#12415#28857#12398#25968#12434#22793#12360#12427
    Caption = '&Change'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 14
    OnClick = ChangeButtonClick
  end
  object SizeCheckBox: TCheckBox
    Left = 0
    Top = 400
    Width = 65
    Height = 17
    Hint = 'y'#36600#12398#26368#22823#26368#23567#12434#33258#21205#12395#21512#12431#12379#12427
    Caption = 'AutoSize'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 15
    OnClick = SizeCheckBoxClick
  end
  object xIncrementEdit: TEdit
    Left = 80
    Top = 322
    Width = 65
    Height = 20
    TabOrder = 20
  end
  object yIncrementEdit: TEdit
    Left = 80
    Top = 346
    Width = 65
    Height = 20
    TabOrder = 17
  end
  object dyIncrementEdit: TEdit
    Left = 80
    Top = 370
    Width = 65
    Height = 20
    TabOrder = 18
  end
  object Button1: TButton
    Left = 160
    Top = 336
    Width = 33
    Height = 41
    Caption = 'a'
    TabOrder = 19
    OnClick = Button1Click
  end
  object ClearButton: TButton
    Left = 0
    Top = 421
    Width = 60
    Height = 26
    Hint = #12464#12521#12501#12434#28040#12377
    Caption = 'Clear'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 16
    OnClick = ClearButtonClick
  end
  object GPop: TPopupMenu
    Left = 216
    Top = 40
    object GPopSaveI: TMenuItem
      Caption = #30011#20687#12434#20445#23384'(&S)'
      Hint = 'wmf'#12501#12449#12452#12523#12391#20445#23384#12375#12414#12377#12290
      OnClick = GPopSaveIClick
    end
    object GPopSaveD: TMenuItem
      Caption = #12487#12540#12479#12434#20445#23384'(&H)'
      Hint = 'x,y'#12398#20516#12434'dat'#12398#25313#24373#23376#12391#20445#23384#12375#12414#12377#12290
      OnClick = GPopSaveDClick
    end
    object GPopOpen: TMenuItem
      Caption = #12487#12540#12479#12434#38283#12367'(&O)'
      Hint = 'dat'#12501#12449#12452#12523#12434#38283#12365#12414#12377#12290
      OnClick = GPopOpenClick
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Exit: TMenuItem
      Caption = #32066#20102'(&X)'
      Hint = #12362#12431#12426#12290
      OnClick = ExitClick
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'dat'
    Filter = 'dat'#12501#12449#12452#12523'(*.dat)|*.dat|text'#12501#12449#12452#12523'(*.txt)|*.txt|'#12377#12409#12390'|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 216
    Top = 72
  end
  object SaveDialog1: TSaveDialog
    Filter = #12513#12479#12501#12449#12452#12523'(*.wmf)|*.wmf|'#12487#12540#12479#12501#12449#12452#12523'(*.dat)|*.dat|'#12377#12409#12390'|*.*'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 216
    Top = 104
  end
end
