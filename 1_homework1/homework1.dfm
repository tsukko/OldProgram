object Form1: TForm1
  Left = 203
  Top = 121
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 319
  ClientWidth = 294
  Color = 16053450
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Latha'
  Font.Pitch = fpFixed
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  Visible = True
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 12
  object B1: TButton
    Left = 8
    Top = 0
    Width = 113
    Height = 25
    Caption = 'Button(&B)'
    TabOrder = 1
    TabStop = False
    OnClick = B1Click
  end
  object BitBtn1: TBitBtn
    Left = 136
    Top = 0
    Width = 145
    Height = 25
    Hint = #32066#20102#12375#12414#12377#12290
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Latha'
    Font.Pitch = fpFixed
    Font.Style = []
    Kind = bkClose
    NumGlyphs = 2
    ParentFont = False
    TabOrder = 0
    OnClick = BitBtn1Click
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 32
    Width = 289
    Height = 81
    Caption = 'Calculation'
    TabOrder = 2
    object Label1: TLabel
      Left = 69
      Top = 18
      Width = 9
      Height = 16
      AutoSize = False
      Caption = 'OP'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Latha'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 144
      Top = 18
      Width = 9
      Height = 17
      Caption = '='
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -17
      Font.Name = 'Latha'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 8
      Top = 16
      Width = 57
      Height = 20
      ImeMode = imClose
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 80
      Top = 16
      Width = 57
      Height = 20
      ImeMode = imClose
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 160
      Top = 16
      Width = 57
      Height = 20
      TabStop = False
      TabOrder = 3
    end
    object Button1: TButton
      Left = 224
      Top = 32
      Width = 57
      Height = 25
      Caption = #35336#31639'(&E)'
      TabOrder = 2
      OnClick = Button1Click
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 40
      Width = 209
      Height = 33
      Caption = 'select'
      Columns = 4
      Items.Strings = (
        '+ (&a)'
        '- (&f)'
        '* (&m)'
        '/ (&w)')
      TabOrder = 4
      OnClick = RadioGroup1Click
    end
  end
  object GroupBox2: TGroupBox
    Left = 0
    Top = 120
    Width = 289
    Height = 81
    Caption = 'Sort'
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Latha'
    Font.Pitch = fpFixed
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    object Label3: TLabel
      Left = 56
      Top = 16
      Width = 8
      Height = 16
      Caption = '>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Latha'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 112
      Top = 16
      Width = 8
      Height = 16
      Caption = '>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Latha'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 168
      Top = 16
      Width = 8
      Height = 16
      Caption = '>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Latha'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 224
      Top = 16
      Width = 8
      Height = 16
      Caption = '>'
      Font.Charset = SHIFTJIS_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Latha'
      Font.Pitch = fpFixed
      Font.Style = []
      ParentFont = False
    end
    object Edit4: TEdit
      Left = 8
      Top = 16
      Width = 49
      Height = 20
      ImeMode = imClose
      TabOrder = 0
    end
    object Edit5: TEdit
      Left = 64
      Top = 16
      Width = 49
      Height = 20
      ImeMode = imClose
      TabOrder = 1
    end
    object Edit6: TEdit
      Left = 120
      Top = 16
      Width = 49
      Height = 20
      ImeMode = imClose
      TabOrder = 2
    end
    object Edit7: TEdit
      Left = 176
      Top = 16
      Width = 49
      Height = 20
      ImeMode = imClose
      TabOrder = 3
    end
    object Edit8: TEdit
      Left = 232
      Top = 16
      Width = 49
      Height = 20
      ImeMode = imClose
      TabOrder = 4
    end
    object RadioGroup2: TRadioGroup
      Left = 24
      Top = 40
      Width = 145
      Height = 33
      Caption = 'select'
      Columns = 2
      Items.Strings = (
        #26119#38918' (&u)'
        #38477#38918' (&d)')
      TabOrder = 6
      OnClick = RadioGroup2Click
    end
    object Button2: TButton
      Left = 184
      Top = 45
      Width = 65
      Height = 25
      Caption = '&Sort(&S)'
      Default = True
      TabOrder = 5
      OnClick = Button2Click
    end
  end
  object GroupBox4: TGroupBox
    Left = 0
    Top = 208
    Width = 289
    Height = 105
    Caption = 'Sort2 '#12459#12531#12510#21306#20999#12426#12391#20195#20837#12375#12390
    Font.Charset = SHIFTJIS_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Latha'
    Font.Pitch = fpFixed
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    object B2: TButton
      Left = 184
      Top = 70
      Width = 65
      Height = 25
      Caption = 'Sort2(&z)'
      Default = True
      Enabled = False
      TabOrder = 0
      OnClick = B2Click
    end
    object E2: TEdit
      Left = 8
      Top = 40
      Width = 273
      Height = 20
      TabOrder = 1
    end
    object RadioGroup3: TRadioGroup
      Left = 24
      Top = 64
      Width = 145
      Height = 33
      Caption = 'select'
      Columns = 2
      Items.Strings = (
        #26119#38918' (&x)'
        #38477#38918' (&y)')
      TabOrder = 2
    end
    object E1: TEdit
      Left = 8
      Top = 16
      Width = 273
      Height = 20
      ImeMode = imClose
      TabOrder = 3
      OnChange = E1Change
    end
  end
end
