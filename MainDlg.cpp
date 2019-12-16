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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddButton)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::DeleteButton)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movieList.InsertColumn(0, "Title", LVCFMT_LEFT, 100, 20);
	movieList.InsertColumn(1, "Year", LVCFMT_CENTER, 100, 20);
	movieList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);

	return TRUE;
}



void MainDlg::AddButton()
{

	CString movieName;
	CString movieYear;
	GetDlgItemText(IDC_EDIT1, movieName);
	GetDlgItemText(IDC_EDIT2, movieYear);
	int inputIndex = movieList.GetItemCount();
	
	if (movieName == "" || movieYear == "")
		return;
	
	movieList.InsertItem(inputIndex, movieName);
	movieList.SetItemText(inputIndex, 1, movieYear);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
	
}


void MainDlg::DeleteButton()
{
	movieList.DeleteItem(movieList.GetNextItem(-1,LVNI_SELECTED));	
	if (movieList.GetItemCount() == 0)
		GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
}
