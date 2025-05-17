#pragma once

#include "resource.h"	

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);
	enum { IDD = IDD_V8_DIALOG };
	CListCtrl movies;
	afx_msg void OnAdd();
	afx_msg void OnDelete();

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
};
