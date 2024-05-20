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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::CB1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::CL2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	int InsertColumn(
		int nCol,
		const LVCOLUMN * pColumn);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	LControl.InsertColumn(0, _T("Name"), LVCFMT_CENTER, 90);
	LControl.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 45);
	LControl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::CB1()
{
	CString Name, Year;
	GetDlgItemText(IDC_EDIT1, Name);
	GetDlgItemText(IDC_EDIT2, Year);
	const int elementAtIndex = LControl.GetItemCount();
	if (!(Name.IsEmpty() || Year.IsEmpty())) {
		LControl.InsertItem(elementAtIndex, Name);
		LControl.SetItemText(elementAtIndex, 1, Year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
	else
		MessageBox("Wrong or inccorect entry.", "Warning:", MB_OK | MB_ICONWARNING);
}


void MainDlg::CL2()
{
	const int item = LControl.GetNextItem(-1, LVNI_SELECTED);
	if (item != -1)
		LControl.DeleteItem(item);
}
