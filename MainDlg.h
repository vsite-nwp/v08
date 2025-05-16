#pragma once

#include "resource.h"	

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

private:
	CListCtrl m_listCtrl;
	CEdit m_edit1;
	CEdit m_edit2;

	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
};
