// SpaceSetting.cpp : implementation file
//

#include "stdafx.h"
#include "KSF Creator2.h"
#include "SpaceSetting.h"
#include "KSF Creator2View.h"

// SpaceSetting dialog

IMPLEMENT_DYNAMIC(SpaceSetting, CDialog)

SpaceSetting::SpaceSetting(CWnd* pParent /*=NULL*/)
	: CDialog(SpaceSetting::IDD, pParent)
{

}

SpaceSetting::~SpaceSetting()
{
}

void SpaceSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SpaceSetting, CDialog)
	ON_BN_CLICKED(IDOK, &SpaceSetting::OnBnClickedOk)
END_MESSAGE_MAP()


// SpaceSetting message handlers

void SpaceSetting::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	unsigned int spacevalue = GetDlgItemInt(IDC_SPACEVALUE, 0, false);
	pDoc->m_ksf.setSpace(rangeS, rangeE, Double, spacevalue);
	POSITION pos = pDoc->GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)pDoc->GetNextView(pos);
	if(pView->EndSel > pDoc->m_ksf.getStepInfo().size()-1)
		pView->EndSel = pDoc->m_ksf.getStepInfo().size()-1;

	if(pView->BeginSel > pDoc->m_ksf.getStepInfo().size()-1)
		pView->BeginSel = pDoc->m_ksf.getStepInfo().size()-1;
	OnOK();
}
