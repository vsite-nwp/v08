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
	DDX_Control(pDX, IDC_LIST1, listItem);
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

	listItem.InsertColumn(0, "Title", LVCFMT_LEFT, 120);
	listItem.InsertColumn(1, "Year", LVCFMT_LEFT, 70);
	listItem.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::Add()
{
	int  cnt = listItem.GetItemCount();
	CString prijenos1, prijenos2;
	
	GetDlgItemText(IDC_EDIT1, prijenos1);
	GetDlgItemText(IDC_EDIT2, prijenos2);

	if (!prijenos1.IsEmpty() && !prijenos2.IsEmpty())
	{
		listItem.InsertItem(cnt, prijenos1);
		listItem.SetItemText(cnt, 1, prijenos2);
	}
	else
		MessageBox("Moraju biti unešena oba polja!", "NEPOTPUN UNOS", MB_ICONEXCLAMATION);
}


void MainDlg::Delete()
{
	int provjera = listItem.GetNextItem(-1, LVNI_SELECTED);
	if (provjera > -1)
		listItem.DeleteItem(provjera);
}
