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
	DDX_Control(pDX, IDC_LIST1, MoviesTitles);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);        // Set small icon

	MoviesTitles.InsertColumn(0, "Title", LVCFMT_LEFT, 100);
	MoviesTitles.InsertColumn(1, "Year", LVCFMT_CENTER, 100);

	MoviesTitles.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	// Add your control notification handler code here
	CString Name, Year;
	const int Index = MoviesTitles.GetItemCount();

	GetDlgItemText(IDC_EDIT1, Name);
	GetDlgItemText(IDC_EDIT2, Year);

	if (Name.IsEmpty() || Year.IsEmpty()) {
		return;
	}

	MoviesTitles.InsertItem(Index, Name);
	MoviesTitles.SetItemText(Index, 1, Year);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}


void MainDlg::DeleteButton2()
{
    // Add your control notification handler code here

	MoviesTitles.DeleteItem(MoviesTitles.GetNextItem(-1, LVNI_SELECTED));
}
