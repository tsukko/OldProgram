object Form1: TForm1
  Left = 243
  Top = 55
  Caption = #25269#25239#28204#23450#12398#12390#12377#12392#12290#12392#12426#12354#12360#12378#35336#28204#22120#12398#38651#28304#20837#12428#12392#12363#12428#12290
  ClientHeight = 469
  ClientWidth = 455
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
  object OpenBotton: TButton
    Left = 248
    Top = 8
    Width = 65
    Height = 41
    Caption = 'open'
    TabOrder = 0
    OnClick = OpenBottonClick
  end
  object BitBtn1: TBitBtn
    Left = 320
    Top = 8
    Width = 105
    Height = 41
    Kind = bkClose
    NumGlyphs = 2
    TabOrder = 1
  end
  object Panel1: TPanel
    Left = 0
    Top = 56
    Width = 457
    Height = 409
    TabOrder = 2
    object Label1: TLabel
      Left = 112
      Top = 56
      Width = 27
      Height = 12
      Caption = 'Volt+'
    end
    object Label2: TLabel
      Left = 216
      Top = 56
      Width = 27
      Height = 12
      Caption = 'Volt-'
    end
    object Label3: TLabel
      Left = 328
      Top = 56
      Width = 57
      Height = 12
      Caption = 'Resistance'
    end
    object Ch1Button: TButton
      Left = 16
      Top = 72
      Width = 49
      Height = 25
      Caption = 'ch&1'
      TabOrder = 0
      OnClick = Ch1ButtonClick
    end
    object Ch2Button: TButton
      Left = 16
      Top = 104
      Width = 49
      Height = 25
      Caption = 'ch&2'
      TabOrder = 1
      OnClick = Ch2ButtonClick
    end
    object Ch3Button: TButton
      Left = 16
      Top = 136
      Width = 49
      Height = 25
      Caption = 'ch&3'
      TabOrder = 2
      OnClick = Ch3ButtonClick
    end
    object Ch4Button: TButton
      Left = 16
      Top = 168
      Width = 49
      Height = 25
      Caption = 'ch&4'
      TabOrder = 3
      OnClick = Ch4ButtonClick
    end
    object Ch5Button: TButton
      Left = 16
      Top = 200
      Width = 49
      Height = 25
      Caption = 'ch&5'
      TabOrder = 4
      OnClick = Ch5ButtonClick
    end
    object Ch1VoltpEdit: TEdit
      Left = 72
      Top = 74
      Width = 105
      Height = 20
      TabOrder = 5
    end
    object Ch2VoltpEdit: TEdit
      Left = 72
      Top = 106
      Width = 105
      Height = 20
      TabOrder = 6
    end
    object Ch3VoltpEdit: TEdit
      Left = 72
      Top = 138
      Width = 105
      Height = 20
      TabOrder = 7
    end
    object Ch4VoltpEdit: TEdit
      Left = 72
      Top = 170
      Width = 105
      Height = 20
      TabOrder = 8
    end
    object ComboBox1: TComboBox
      Left = 16
      Top = 48
      Width = 81
      Height = 20
      TabOrder = 9
      Text = 'ComboBox1'
      OnChange = ComboBox1Change
      Items.Strings = (
        #65297'E-3'
        #65297'E-4'
        #65297'E-5'
        #65297'E-6')
    end
    object Ch5VoltpEdit: TEdit
      Left = 72
      Top = 202
      Width = 105
      Height = 20
      TabOrder = 10
    end
    object CheckBox1: TCheckBox
      Left = 232
      Top = 232
      Width = 57
      Height = 17
      Caption = #28201#24230#35336
      TabOrder = 11
      OnClick = CheckBox1Click
    end
    object TemperatureEdit: TEdit
      Left = 304
      Top = 232
      Width = 105
      Height = 20
      TabOrder = 12
      Text = 'Temperature'
    end
    object Ch1VoltnEdit: TEdit
      Left = 184
      Top = 74
      Width = 105
      Height = 20
      TabOrder = 13
    end
    object Ch2VoltnEdit: TEdit
      Left = 184
      Top = 106
      Width = 105
      Height = 20
      TabOrder = 14
    end
    object Ch3VoltnEdit: TEdit
      Left = 184
      Top = 138
      Width = 105
      Height = 20
      TabOrder = 15
    end
    object Ch4VoltnEdit: TEdit
      Left = 184
      Top = 170
      Width = 105
      Height = 20
      TabOrder = 16
    end
    object Ch5VoltnEdit: TEdit
      Left = 184
      Top = 202
      Width = 105
      Height = 20
      TabOrder = 17
    end
    object Ch5ResistanceEdit: TEdit
      Left = 304
      Top = 202
      Width = 105
      Height = 20
      TabOrder = 18
    end
    object Ch4ResistanceEdit: TEdit
      Left = 304
      Top = 170
      Width = 105
      Height = 20
      TabOrder = 19
    end
    object Ch3ResistanceEdit: TEdit
      Left = 304
      Top = 138
      Width = 105
      Height = 20
      TabOrder = 20
    end
    object Ch2ResistanceEdit: TEdit
      Left = 304
      Top = 106
      Width = 105
      Height = 20
      TabOrder = 21
    end
    object Ch1ResistanceEdit: TEdit
      Left = 304
      Top = 74
      Width = 105
      Height = 20
      TabOrder = 22
    end
    object Panel2: TPanel
      Left = 8
      Top = 256
      Width = 401
      Height = 81
      TabOrder = 23
      object CloseChButton: TButton
        Left = 312
        Top = 40
        Width = 65
        Height = 33
        Caption = 'Close Ch'
        TabOrder = 0
        OnClick = CloseChButtonClick
      end
      object OpenAllButton: TButton
        Left = 232
        Top = 40
        Width = 73
        Height = 33
        Caption = '&OpenAll'
        TabOrder = 1
        OnClick = OpenAllButtonClick
      end
      object GroupBox1: TGroupBox
        Left = 8
        Top = 32
        Width = 217
        Height = 41
        Caption = 'GroupBox1'
        TabOrder = 2
        object RadioButton1: TRadioButton
          Left = 8
          Top = 16
          Width = 41
          Height = 17
          Caption = 'ch1'
          TabOrder = 0
        end
        object RadioButton2: TRadioButton
          Left = 48
          Top = 16
          Width = 41
          Height = 17
          Caption = 'ch2'
          TabOrder = 1
        end
        object RadioButton3: TRadioButton
          Left = 88
          Top = 16
          Width = 41
          Height = 17
          Caption = 'ch3'
          TabOrder = 2
        end
        object RadioButton4: TRadioButton
          Left = 128
          Top = 16
          Width = 41
          Height = 17
          Caption = 'ch4'
          TabOrder = 3
        end
        object RadioButton5: TRadioButton
          Left = 168
          Top = 16
          Width = 41
          Height = 17
          Caption = 'ch5'
          TabOrder = 4
        end
      end
      object ReverseCheckBox: TCheckBox
        Left = 224
        Top = 8
        Width = 57
        Height = 17
        Caption = #21453#36578'(&R)'
        TabOrder = 3
        OnClick = ReverseCheckBoxClick
      end
      object CurrentCheckBox: TCheckBox
        Left = 128
        Top = 8
        Width = 81
        Height = 17
        Caption = 'CurrentOn'
        TabOrder = 4
        OnClick = CurrentCheckBoxClick
      end
      object DisplayVoltButton: TButton
        Left = 302
        Top = 8
        Width = 75
        Height = 25
        Caption = 'DisplayVolt'
        TabOrder = 5
        OnClick = DisplayVoltButtonClick
      end
    end
  end
  object SelectTemperatureChRadioGroup: TRadioGroup
    Left = 8
    Top = 8
    Width = 233
    Height = 41
    Caption = #28201#24230#35336#65288#12481#12455#12483#12463#12375#12394#12356#12392#12458#12540#12503#12531#12373#12379#12394#12356#65289
    Columns = 5
    Items.Strings = (
      'Ch1'
      'Ch2'
      'Ch3'
      'Ch4'
      'Ch5')
    TabOrder = 3
    OnClick = SelectTemperatureChRadioGroupClick
  end
end
