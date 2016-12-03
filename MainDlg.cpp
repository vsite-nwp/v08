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
	DDX_Control(pDX, IDC_LIST1, ListaFilmova);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAdd)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnRemove)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	ListaFilmova.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	ListaFilmova.InsertColumn(0, "Title",0,100);
	ListaFilmova.InsertColumn(1, "Year",0,75);

	return TRUE;
}



void MainDlg::OnAdd()
{
	CString title, year;
	int slijedeci = ListaFilmova.GetItemCount();
	GetDlgItemText(IDC_EDIT1, title);
	GetDlgItemText(IDC_EDIT2, year);
	if (title == "" && year == "")
		return;
	ListaFilmova.InsertItem(slijedeci, title);
	ListaFilmova.SetItemText(slijedeci, 1, year);
	SetDlgItemText(IDC_EDIT1, "");
	SetDlgItemText(IDC_EDIT2, "");
}


void MainDlg::OnRemove()
{
	ListaFilmova.DeleteItem(ListaFilmova.GetNextItem(-1, LVNI_SELECTED));
}
