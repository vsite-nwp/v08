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
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnAddMovie)
	ON_BN_CLICKED(IDC_BUTTON2, &MainDlg::OnRemoveMovie)
END_MESSAGE_MAP()

BOOL MainDlg::OnInitDialog()
{	
	CDialog::OnInitDialog();
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	ListaFilmova.InsertColumn(1, "Naslov", LVCFMT_LEFT,90);
	ListaFilmova.InsertColumn(2, "Godina", LVCFMT_LEFT,110);
	return TRUE;
}

void MainDlg::OnAddMovie() {
	CString naslov, godina;
	int index = ListaFilmova.GetItemCount();

	GetDlgItemText(IDC_EDIT1, naslov);
	GetDlgItemText(IDC_EDIT2, godina);

	if(naslov == "" || godina == "") return;

	ListaFilmova.InsertItem(index, naslov);
	ListaFilmova.SetItemText(index, 1, godina);
}

void MainDlg::OnRemoveMovie() {
	ListaFilmova.DeleteItem(ListaFilmova.GetNextItem(-1, LVNI_SELECTED));
}
