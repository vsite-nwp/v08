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
	DDX_Control(pDX, IDC_EDIT1, titleEdit);
	DDX_Control(pDX, IDC_EDIT2, yearEdit);
	DDX_Control(pDX, IDC_LIST1, movieDetail_list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::addButton_Clicked)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::deleteButton_Clicked)
	ON_BN_CLICKED(IDC_BUTTON3, &MainDlg::clearAllButton_Clicked)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movieDetail_list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 135);
	movieDetail_list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 55);
	movieDetail_list.SetExtendedStyle(movieDetail_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::addButton_Clicked() {
	CString s; CString i;
	titleEdit.GetWindowText(s);
	yearEdit.GetWindowText(i);
	movieDetail_list.SetItemText(movieDetail_list.InsertItem(movieDetail_list.GetItemCount(), s), 1, i);
	titleEdit.SetWindowText("");
	yearEdit.SetWindowText("");
}


void MainDlg::deleteButton_Clicked() {
	int pos = movieDetail_list.GetNextItem(-1, LVNI_SELECTED);
	if (pos != NULL) {
		movieDetail_list.DeleteItem(pos);
	}
}

void MainDlg::clearAllButton_Clicked() {
	movieDetail_list.DeleteAllItems();
}