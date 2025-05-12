#pragma once

#include "resource.h"	
#include "afxcmn.h"  // Potrebno za CListCtrl

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);
	enum { IDD = IDD_V8_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
