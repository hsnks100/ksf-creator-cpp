#pragma once

#include "KSF Creator2Doc.h"
// SpaceSetting dialog

class CKSFCreator2Doc;
class SpaceSetting : public CDialog
{
	DECLARE_DYNAMIC(SpaceSetting)

public:
	int rangeS;
	int rangeE;
	bool Double;
	CKSFCreator2Doc* pDoc;
	SpaceSetting(CWnd* pParent = NULL);   // standard constructor
	virtual ~SpaceSetting();

// Dialog Data
	enum { IDD = IDD_SPACESETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
