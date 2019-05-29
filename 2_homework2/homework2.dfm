object Form1: TForm1
  Left = 208
  Top = 116
  Caption = 'Form1'
  ClientHeight = 250
  ClientWidth = 517
  Color = clBtnFace
  Font.Charset = SHIFTJIS_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Arial'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    517
    250)
  PixelsPerInch = 96
  TextHeight = 12
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 522
    Height = 217
    Hint = #12513#12514
    Anchors = [akLeft, akTop, akRight, akBottom]
    ParentShowHint = False
    PopupMenu = PopupMenu1
    ShowHint = True
    TabOrder = 0
    ExplicitWidth = 515
    ExplicitHeight = 185
  end
  object ForButton: TButton
    Left = 8
    Top = 223
    Width = 79
    Height = 25
    Hint = #20061#20061
    Anchors = [akLeft, akBottom]
    Caption = '&for'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = ForButtonClick
  end
  object WhileButton: TButton
    Left = 91
    Top = 223
    Width = 77
    Height = 25
    Hint = #20061#20061
    Anchors = [akBottom]
    Caption = '&while'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
    OnClick = WhileButtonClick
    ExplicitLeft = 92
  end
  object ClearButton: TButton
    Left = 174
    Top = 223
    Width = 77
    Height = 25
    Hint = #12513#12514#28040#21435
    Action = clear
    Anchors = [akBottom]
    ParentShowHint = False
    ShowHint = True
    TabOrder = 3
    ExplicitLeft = 171
    ExplicitTop = 191
  end
  object SaveButton: TButton
    Left = 256
    Top = 223
    Width = 77
    Height = 25
    Hint = #12513#12514#12434#20445#23384
    Action = save
    Anchors = [akBottom]
    ParentShowHint = False
    ShowHint = True
    TabOrder = 4
    ExplicitLeft = 258
  end
  object LoadButton: TButton
    Left = 339
    Top = 223
    Width = 77
    Height = 25
    Hint = #12513#12514#12434#35501#12415#36796#12416
    Action = load
    Anchors = [akBottom]
    ParentShowHint = False
    ShowHint = True
    TabOrder = 5
    ExplicitLeft = 341
  end
  object BitBtn: TBitBtn
    Left = 421
    Top = 223
    Width = 87
    Height = 25
    Hint = #32066#20102#12375#12414#12377#12290
    Anchors = [akRight, akBottom]
    Kind = bkClose
    NumGlyphs = 2
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    ExplicitLeft = 424
  end
  object PopupMenu1: TPopupMenu
    Left = 176
    Top = 80
    object Save1: TMenuItem
      Action = save
      Caption = #20445#23384'(&S)'
      Hint = #12513#12514#12398#20445#23384
      ShortCut = 16467
    end
    object Load1: TMenuItem
      Action = load
      Caption = #35501#12415#36796#12415'(&L)'
      Hint = #12486#12461#12473#12488#12398#35501#12415#36796#12415
      ShortCut = 16460
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Copy1: TMenuItem
      Action = EditCopy1
    end
    object Cut1: TMenuItem
      Action = EditCut1
    end
    object Paste1: TMenuItem
      Action = EditPaste1
    end
    object Del2: TMenuItem
      Action = EditDelete1
      Hint = #12513#12514#12398#36984#25246#31684#22258#12398#21066#38500
    end
    object Del1: TMenuItem
      Action = clear
      Caption = #20840#28040#21435'(&Q)'
      Hint = #12513#12514#12434#20840#12390#28040#12377
      ShortCut = 16430
    end
    object N3: TMenuItem
      Caption = '-'
    end
    object End: TMenuItem
      Caption = #32066#20102'(&X)'
      Hint = #32066#20102
      ShortCut = 32883
      OnClick = EndClick
    end
  end
  object ActionList1: TActionList
    Left = 136
    Top = 80
    object save: TAction
      Caption = '&Save'
      OnExecute = saveExecute
    end
    object load: TAction
      Caption = '&Load'
      OnExecute = loadExecute
    end
    object clear: TAction
      Caption = 'clear(&Q)'
      OnExecute = clearExecute
    end
    object EditCopy1: TEditCopy
      Category = #32232#38598
      Caption = #12467#12500#12540'(&C)'
      Hint = #12467#12500#12540
      ImageIndex = 1
      ShortCut = 16451
    end
    object EditCut1: TEditCut
      Category = #32232#38598
      Caption = #20999#12426#21462#12426'(&T)'
      Hint = #20999#12426#21462#12426
      ImageIndex = 0
      ShortCut = 16472
    end
    object EditPaste1: TEditPaste
      Category = #32232#38598
      Caption = #36028#12426#20184#12369'(&P)'
      Hint = #36028#12426#20184#12369
      ImageIndex = 2
      ShortCut = 16470
    end
    object EditDelete1: TEditDelete
      Category = #32232#38598
      Caption = #21066#38500'(&D)'
      ImageIndex = 5
      ShortCut = 46
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'txt'
    Filter = #12486#12461#12473#12488#12501#12449#12452#12523'(*.txt)|*.txt|'#12377#12409#12390'(*.*)|*.*'
    InitialDir = 'C:\'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 224
    Top = 80
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = #12486#12461#12473#12488#12501#12449#12452#12523'(*.txt)|*.txt|'#12377#12409#12390'(*.*)|*.*'
    InitialDir = 'C:\'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 272
    Top = 80
  end
end
