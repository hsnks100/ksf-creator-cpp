// KsfToPic.cpp : implementation file
//

#include "stdafx.h"
#include "KSF Creator2.h"
#include "ksftopic.h"


// KsfToPic dialog

IMPLEMENT_DYNAMIC(KsfToPic, CDialog)

KsfToPic::KsfToPic(CWnd* pParent /*=NULL*/)
	: CDialog(KsfToPic::IDD, pParent)
{

}

KsfToPic::~KsfToPic()
{
}

void KsfToPic::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(KsfToPic, CDialog)
	ON_BN_CLICKED(IDOK, &KsfToPic::OnBnClickedOk)
END_MESSAGE_MAP()


// KsfToPic message handlers

void KsfToPic::OnBnClickedOk()
{
	/*CxImage i;
	i.Create(640, 480, 32, CXIMAGE_FORMAT_PNG);
	bool a = i.Save(TEXT("d:\\Åª.png"), CXIMAGE_FORMAT_PNG);
	i.*/
	CFileDialog dlg(FALSE, NULL, NULL, OFN_EXPLORER, 
		TEXT("±×¸²ÆÄÀÏ (*.png)|*.png||"));

	
	dlg.m_ofn.lpstrInitialDir = (const TCHAR*)pView->GetDocument()->GetPathName();
	dlg.m_ofn.lpstrDefExt = TEXT("png");
	dlg.DoModal();

	unsigned int height = GetDlgItemInt(IDC_HEIGHT);
	unsigned int speed = GetDlgItemInt(IDC_SPEED);
	pView->CreatePic(dlg.GetPathName(), height, speed);
	// TODO: Add your control notification handler code here
	OnOK();
}

BOOL KsfToPic::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	SetDlgItemInt(IDC_SPEED, 3);
	SetDlgItemInt(IDC_HEIGHT, 768);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
