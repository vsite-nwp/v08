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
	DDX_Control(pDX, IDC_LIST1, listOfMovies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::buttonAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::buttonRemove)
END_MESSAGE_MAP()
void MainDlg::buttonAdd() {
	CString movieName;
	CString movieYear;
	GetDlgItemText(IDC_EDIT1, movieName);
	GetDlgItemText(IDC_EDIT2, movieYear);
	int input = listOfMovies.GetItemCount();
	if (movieName=="" || movieYear=="")
		return;
	listOfMovies.InsertItem(input,movieName);
	listOfMovies.SetItemText(input, 1, movieYear);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
}
void MainDlg::buttonRemove() {
	listOfMovies.DeleteItem(listOfMovies.GetNextItem(-1, LVNI_SELECTED));
	if (listOfMovies.GetItemCount() == 0)
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
}

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	listOfMovies.InsertColumn(0, "title", LVCFMT_LEFT, 100, 20);
	listOfMovies.InsertColumn(1, "year", LVCFMT_CENTER, 100, 20);
	listOfMovies.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	return TRUE;
}

