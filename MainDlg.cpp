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
	DDX_Control(pDX, IDC_LIST1, moviesList);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	moviesList.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 130);
	moviesList.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50);
	moviesList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}

void MainDlg::OnAdd()
{
	CString titleText, yearText;
	GetDlgItemText(IDC_EDIT1, titleText);
	GetDlgItemText(IDC_EDIT2, yearText);

	int moviesCount = moviesList.GetItemCount();

	moviesList.InsertItem(moviesCount, titleText);
	moviesList.SetItemText(moviesCount, 1, yearText);

	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
}

void MainDlg::OnDelete()
{
	int listChoose = moviesList.GetNextItem(-1, LVNI_SELECTED);
	if (listChoose == -1) {return;}
	moviesList.DeleteItem(listChoose);
}
