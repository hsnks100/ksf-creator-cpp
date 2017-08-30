#pragma once

#include "KSF Creator2Doc.h"
#include "KSF Creator2.h"

// Rotation dialog

class CKSFCreator2Doc;
class Rotation : public CDialog
{
	DECLARE_DYNAMIC(Rotation)

public:
	int rangeS;
	int rangeE;
	bool defaultSingle;
	CKSFCreator2Doc* pDoc;
	Rotation(CWnd* pParent = NULL);   // standard constructor
	virtual ~Rotation();

// Dialog Data
	enum { IDD = IDD_STEPROTATION };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnSteprotation();
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();

private:
	bool GetChecked(int id);
	
	afx_msg void OnBnClickedHori();
	afx_msg void OnBnClickedDouble();
	afx_msg void OnBnClicked1p();
	afx_msg void OnBnClicked2p();
};
