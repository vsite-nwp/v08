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
	DDX_Control(pDX, IDC_LIST1, member);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	member.InsertColumn(0, _T("Ime"), LVCFMT_LEFT, 100);
	member.InsertColumn(1, _T("Godina"), LVCFMT_LEFT, 100);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString c1,c2;
	int br = member.GetItemCount();
	GetDlgItemText(IDC_EDIT1, c1);
	GetDlgItemText(IDC_EDIT2, c2);
	member.InsertItem(br, c1);
	member.SetItemText(br, 1, c2);
	
	
}


void MainDlg::OnBnClickedButton2()
{
	member.DeleteItem(member.GetNextItem(-1, LVNI_SELECTED));
	
}
