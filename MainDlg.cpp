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
	, YearVar(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}



void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, title);
	DDX_Control(pDX, IDC_EDIT1, box1);
	DDX_Control(pDX, IDC_EDIT2, box2);
	DDX_Text(pDX, IDC_EDIT2, YearVar);
	DDX_Control(pDX, IDC_BUTTON2, ButtonDelete);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	title.InsertColumn(0,"title",0,141);
	title.InsertColumn(1, "year", 0, 50);
	title.SetExtendedStyle(title.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
//	ButtonDelete
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}






void MainDlg::OnBnClickedButton1()
{
	int next;
	CString txt1,txt2;

		GetDlgItemText(IDC_EDIT1, txt1);
		GetDlgItemText(IDC_EDIT2, txt2);
		if (txt1 != ""&&txt2 != ""&&atoi(txt2)>1800&&atoi(txt2)<2100) {
			next = title.InsertItem(title.GetItemCount(), txt1);
			title.SetItemText(next, 1, txt2);
		}
}
void MainDlg::OnBnClickedButton2()
{
	int item;
	item = title.GetNextItem(-1, LVNI_SELECTED);
	if (item > -1)
		title.DeleteItem(item);
}





