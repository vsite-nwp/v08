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
	DDX_Control(pDX, IDC_BUTTON2, ButtonDelete);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MainDlg::OnLvnItemchangedList1)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{	
	
	
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	movies.InsertColumn(0, _T("Title"),0,100,100);
	movies.InsertColumn(1, _T("Year"),0,100,100);
	movies.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	
	return TRUE;
}



void MainDlg::OnAdd()
{
	
	CString title,year;
	
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	int row=movies.InsertItem(movies.GetItemCount(), title);
	movies.SetItemText(row,1, year);
}


void MainDlg::OnDelete()
{

	int selected = movies.GetNextItem(-1, LVNI_SELECTED);
	movies.DeleteItem(selected);
	movies.SetItemState(selected - 1, LVIS_SELECTED, LVIS_SELECTED);

}


void MainDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	if (movies.GetNextItem(-1, LVNI_SELECTED) > -1)
	{
		ButtonDelete.EnableWindow();
	}
	else
	{
		ButtonDelete.EnableWindow(0);
	}
	*pResult = 0;
}
