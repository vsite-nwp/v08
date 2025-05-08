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
ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	movies.SetExtendedStyle(movies.GetExtendedStyle() |
                                LVS_EX_FULLROWSELECT);

	movies.InsertColumn(0, _T("Title"), LVCFMT_CENTER, 200);
    movies.InsertColumn(1, _T("Year"), LVCFMT_CENTER, 100);
	
	return TRUE;
}

void MainDlg::OnAdd() { 
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	if (title.IsEmpty() || year.IsEmpty()) {
        MessageBox(_T("Please enter both title and year."), _T("Error"),
                    MB_OK | MB_ICONERROR);
        return;
    }

	int index = movies.GetItemCount();
    movies.InsertItem(index, title);
    movies.SetItemText(index, 1, year);

	// Ocistiti input polja
	SetDlgItemText(IDC_EDIT1, "");
    SetDlgItemText(IDC_EDIT2, "");
}

void MainDlg::OnDelete() {
  const int item = movies.GetNextItem(-1, LVNI_SELECTED);
  if (item == -1) {
    MessageBox(_T("Please select an item to delete."), _T("Error"),
               MB_OK | MB_ICONERROR);
    return;
  }
  movies.DeleteItem(item);
}
