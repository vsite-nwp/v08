#pragma once

#include "resource.h"	
#include "afxcmn.h"

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };

	CListCtrl ListaFilmova;
	afx_msg void OnAddMovie();
	afx_msg void OnRemoveMovie();
	

protected:

	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
};
