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
	DDX_Control(pDX, IDC_LIST1, list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	list.InsertColumn(0, "Title", LVCFMT_LEFT, 100,-1);
	list.InsertColumn(1,"Year",LVCFMT_LEFT,200,-1);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}



void MainDlg::OnClickedButton1()
{
	CString text1, text2;
	GetDlgItemText(IDC_EDIT1, text1);
	GetDlgItemText(IDC_EDIT2, text2);
	int index = list.GetItemCount();
	list.InsertItem(index, text1);
	list.SetItemText(index,1, text2);
	list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	SetDlgItemText(IDC_EDIT1, " ");
	SetDlgItemText(IDC_EDIT2, " ");
}


void MainDlg::OnBnClickedButton2()
{
	int i = list.GetNextItem(-1, LVNI_SELECTED);
	if (i > -1)
		list.DeleteItem(i);
}
