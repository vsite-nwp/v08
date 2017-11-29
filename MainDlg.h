#pragma once

#include "resource.h"	
#include "afxcmn.h"
#include "afxwin.h"

class MainDlg : public CDialog
{
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl movies;
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	CButton ButtonDelete;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
};
