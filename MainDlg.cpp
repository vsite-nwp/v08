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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddItem)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteItem)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movieList.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 200);
	movieList.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 80);
	movieList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::OnAddItem()
{
	CString titleSave, yearSave;
	GetDlgItemText(IDC_EDIT1, titleSave);
	GetDlgItemText(IDC_EDIT2, yearSave);

	int movieCount = movieList.GetItemCount();

	movieList.InsertItem(movieCount, titleSave);
	movieList.SetItemText(movieCount, 1, yearSave);

	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
}

void MainDlg::OnDeleteItem()
{
	int movieSelect = movieList.GetNextItem(-1, LVNI_SELECTED);
	if (movieSelect == -1) {
		return;
	}
	movieList.DeleteItem(movieSelect);
}
