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
	DDX_Control(pDX, IDC_EDIT1, title_edit);
	DDX_Control(pDX, IDC_EDIT2, year_edit);
	DDX_Control(pDX, IDC_LIST1, movies_list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddButtonClicked)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDeleteButtonClicked)
	//ON_BN_CLICKED(IDC_BUTTON3, &MainDlg::OnDeleteAllClicked)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movies_list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 135);
	movies_list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 55);
	movies_list.SetExtendedStyle(movies_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnAddButtonClicked()
{
	CString s;
	title_edit.GetWindowText(s);
	int n_item = movies_list.GetItemCount();
	movies_list.InsertItem(n_item, s);
	year_edit.GetWindowText(s);
	movies_list.SetItemText(n_item, 1, s);
	title_edit.SetWindowText("");
	year_edit.SetWindowText("");

}

void MainDlg::OnDeleteButtonClicked()
{
	int selected = movies_list.GetNextItem(-1, LVNI_SELECTED);
	if (selected != -1) {
		movies_list.DeleteItem(selected);
	}

} 

