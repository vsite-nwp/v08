#pragma once

#include "resource.h"	

class MainDlg : public CDialog
{
private:
	void AddColumnsName();
	void SetEditToDefaultValue();
	bool IsMovieNameValid(CString movieName);
public:
	MainDlg(CWnd* pParent = NULL);	// standard constructor
	enum { IDD = IDD_V8_DIALOG };

protected:
	void DoDataExchange(CDataExchange* pDX) override;
	HICON m_hIcon;
	BOOL OnInitDialog() override;
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
