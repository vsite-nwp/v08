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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	List.InsertColumn(0, _T("Title"), 0, 150);
	List.InsertColumn(1, _T("Year"), 0, 40);
	List.SetExtendedStyle(List.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnClickedButton1()
{//add
	CString text;
	GetDlgItemText(IDC_EDIT1, text);
	int line = List.InsertItem(List.GetItemCount(), text);

	GetDlgItemText(IDC_EDIT2, text);
	List.SetItemText(line, 1, text);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}


void MainDlg::OnClickedButton2()
{//delete
	List.DeleteItem(List.GetNextItem(-1, LVNI_SELECTED));
}
