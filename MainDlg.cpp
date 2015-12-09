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
	DDX_Control(pDX, IDC_LIST1, listCtrl);
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

	listCtrl.InsertColumn(1, _T("Title"),0,100);
	listCtrl.InsertColumn(2, _T("Year"),0,50);
	
	listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	return TRUE;
}



void MainDlg::OnAdd()
{
	int index;
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	index = listCtrl.GetItemCount();

	listCtrl.InsertItem(index, title);
	listCtrl.SetItemText(index, 1, year);

	listCtrl.SetItemState(index, LVIS_SELECTED, LVIS_SELECTED);
}


void MainDlg::OnDelete()
{
	int count;

	listCtrl.DeleteItem(listCtrl.GetNextItem(-1, LVNI_SELECTED));

	count = listCtrl.GetItemCount() - 1;
	if (count >= 0)
		listCtrl.SetItemState(count, LVIS_SELECTED, LVIS_SELECTED);
}