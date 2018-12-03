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
	DDX_Control(pDX, IDC_LIST1, movieList);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &MainDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{	
	CDialog::OnInitDialog();
	movieList.InsertColumn(0, _T("Title"), 0, 120, -1);
	movieList.InsertColumn(1, _T("Year"), 0, 50, -1);
	movieList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString inputText;
	int currIndex;
	currIndex=movieList.GetItemCount();
	GetDlgItemText(IDC_EDIT1, inputText);
	movieList.InsertItem(currIndex, inputText);
	GetDlgItemText(IDC_EDIT2, inputText);
	movieList.SetItemText(currIndex, 1, inputText);
}

void MainDlg::OnBnClickedButton2()
{
	int deleteIndex;
	deleteIndex = movieList.GetNextItem(-1, LVNI_SELECTED);
	if (deleteIndex != -1) movieList.DeleteItem(deleteIndex);
}

void MainDlg::OnEnChangeEdit1()
{
	//ignore, added by accident and linker complained
}


