#pragma once

#include "KSF Creator2Doc.h"

class CKSFCreator2Doc;
// CosDlg dialog

class CosDlg : public CDialog
{
	DECLARE_DYNAMIC(CosDlg)

public:
	CosDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CosDlg();

	int steppos;
	CKSFCreator2Doc* pDoc;
// Dialog Data
	enum { IDD = IDD_EDITCOS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
public:
	virtual BOOL OnInitDialog();
public:
	virtual BOOL Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd = NULL);
public:
//	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnEnSetfocusEditcos();
};
