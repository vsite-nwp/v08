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
	ON_BN_CLICKED(IDC_BUTTON1, MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, MainDlg::OnDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);		// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	list_control.InsertColumn(
		0, 
		"Title", 
		LVCFMT_LEFT, 
		100, 
		-1);

	list_control.InsertColumn(
		1, 
		"Year", 
		LVCFMT_RIGHT, 
		100, 
		-1);

	list_control.SetExtendedStyle( LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnAdd() 
{
	CString fieldValue;
	const int item_count = list_control.GetItemCount();

	GetDlgItemText(IDC_EDIT1, fieldValue);
	list_control.InsertItem(item_count, fieldValue);

	GetDlgItemText(IDC_EDIT2, fieldValue);
	list_control.SetItemText(item_count, 1, fieldValue);

	list_size++;
}

void MainDlg::OnDelete() 
{
	if (list_size <= 0 || list_control.GetItemCount() <= 0)
		return;

	if (list_control.DeleteItem(list_control.GetNextItem(-1, LVNI_SELECTED)) != 0)
	{
		list_size--;
	}

	const int delete_item_id = list_control.GetNextItem(-1, LVNI_SELECTED);
	if (delete_item_id != -1)
	{
		list_control.DeleteItem(delete_item_id);
	}
}

