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
	DDX_Control(pDX, IDC_LIST1, controlv);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MainDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	controlv.InsertColumn(0, "Title", 0, 95, -1);
	controlv.InsertColumn(1, "Year", 0, 95, -1);
	controlv.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString text;
	int i=controlv.GetItemCount();
	GetDlgItemText(IDC_EDIT1, text);
	controlv.InsertItem(i, text);
	GetDlgItemText(IDC_EDIT2, text);
	controlv.SetItemText(i, 1, text);
}


void MainDlg::OnBnClickedButton2()
{
	int i = controlv.GetNextItem(-1, LVNI_SELECTED);
	if(i>=0)
		controlv.DeleteItem(i);
}


void MainDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}
