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
	DDX_Control(pDX, IDC_LIST1, coll);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)

	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnDelete)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	coll.InsertColumn(0, "Title", 0, 120);
	coll.InsertColumn(1, "Year", 0, 70);
	coll.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	return TRUE;
}


void MainDlg::OnDelete()
{
	int check = coll.GetNextItem(-1, LVNI_SELECTED);
	if (check > -1)
		coll.DeleteItem(check);
}


void MainDlg::OnAdd()
{
	CString txt1, txt2;
	int count = coll.GetItemCount();
	GetDlgItemText(IDC_EDIT1, txt1);
	GetDlgItemText(IDC_EDIT2, txt2);
	if (!txt1.IsEmpty() && !txt2.IsEmpty()) {
		int row = coll.InsertItem(count, txt1);
		coll.SetItemText(row, 1, txt2);

	}
	else
		MessageBox("Unijeti oba polja!!!");
}
