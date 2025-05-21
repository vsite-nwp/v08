#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, LControl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)

	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::ClickAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::ClickDelete)

END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
    CDialog::OnInitDialog();
    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    LControl.SetView(LVS_REPORT);
    LControl.InsertColumn(0, _T("Name"), LVCFMT_CENTER, 100);
    LControl.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 50);
    LControl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

    return TRUE;
}

void MainDlg::ClickAdd()
{
    CString Name, Year;
    GetDlgItemText(IDC_EDIT1, Name);
    GetDlgItemText(IDC_EDIT2, Year);
    Name.Trim();
    Year.Trim();

    //Provjera godine (samo brojevi)
    bool isValidYear = true;
    for (int i = 0; i < Year.GetLength(); i++) 
    {
        if (!_istdigit(Year[i])) 
        {
            isValidYear = false;
            break;
        }
    }

    if (!Name.IsEmpty() && !Year.IsEmpty() && isValidYear) 
    {
        const int elementAtIndex = LControl.GetItemCount();
        LControl.InsertItem(elementAtIndex, Name);
        LControl.SetItemText(elementAtIndex, 1, Year);

        SetDlgItemText(IDC_EDIT1, _T(""));
        SetDlgItemText(IDC_EDIT2, _T(""));

        GetDlgItem(IDC_EDIT1)->SetFocus();
    }
    else 
    {
        MessageBox(_T("Invalid entry"), _T("Error"), MB_OK | MB_ICONWARNING);
    }
}


void MainDlg::ClickDelete()
{
	const int item = LControl.GetNextItem(-1, LVNI_SELECTED);
    if (item != -1)
    {
        LControl.DeleteItem(item);
    }
    else 
    {
        MessageBox(_T("Select item to delete."), _T("Error"), MB_OK | MB_ICONWARNING);
    }
		
}
