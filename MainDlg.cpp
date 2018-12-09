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
	DDX_Control(pDX, IDC_LIST1, List);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2,&MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	List.InsertColumn(0,_T("Title"),LVCFMT_LEFT,80);
	List.InsertColumn(1,_T("Year"),LVCFMT_CENTER,80);
	
	List.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}

void MainDlg::OnBnClickedButton1()
{
	
	CString text1,text2;
	GetDlgItemText(IDC_EDIT1,text1);
	GetDlgItemText(IDC_EDIT2, text2);

	if (!text1.IsEmpty() && !text2.IsEmpty()) {

		int i = List.GetItemCount();
		List.InsertItem(i, text1);
		List.SetItemText(i, 1, text2);
	}

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}
void MainDlg::OnBnClickedButton2()
{
	
	int selektiran = List.GetNextItem(-1, LVNI_SELECTED);
	if (selektiran != -1) {
		List.DeleteItem(selektiran);
	}


	
}

