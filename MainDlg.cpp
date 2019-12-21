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
	DDX_Control(pDX, IDC_LIST1, filmovi);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, onButtonClickAdd)
	ON_BN_CLICKED(IDC_BUTTON2, onButtonClickDelete)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	filmovi.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	filmovi.InsertColumn(0, _T("Title"), LVCFMT_LEFT, 140, -1);
	filmovi.InsertColumn(1, _T("Year"), LVCFMT_LEFT, 50, -1);

	return TRUE;
}

void MainDlg::onButtonClickAdd()
{
	CString title, year;
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	if (!title.IsEmpty() || !year.IsEmpty())
	{
		filmovi.InsertItem(0, title);
		filmovi.SetItemText(0, 1, year);
		SetDlgItemText(IDC_EDIT1, "");
		SetDlgItemText(IDC_EDIT2, "");
	}
}

void MainDlg::onButtonClickDelete()
{
	filmovi.DeleteItem(filmovi.GetNextItem(-1, LVNI_SELECTED));
}