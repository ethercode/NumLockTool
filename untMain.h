//---------------------------------------------------------------------------

#ifndef untMainH
#define untMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmNumLockTool:public TForm
{
__published:    // IDE-managed Components
    TTimer*                         tmrMain;
    TLabel*                         lblString;
    void __fastcall                 tmrMainTimer(TObject* Sender);
    void __fastcall                 FormCreate(TObject* Sender);
private:    // User declarations
public:     // User declarations
    __fastcall                      TfrmNumLockTool(TComponent* Owner);

    bool                            m_fLastNum;
    bool                            m_fLastCap;
    bool                            m_fLastScr;
    int                             m_iBounceDir;
    int                             m_iAlpha;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNumLockTool* frmNumLockTool;
//---------------------------------------------------------------------------
#endif
