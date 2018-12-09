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
	DDX_Control(pDX, IDC_LIST1, list_control);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::Add)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::Delete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	list_control.InsertColumn(0,_T("Naslov"),LVCFMT_LEFT,100);
	list_control.InsertColumn(1, _T("Godina"), LVCFMT_CENTER, 100);
	list_control.SetExtendedStyle(list_control.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	
	return TRUE;
}


void MainDlg::Add()
{
	CString naslov, godina;
		
	GetDlgItemText(IDC_EDIT1, naslov);
	GetDlgItemText(IDC_EDIT2, godina);

	int stupac = list_control.InsertItem(list_control.GetItemCount(), naslov);

	
	list_control.SetItemText(stupac, 1, godina);

	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT2,"");
}

void MainDlg::Delete()
{
	int temp_delete;
	temp_delete=list_control.GetNextItem(-1, LVNI_SELECTED);
	if (temp_delete != -1)list_control.DeleteItem(temp_delete);
}
