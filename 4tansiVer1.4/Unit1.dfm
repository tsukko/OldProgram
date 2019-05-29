object Form1: TForm1
  Left = 149
  Top = 44
  BorderStyle = bsToolWindow
  Caption = 'measure-ver1.4(060308)'
  ClientHeight = 521
  ClientWidth = 803
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
  object Panel1: TPanel
    Left = 0
    Top = 43
    Width = 801
    Height = 457
    Caption = 'Panel1'
    TabOrder = 1
    object Label16: TLabel
      Left = 648
      Top = 40
      Width = 7
      Height = 12
      Caption = 'T'
    end
    object Label17: TLabel
      Left = 496
      Top = 40
      Width = 8
      Height = 12
      Caption = 'R'
    end
    object Label18: TLabel
      Left = 560
      Top = 40
      Width = 23
      Height = 12
      Caption = '*10^'
    end
    object MeasureChart: TChart
      Left = 8
      Top = 8
      Width = 481
      Height = 441
      BackWall.Brush.Style = bsClear
      BackWall.Color = clWhite
      Gradient.Direction = gdBottomTop
      Gradient.EndColor = 11927477
      Gradient.Visible = True
      Legend.Alignment = laTop
      Legend.Font.Charset = SHIFTJIS_CHARSET
      Legend.Font.Name = #65325#65331' '#65328#26126#26397
      Legend.LegendStyle = lsSeries
      Legend.TopPos = 0
      MarginBottom = 3
      MarginLeft = 2
      MarginTop = 3
      Title.Text.Strings = (
        'TChart')
      Title.Visible = False
      BottomAxis.Automatic = False
      BottomAxis.AutomaticMaximum = False
      BottomAxis.AutomaticMinimum = False
      BottomAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
      BottomAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
      BottomAxis.Maximum = 300.000000000000000000
      BottomAxis.Title.Caption = 'temperature  [K]'
      BottomAxis.Title.Font.Charset = SHIFTJIS_CHARSET
      BottomAxis.Title.Font.Height = -13
      BottomAxis.Title.Font.Name = 'Terminal'
      DepthAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
      DepthAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
      DepthAxis.Title.Font.Charset = SHIFTJIS_CHARSET
      DepthAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
      LeftAxis.Automatic = False
      LeftAxis.AutomaticMaximum = False
      LeftAxis.AutomaticMinimum = False
      LeftAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
      LeftAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
      LeftAxis.Maximum = 425.000000000000000000
      LeftAxis.Title.Caption = 'resistance  ['#937']'
      LeftAxis.Title.Font.Charset = SHIFTJIS_CHARSET
      LeftAxis.Title.Font.Height = -13
      LeftAxis.Title.Font.Name = 'Terminal'
      RightAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
      RightAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
      RightAxis.Title.Font.Charset = SHIFTJIS_CHARSET
      RightAxis.Title.Font.Name = #65325#65331' '#65328#26126#26397
      TopAxis.LabelsFormat.Font.Charset = SHIFTJIS_CHARSET
      TopAxis.LabelsFormat.Font.Name = #65325#65331' '#65328#26126#26397
      TopAxis.Title.Font.Charset = ANSI_CHARSET
      TopAxis.Title.Font.Name = 'Tahoma'
      View3D = False
      View3DWalls = False
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Color = clWhite
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnMouseDown = MeasureChartMouseDown
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object TemLabel: TLabel
        Left = 352
        Top = 24
        Width = 24
        Height = 12
        Caption = #28201#24230
      end
      object PLabel: TLabel
        Left = 352
        Top = 8
        Width = 24
        Height = 12
        Caption = #28857#25968
      end
      object TemperatureLabel: TLabel
        Left = 384
        Top = 24
        Width = 91
        Height = 12
        Caption = 'TemperatureLabel'
      end
      object PointLabel: TLabel
        Left = 384
        Top = 8
        Width = 53
        Height = 12
        Caption = 'PointLabel'
      end
      object Series1: TPointSeries
        HoverElement = [heCurrent]
        Marks.Font.Charset = SHIFTJIS_CHARSET
        Marks.Font.Name = #65325#65331' '#65328#26126#26397
        Marks.Callout.Length = 8
        SeriesColor = clRed
        Title = '1ch'
        ClickableLine = False
        Pointer.Brush.Color = clRed
        Pointer.InflateMargins = True
        Pointer.Pen.Visible = False
        Pointer.Style = psCircle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series2: TPointSeries
        HoverElement = [heCurrent]
        Marks.Font.Charset = SHIFTJIS_CHARSET
        Marks.Font.Name = #65325#65331' '#65328#26126#26397
        Marks.Callout.Length = 8
        SeriesColor = clGreen
        Title = '2ch'
        ClickableLine = False
        Pointer.Brush.Color = clGreen
        Pointer.InflateMargins = True
        Pointer.Pen.Visible = False
        Pointer.Style = psCircle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series3: TPointSeries
        HoverElement = [heCurrent]
        Marks.Font.Charset = SHIFTJIS_CHARSET
        Marks.Font.Name = #65325#65331' '#65328#26126#26397
        Marks.Callout.Length = 8
        SeriesColor = 4227327
        Title = '3ch'
        ClickableLine = False
        Pointer.InflateMargins = True
        Pointer.Pen.Visible = False
        Pointer.Style = psCircle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series4: TPointSeries
        HoverElement = [heCurrent]
        Marks.Font.Charset = SHIFTJIS_CHARSET
        Marks.Font.Name = #65325#65331' '#65328#26126#26397
        Marks.Callout.Length = 8
        SeriesColor = clBlue
        Title = '4ch'
        ClickableLine = False
        Pointer.InflateMargins = True
        Pointer.Pen.Visible = False
        Pointer.Style = psCircle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
      object Series5: TPointSeries
        HoverElement = [heCurrent]
        Marks.Font.Charset = SHIFTJIS_CHARSET
        Marks.Font.Name = #65325#65331' '#65328#26126#26397
        Marks.Callout.Length = 8
        SeriesColor = clGray
        Title = '5ch'
        ClickableLine = False
        Pointer.Brush.Color = clGray
        Pointer.InflateMargins = True
        Pointer.Pen.Visible = False
        Pointer.Style = psCircle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
    object ConfigGroupBox: TGroupBox
      Left = 496
      Top = 96
      Width = 297
      Height = 353
      Hint = #28204#23450#20013#12399#22793#26356#12391#12365#12414#12379#12435
      Caption = 'configuration'
      ParentShowHint = False
      ShowHint = False
      TabOrder = 1
      object ChChoiceGroupBox: TGroupBox
        Left = 40
        Top = 16
        Width = 217
        Height = 41
        Hint = #12481#12455#12483#12463#12399#12378#12377#12392#12375#12383#12398#12481#12515#12531#12493#12523#12398#35373#23450#12418#12391#12365#12394#12356#12424#12358#12395#12375#12390#12427
        Caption = #28204#23450#12377#12427'ch'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        object CheckBox1: TCheckBox
          Left = 8
          Top = 16
          Width = 41
          Height = 17
          Caption = '1ch'
          Checked = True
          State = cbChecked
          TabOrder = 0
        end
        object CheckBox2: TCheckBox
          Left = 48
          Top = 16
          Width = 41
          Height = 17
          Caption = '2ch'
          Checked = True
          State = cbChecked
          TabOrder = 1
        end
        object CheckBox4: TCheckBox
          Left = 128
          Top = 16
          Width = 41
          Height = 17
          Caption = '4ch'
          Checked = True
          State = cbChecked
          TabOrder = 2
        end
        object CheckBox3: TCheckBox
          Left = 88
          Top = 16
          Width = 41
          Height = 17
          Caption = '3ch'
          Checked = True
          State = cbChecked
          TabOrder = 3
        end
        object CheckBox5: TCheckBox
          Left = 168
          Top = 16
          Width = 41
          Height = 17
          Caption = '5ch'
          Checked = True
          State = cbChecked
          TabOrder = 4
        end
      end
      object Ch1GroupBox: TGroupBox
        Left = 8
        Top = 64
        Width = 281
        Height = 57
        Caption = '1ch'
        TabOrder = 1
        object Label1: TLabel
          Left = 8
          Top = 16
          Width = 57
          Height = 12
          Caption = #12469#12531#12503#12523#21517
        end
        object Label2: TLabel
          Left = 168
          Top = 16
          Width = 52
          Height = 12
          Caption = #38651#27969#20516'[A]'
        end
        object Label19: TLabel
          Left = 240
          Top = 16
          Width = 36
          Height = 12
          Caption = #28201#24230#35336
        end
        object Label28: TLabel
          Left = 184
          Top = 36
          Width = 23
          Height = 12
          Caption = '*10^'
        end
        object Ch1SampleNameEdit: TEdit
          Left = 8
          Top = 32
          Width = 129
          Height = 20
          TabOrder = 0
        end
        object CurrentExponentComboBox1: TComboBox
          Left = 216
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 1
          Text = 'CurrentExponentComboBox1'
        end
        object CurrentMantissaEdit1: TEdit
          Left = 144
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 2
          Text = 'CurrentMantissaEdit1'
        end
      end
      object Ch2GroupBox: TGroupBox
        Left = 8
        Top = 120
        Width = 281
        Height = 57
        Caption = '2ch'
        TabOrder = 2
        object Label4: TLabel
          Left = 8
          Top = 16
          Width = 57
          Height = 12
          Caption = #12469#12531#12503#12523#21517
        end
        object Label5: TLabel
          Left = 168
          Top = 16
          Width = 52
          Height = 12
          Caption = #38651#27969#20516'[A]'
        end
        object Label20: TLabel
          Left = 240
          Top = 16
          Width = 36
          Height = 12
          Caption = #28201#24230#35336
        end
        object Label27: TLabel
          Left = 184
          Top = 36
          Width = 23
          Height = 12
          Caption = '*10^'
        end
        object Ch2SampleNameEdit: TEdit
          Left = 8
          Top = 32
          Width = 129
          Height = 20
          TabOrder = 0
        end
        object CurrentExponentComboBox2: TComboBox
          Left = 216
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 1
          Text = 'CurrentExponentComboBox2'
        end
        object CurrentMantissaEdit2: TEdit
          Left = 144
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 2
          Text = 'CurrentMantissaEdit2'
        end
      end
      object Ch3GroupBox: TGroupBox
        Left = 8
        Top = 176
        Width = 281
        Height = 57
        Caption = '3ch'
        TabOrder = 3
        object Label7: TLabel
          Left = 8
          Top = 16
          Width = 57
          Height = 12
          Caption = #12469#12531#12503#12523#21517
        end
        object Label8: TLabel
          Left = 168
          Top = 16
          Width = 52
          Height = 12
          Caption = #38651#27969#20516'[A]'
        end
        object Label21: TLabel
          Left = 240
          Top = 16
          Width = 36
          Height = 12
          Caption = #28201#24230#35336
        end
        object Label26: TLabel
          Left = 184
          Top = 36
          Width = 23
          Height = 12
          Caption = '*10^'
        end
        object Ch3SampleNameEdit: TEdit
          Left = 8
          Top = 32
          Width = 129
          Height = 20
          TabOrder = 0
        end
        object CurrentExponentComboBox3: TComboBox
          Left = 216
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 1
          Text = 'CurrentExponentComboBox3'
        end
        object CurrentMantissaEdit3: TEdit
          Left = 144
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 2
          Text = 'CurrentMantissaEdit3'
        end
      end
      object Ch4GroupBox: TGroupBox
        Left = 8
        Top = 232
        Width = 281
        Height = 57
        Caption = '4ch'
        TabOrder = 4
        object Label10: TLabel
          Left = 8
          Top = 16
          Width = 57
          Height = 12
          Caption = #12469#12531#12503#12523#21517
        end
        object Label11: TLabel
          Left = 168
          Top = 16
          Width = 52
          Height = 12
          Caption = #38651#27969#20516'[A]'
        end
        object Label22: TLabel
          Left = 240
          Top = 16
          Width = 36
          Height = 12
          Caption = #28201#24230#35336
        end
        object Label25: TLabel
          Left = 184
          Top = 36
          Width = 23
          Height = 12
          Caption = '*10^'
        end
        object Ch4SampleNameEdit: TEdit
          Left = 8
          Top = 32
          Width = 129
          Height = 20
          TabOrder = 0
        end
        object CurrentExponentComboBox4: TComboBox
          Left = 216
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 1
          Text = 'CurrentExponentComboBox4'
        end
        object CurrentMantissaEdit4: TEdit
          Left = 144
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 2
          Text = 'CurrentMantissaEdit4'
        end
      end
      object Ch5GroupBox: TGroupBox
        Left = 8
        Top = 288
        Width = 281
        Height = 57
        Caption = '5ch'
        TabOrder = 5
        object Label13: TLabel
          Left = 8
          Top = 16
          Width = 57
          Height = 12
          Caption = #12469#12531#12503#12523#21517
        end
        object Label14: TLabel
          Left = 168
          Top = 16
          Width = 52
          Height = 12
          Caption = #38651#27969#20516'[A]'
        end
        object Label23: TLabel
          Left = 240
          Top = 16
          Width = 36
          Height = 12
          Caption = #28201#24230#35336
        end
        object Label24: TLabel
          Left = 184
          Top = 36
          Width = 23
          Height = 12
          Caption = '*10^'
        end
        object Ch5SampleNameEdit: TEdit
          Left = 8
          Top = 32
          Width = 129
          Height = 20
          TabOrder = 0
          Text = 'Temperture'
        end
        object CurrentExponentComboBox5: TComboBox
          Left = 216
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 1
          Text = 'CurrentExponentComboBox5'
        end
        object CurrentMantissaEdit5: TEdit
          Left = 144
          Top = 32
          Width = 33
          Height = 20
          TabOrder = 2
          Text = 'CurrentMantissaEdit5'
        end
      end
      object RadioButton1: TRadioButton
        Left = 264
        Top = 96
        Width = 17
        Height = 17
        TabOrder = 6
        OnClick = RadioButton1Click
      end
      object RadioButton2: TRadioButton
        Left = 264
        Top = 152
        Width = 17
        Height = 17
        TabOrder = 7
        OnClick = RadioButton2Click
      end
      object RadioButton4: TRadioButton
        Left = 264
        Top = 264
        Width = 17
        Height = 17
        TabOrder = 8
        OnClick = RadioButton4Click
      end
      object RadioButton5: TRadioButton
        Left = 264
        Top = 320
        Width = 17
        Height = 17
        TabOrder = 9
        OnClick = RadioButton5Click
      end
      object RadioButton3: TRadioButton
        Left = 264
        Top = 208
        Width = 17
        Height = 17
        TabOrder = 10
        OnClick = RadioButton3Click
      end
    end
    object FileNameGroupBox: TGroupBox
      Left = 496
      Top = 56
      Width = 297
      Height = 41
      Caption = 'FileName'
      TabOrder = 2
      object FileNameEdit: TEdit
        Left = 8
        Top = 12
        Width = 217
        Height = 20
        Hint = #20445#23384#12377#12427#12501#12449#12452#12523#12398#12497#12473#12418#19968#32210#12395#34920#31034#12289#30452#25509#26360#12365#36796#12415#12418#12391#12365#12427
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        Text = 'FileNameEdit'
      end
      object FNChangeButton: TButton
        Left = 232
        Top = 14
        Width = 57
        Height = 17
        Hint = #20445#23384#22580#25152#12289#12501#12449#12452#12523#21517#12434#22793#26356#12377#12427
        Caption = 'C&hange?'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = FNChangeButtonClick
      end
    end
    object MeasureButton: TButton
      Left = 520
      Top = 8
      Width = 81
      Height = 25
      Hint = #28204#23450#38283#22987
      Caption = '&Down'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = MeasureButtonClick
    end
    object StopButton: TButton
      Left = 720
      Top = 8
      Width = 73
      Height = 25
      Hint = #28204#23450#20013#27490
      Caption = '&Stop'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = StopButtonClick
    end
    object UpButton: TButton
      Left = 608
      Top = 8
      Width = 81
      Height = 25
      Hint = #28201#24230#19978#26119#12377#12427#12392#12365#12398#12487#12540#12479#21462#12426#12414#12377
      Caption = '&Up'
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnClick = UpButtonClick
    end
    object ResistanceMantissaComboBox: TComboBox
      Left = 512
      Top = 36
      Width = 41
      Height = 20
      TabOrder = 6
      Text = 'ResistanceMantissaComboBox'
      OnChange = ResistanceMantissaComboBoxChange
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6'
        '7'
        '8'
        '9')
    end
    object ResistanceExponenComboBox: TComboBox
      Left = 592
      Top = 36
      Width = 41
      Height = 20
      TabOrder = 7
      Text = 'ResistanceExponenComboBox'
      OnChange = ResistanceExponenComboBoxChange
      Items.Strings = (
        '5'
        '4'
        '3'
        '2'
        '1'
        '0'
        '-1'
        '-2'
        '-3'
        '-4'
        '-5'
        '-6'
        '-7'
        '-8'
        '-9'
        '-10')
    end
    object TemperatureComboBox: TComboBox
      Left = 664
      Top = 36
      Width = 49
      Height = 20
      TabOrder = 8
      Text = 'TemperatureComboBox'
      OnChange = TemperatureComboBoxChange
      Items.Strings = (
        '10'
        '20'
        '30'
        '40'
        '50'
        '60'
        '70'
        '80'
        '100'
        '120'
        '140'
        '160'
        '180'
        '200'
        '250'
        '300')
    end
  end
  object BitBtn1: TBitBtn
    Left = 712
    Top = 8
    Width = 81
    Height = 25
    Hint = #32066#12431#12426
    Kind = bkClose
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
  end
  object BoardOpenButton: TButton
    Left = 8
    Top = 8
    Width = 81
    Height = 25
    Caption = '&Open'
    TabOrder = 2
    OnClick = BoardOpenButtonClick
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 502
    Width = 803
    Height = 19
    Panels = <
      item
        BiDiMode = bdRightToLeft
        ParentBiDiMode = False
        Text = #24231#27161
        Width = 500
      end
      item
        Text = #29366#24907
        Width = 120
      end
      item
        Text = #26178
        Width = 150
      end>
  end
  object ConditionGroupBox: TGroupBox
    Left = 104
    Top = 0
    Width = 585
    Height = 41
    Caption = #28204#23450#26465#20214
    TabOrder = 4
    object Label3: TLabel
      Left = 184
      Top = 20
      Width = 87
      Height = 12
      Caption = 'K '#12372#12392#28204#23450#12288#24460#12399
    end
    object Label6: TLabel
      Left = 408
      Top = 20
      Width = 107
      Height = 12
      Caption = #31186#12362#12365#12395#28201#24230#12481#12455#12483#12463
    end
    object Label9: TLabel
      Left = 40
      Top = 20
      Width = 33
      Height = 12
      Caption = 'K '#12363#12425
    end
    object Label12: TLabel
      Left = 112
      Top = 20
      Width = 33
      Height = 12
      Caption = 'K '#12414#12391
    end
    object Label15: TLabel
      Left = 312
      Top = 20
      Width = 69
      Height = 12
      Caption = 'K '#12372#12392#28204#23450#12288#12539
    end
    object TempRate1Edit: TEdit
      Left = 152
      Top = 16
      Width = 25
      Height = 20
      TabOrder = 0
      Text = '0.5'
    end
    object SecondRateEdit: TEdit
      Left = 384
      Top = 16
      Width = 17
      Height = 20
      TabOrder = 1
      Text = '4'
    end
    object ConditionButton: TButton
      Left = 520
      Top = 16
      Width = 53
      Height = 17
      Caption = #22793#26356
      TabOrder = 2
      OnClick = ConditionButtonClick
    end
    object FirstTempEdit: TEdit
      Left = 8
      Top = 16
      Width = 25
      Height = 20
      TabOrder = 3
      Text = '300'
    end
    object TempEdit: TEdit
      Left = 80
      Top = 16
      Width = 25
      Height = 20
      TabOrder = 4
      Text = '50'
    end
    object TempRate2Edit: TEdit
      Left = 280
      Top = 16
      Width = 25
      Height = 20
      TabOrder = 5
      Text = '0.2'
    end
  end
  object Timer1: TTimer
    Interval = 2000
    OnTimer = Timer1Timer
    Left = 112
    Top = 168
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.txt'
    Filter = 'txt'#12501#12449#12452#12523'(*.txt)|*.txt|'#20840#12390'(*.*)|*.*'
    InitialDir = 'C:\Documents and Settings\Sakata Lab\'#12487#12473#12463#12488#12483#12503'\GM_data'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 80
    Top = 168
  end
end
