#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

MainDlg::MainDlg(CWnd* pParent)
	: CDialog(MainDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MainDlg::DoDataExchange(CDataExchange* pDDX)
{
	CDialog::DoDataExchange(pDDX);
	DDX_Control(pDDX, IDC_LIST1, lista);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	lista.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 150);
	lista.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50);
	lista.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}

void MainDlg::OnClickedButton1()
{
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);

	if (!title.IsEmpty() && !year.IsEmpty()) {
		int mCount = lista.GetItemCount();
		lista.InsertItem(mCount, title);
		lista.SetItemText(mCount, 1, year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
		GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	}
}

void MainDlg::OnClickedButton2()
{
	if (lista.GetNextItem(-1, LVNI_SELECTED) != -1)
		lista.DeleteItem(lista.GetNextItem(-1, LVNI_SELECTED));
}
void MainDlg::OnOK()
{
	OnClickedButton1();
}
