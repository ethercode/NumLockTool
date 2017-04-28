object frmNumLockTool: TfrmNumLockTool
  Left = 192
  Top = 107
  AlphaBlend = True
  AutoSize = True
  BorderIcons = []
  BorderStyle = bsNone
  ClientHeight = 16
  ClientWidth = 104
  Color = clBlack
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object lblString: TLabel
    Left = 0
    Top = 0
    Width = 88
    Height = 16
    Caption = 'NUM CAP SCR'
    Font.Charset = ANSI_CHARSET
    Font.Color = clLime
    Font.Height = -13
    Font.Name = 'Courier New'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object tmrMain: TTimer
    Interval = 10
    OnTimer = tmrMainTimer
  end
end
