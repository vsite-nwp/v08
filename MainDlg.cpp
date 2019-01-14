#include "stdafx.h"
#include "v8.h"
#include "MainDlg.h"
#include "cstring"

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
	DDX_Control(pDX, IDC_LIST1, cLista);
}

BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnBnClickedButton2)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	cLista.InsertColumn(0, "Naslov", LVCFMT_LEFT, 100, 20);
	cLista.InsertColumn(1, "Godina", LVCFMT_CENTER, 60, 10);
	cLista.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;
}



void MainDlg::OnBnClickedButton1()
{
	CString name_of_the_movie;
	CString year_of_the_movie;

	GetDlgItemText(IDC_EDIT1, name_of_the_movie);
	GetDlgItemText(IDC_EDIT2, year_of_the_movie);

	int brojac = cLista.GetItemCount();

	cLista.InsertItem(brojac, name_of_the_movie);
	cLista.SetItemText(brojac, 1, year_of_the_movie);
}


void MainDlg::OnBnClickedButton2()
{
	cLista.DeleteItem(cLista.GetNextItem(-1, LVNI_SELECTED));
}