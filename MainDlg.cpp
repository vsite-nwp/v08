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

	DDX_Control(pDX, IDC_LIST1, Movies);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)

	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButtonDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	SetDlgItemText(IDC_EDIT1, "Unesite ime filma");
	SetDlgItemText(IDC_EDIT2, "Unesite godinu filma");
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	Movies.InsertColumn(0, _T("Name"), LVCFMT_CENTER, 100);
	Movies.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 50);
	Movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}



void MainDlg::OnBnClickedButtonAdd()
{
	CString movie_name, movie_year;
	GetDlgItemText(IDC_EDIT1, movie_name);
	GetDlgItemText(IDC_EDIT2, movie_year);
	int index = Movies.GetItemCount();
	if (movie_name.IsEmpty() || movie_year.IsEmpty()) {
		MessageBox("ENTER NAME AND YEAR!", "Warning", MB_OK | MB_ICONWARNING);
	}
	else {
		Movies.InsertItem(index, movie_name);
		Movies.SetItemText(index, 1, movie_year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}


}


void MainDlg::OnBnClickedButtonDelete()
{
	const int movie = Movies.GetNextItem(-1, LVNI_SELECTED);
	if (movie != -1) Movies.DeleteItem(movie);
}
