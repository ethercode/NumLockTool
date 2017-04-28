//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("untMain.cpp", frmNumLockTool);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    bool    MayRun  = true;
    HWND    w       = FindWindow(0, "NumLockToolWin");
    if (w)
    {
        DWORD   dwMyPID = GetCurrentProcessId();
        DWORD   dwOtherPID;
        GetWindowThreadProcessId(w, &dwOtherPID);
        if (dwOtherPID != dwMyPID)
        {
            MayRun = false;
        }
    }
    if (!MayRun)
    {
        return 0;
    }

    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TfrmNumLockTool), &frmNumLockTool);
        Application->Run();
    }
    catch (Exception& exception)
    {
        Application->ShowException(&exception);
    }
    catch (...)
    {
        try
        {
            throw Exception("");
        }
        catch (Exception& exception)
        {
            Application->ShowException(&exception);
        }
    }
    return 0;
}
//---------------------------------------------------------------------------
