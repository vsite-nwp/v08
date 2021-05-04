#pragma once

#include "resource.h"	

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };
	CListCtrl list, buttonAdd, buttonDelete, title, year;

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	afx_msg void Add();
	afx_msg void Del();
	DECLARE_MESSAGE_MAP()
};
