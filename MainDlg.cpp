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
	, title(_T("Enter Movie Title"))
	, year("0000")
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, movie);
	DDX_Text(pDX, IDC_EDIT1, title);
	DDX_Text(pDX, IDC_EDIT2, year);
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
	movie.InsertColumn(0, "Title", LVCFMT_CENTER, 141);
	movie.InsertColumn(1, "Year", LVCFMT_CENTER, 50);
	movie.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{	
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	movie.InsertItem(0, title);
	movie.SetItemText(0, 1, year);
}


void MainDlg::OnBnClickedButton2()
{
	movie.DeleteItem(movie.GetNextItem(-1, LVNI_SELECTED));
}
