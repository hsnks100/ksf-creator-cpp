#pragma once

#include "KSF Creator2View.h"
#include "KSF Creator2Doc.h"
// KsfToPic dialog

class KsfToPic : public CDialog
{
	DECLARE_DYNAMIC(KsfToPic)

public:
	KsfToPic(CWnd* pParent = NULL);   // standard constructor
	virtual ~KsfToPic();
	CKSFCreator2View* pView;
// Dialog Data
	enum { IDD = IDD_KSFTOPIC };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	virtual BOOL OnInitDialog();
};
