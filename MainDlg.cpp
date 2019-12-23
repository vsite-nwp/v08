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
	DDX_Control(pDX, IDC_LIST1, list);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::AddRow)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	list.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140);
	list.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 40);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(0);
	return TRUE;
}


void MainDlg::AddRow()
{
	int index = list.GetItemCount();
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	if (title == "" || year == "")
	{
		MessageBox(_T("Nijesmo se tako dogovor'li!!!\nUpiši nešto!"), "Greška", MB_OK | MB_ICONWARNING);
		return;
	}
			
	list.InsertItem(index, title);
	list.SetItemText(index, 1, year);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
	GetDlgItem(IDC_BUTTON2)->EnableWindow(1);
}
