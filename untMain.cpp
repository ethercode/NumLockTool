//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmNumLockTool*frmNumLockTool;
//---------------------------------------------------------------------------
__fastcall TfrmNumLockTool::TfrmNumLockTool(TComponent* Owner):
    TForm(Owner)
{
    Left = -1000;
    m_iBounceDir = -8;
    m_iAlpha = 255;

    m_fLastNum = 0 && GetKeyState(VK_NUMLOCK) != 0;
    m_fLastScr = GetKeyState(VK_SCROLL) != 0;
    m_fLastCap = GetKeyState(VK_CAPITAL) != 0;
}
//---------------------------------------------------------------------------


void __fastcall TfrmNumLockTool::tmrMainTimer(TObject* Sender)
{
    bool        fNumLock    = 0 && GetKeyState(VK_NUMLOCK) != 0;
    bool        fScrLock    = GetKeyState(VK_SCROLL) != 0;
    bool        fCapLock    = GetKeyState(VK_CAPITAL) != 0;

    int         iTotal      = 0;
    AnsiString  strString   = "";

    if (fNumLock)
    {
        ++iTotal;
        strString += " NUM ";
    }

    if (fCapLock)
    {
        if (fNumLock)
        {
            strString += " ";
        }
        ++iTotal;
        strString += " CAP ";
    }

    if (fScrLock)
    {
        if (fCapLock || fNumLock)
        {
            strString += " ";
        }
        ++iTotal;
        strString += " SCR ";
    }

    if (iTotal)
    {
        Application->ShowMainForm = true;
        ShowWindow(Handle, SW_SHOWNOACTIVATE);
        lblString->Caption = strString;
        POINT   pntMouse;
        GetCursorPos(&pntMouse);
        int iLeft   = pntMouse.x - Width;
        int iTop    = pntMouse.y - Height;
        ShowWindow(Application->Handle, SW_HIDE);
        SetWindowPos(Handle, HWND_TOPMOST, iLeft, iTop, 0, 0, SWP_NOSIZE | SWP_NOACTIVATE);
        ShowWindow(Handle, SW_SHOWNOACTIVATE);
    }
    else
    {
        Application->ShowMainForm = false;
        ShowWindow(Application->Handle, SW_HIDE);
        ShowWindow(Handle, SW_HIDE);
    }


    bool    fVisible        = (iTotal > 0);
    bool    fLastVisible    = m_fLastNum | m_fLastCap | m_fLastScr;

    if (fVisible && !fLastVisible)
    {
        m_iBounceDir = 8;
        m_iAlpha = 255;
    }

    if (!fVisible && fLastVisible)
    {
        m_iBounceDir = 0;
        m_iAlpha = 0;
    }

    m_fLastNum = fNumLock;
    m_fLastScr = fScrLock;
    m_fLastCap = fCapLock;

    if (m_iBounceDir)
    {
        AlphaBlendValue = m_iAlpha;
        m_iAlpha += m_iBounceDir;

        if (m_iBounceDir > 0)
        {
            if (m_iAlpha > 224)
            {
                m_iAlpha = 224;
                m_iBounceDir *= -1;
            }
        }
        else
        {
            if (m_iAlpha < 32)
            {
                m_iAlpha = 32;
                m_iBounceDir *= -1;
            }
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmNumLockTool::FormCreate(TObject* Sender)
{
    Caption = "NumLockToolWin";
    HWND    h   = FindWindow("TfrmNumLockTool", "NumLockTool");
    if (h != NULL && h != Handle)
    {
        Application->Terminate();
    }
}
//---------------------------------------------------------------------------

