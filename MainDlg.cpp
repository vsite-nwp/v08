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
	DDX_Control(pDX, IDC_LIST1, Ctrl);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	Ctrl.InsertColumn(1, _T("Title"), 0, 100);
	Ctrl.InsertColumn(2, _T("Year"), 0, 75);
	Ctrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnAdd()
{
	CString ime,godina;
	GetDlgItemText(IDC_EDIT1, ime);
	GetDlgItemText(IDC_EDIT2, godina);
	int ind = Ctrl.InsertItem(Ctrl.GetItemCount(), ime);
	Ctrl.SetItemText(ind, 1, godina);
}


void MainDlg::OnDelete()
{
	Ctrl.DeleteItem(Ctrl.GetNextItem(-1, LVNI_SELECTED));
	
}
