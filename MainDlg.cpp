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
	DDX_Control(pDX, IDC_LIST1, movies);
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

	//dodaj stupce u listu
	movies.InsertColumn(0, "Title", LVCFMT_LEFT, 100, 20);
	movies.InsertColumn(1, "Year", LVCFMT_CENTER, 100, 20);
	movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}

void MainDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CString movieTitle;
	//int movieYear;
	CString movieYear;

	//uzimam iz edit kontrole
	GetDlgItemText(IDC_EDIT1, movieTitle);
	//GetDlgItemInt(IDC_EDIT2, movieYear);
	//(IDC_EDIT2, _T(movieYear);
	GetDlgItemText(IDC_EDIT2, movieYear);

	//dodavanje reda i postavljenje teksta prvog stupca
	int count = movies.GetItemCount();
	if (movieTitle.IsEmpty() || movieYear.IsEmpty())
		return;

	movies.InsertItem(count,movieTitle);
	movies.SetItemText(count,1,movieYear); //subitem je stupac

	//ocisti edit box
	SetDlgItemText(IDC_EDIT1, NULL);
	SetDlgItemText(IDC_EDIT2, NULL);
}


void MainDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	movies.DeleteItem(movies.GetNextItem(-1,LVNI_SELECTED));
}
