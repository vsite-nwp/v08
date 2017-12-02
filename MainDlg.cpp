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
	DDX_Control(pDX, IDC_LIST1, MovVar);
	
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MainDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::Add)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::Delete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CString Name = "Title";
	CString Name2 = "Year";

	MovVar.InsertColumn(0, (LPCSTR)Name, LVCFMT_LEFT, 140);
	MovVar.InsertColumn(1, (LPCSTR)Name2, LVCFMT_LEFT, 100);
	MovVar.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void MainDlg::Add()
{
	CString Txt;
	GetDlgItemText(IDC_EDIT1, Txt);
	MovVar.InsertItem(0, (LPCTSTR)Txt);
	GetDlgItemText(IDC_EDIT2, Txt);
	MovVar.SetItemText(0, 1, Txt);
}

void MainDlg::Delete()
{
	MovVar.DeleteItem(MovVar.GetNextItem(-1, LVNI_SELECTED));
	
}
