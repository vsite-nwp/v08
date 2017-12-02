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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	movieList.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 150);
	movieList.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50);
	movieList.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}



void MainDlg::OnAdd()
{
	CString movieInfo;
	int itemCnt = movieList.GetItemCount();

	GetDlgItemText(IDC_EDIT1, movieInfo);
	movieList.InsertItem(itemCnt,movieInfo);
	GetDlgItemText(IDC_EDIT2, movieInfo);
	movieList.SetItemText(itemCnt, 1, movieInfo);

	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::OnDelete()
{
	int indSelected = movieList.GetNextItem(-1, LVNI_SELECTED);
	if (indSelected == -1) {
		MessageBox(_T("No items were selected!"), _T("Warning"), 0);
		return;
	}
	movieList.DeleteItem(indSelected);
}
