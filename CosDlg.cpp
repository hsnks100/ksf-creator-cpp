// CosDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KSF Creator2.h"
#include "CosDlg.h"


// CosDlg dialog

IMPLEMENT_DYNAMIC(CosDlg, CDialog)

CosDlg::CosDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CosDlg::IDD, pParent)
{

}

CosDlg::~CosDlg()
{
}

void CosDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CosDlg, CDialog)
	ON_BN_CLICKED(IDC_OK, &CosDlg::OnBnClickedOk)
	ON_WM_CREATE()
//	ON_BN_CLICKED(IDC_BUTTON1, &CosDlg::OnBnClickedButton1)
ON_EN_SETFOCUS(IDC_EDITCOS, &CosDlg::OnEnSetfocusEditcos)
END_MESSAGE_MAP()


// CosDlg message handlers

void CosDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CString cstr;
	GetDlgItemText(IDC_EDITCOS, cstr);

	tmatch results;
	tregex expression;
	expression = TEXT("(\\r\\n)*(^(\\|[BTDE](\\d+\\.?\\d+|\\d+)\\||^#(BPM|TICKCOUNT|DELAY|DELAYBEAT):(\\d+\\.?\\d+|\\d+);)(\\r\\n)*)+");
	if(cstr == TEXT("") || regex_match((LPTSTR)(LPCTSTR)cstr, expression))
	{
		pDoc->m_ksf.ChangeCos(steppos, (const TCHAR*)cstr);
		pDoc->SetModifiedFlag(TRUE);
		EndDialog(-1);
	}
	else
	{
		MessageBox(TEXT("입력값이 올바르지 않습니다."));
		::SetFocus(::GetDlgItem(m_hWnd, IDC_EDITCOS));
	}
}

int CosDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	
	return 0;
}

BOOL CosDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  Add extra initialization here
	tstring data;
	map<int, vector<tstring> >::const_iterator it = pDoc->m_ksf.getChangeOfSpeed().find(steppos);
	if(pDoc->m_ksf.getChangeOfSpeed().end() != it)
	{
		for(int i=0; i<it->second.size(); i++)
		{
			data += it->second[i];
			data += TEXT("\r\n");
		}
	}
	SetDlgItemText(IDC_EDITCOS, data.c_str());

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CosDlg::Create(LPCTSTR lpszTemplateName, CWnd* pParentWnd)
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDialog::Create(lpszTemplateName, pParentWnd);
}

//void CosDlg::OnBnClickedButton1()
//{
//	
//	// TODO: Add your control notification handler code here
//}

void CosDlg::OnEnSetfocusEditcos()
{
	// TODO: Add your control notification handler code here
	CEdit* p = (CEdit*)GetDlgItem(IDC_EDITCOS);
	p->SetSel(-1);
}
