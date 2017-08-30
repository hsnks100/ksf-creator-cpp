// ChildFrm.cpp : CChildFrame 클래스의 구현
//
#include "stdafx.h"
#include "KSF Creator2.h"

#include "ChildFrm.h"
#include "MainFrm.h"
#include "KSF Creator2Doc.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CChildFrame 생성/소멸

CChildFrame::CChildFrame()
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	//cs.style |= WS_HSCROLL;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서 Window 클래스 또는 스타일을 수정합니다.
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
	
	return TRUE;
}


// CChildFrame 진단

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame 메시지 처리기

BOOL CChildFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle , const RECT& rect , CMDIFrameWnd* pParentWnd , CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	
	
	return CMDIChildWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, pContext);
}

int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	CDB.Create(this, IDD_KSFINFO, CBRS_TOP|CBRS_TOOLTIPS, IDD_KSFINFO);
	
	CComboBox* combo = (CComboBox*)CDB.GetDlgItem(IDC_PLAYTYPE);

	combo->AddString(TEXT("SINGLE"));
	combo->AddString(TEXT("DOUBLE"));
	
	return 0;
}


void CChildFrame::DataToControl(const CKSFCreator2Doc* pDoc)
{
	::SetDlgItemText(CDB.m_hWnd, IDC_TITLE, pDoc->m_ksf.m_Title.c_str());
	if(pDoc->m_ksf.m_Difficulty >= 0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_DIFFICULTY, pDoc->m_ksf.m_Difficulty, FALSE);
	else
		::SetDlgItemText(CDB.m_hWnd, IDC_DIFFICULTY, TEXT(""));
	::SetDlgItemText(CDB.m_hWnd, IDC_PLAYER, pDoc->m_ksf.m_Player.c_str());
	::SetDlgItemText(CDB.m_hWnd, IDC_BPM1, pDoc->m_ksf.m_BPM1.c_str());
	::SetDlgItemText(CDB.m_hWnd, IDC_BPM2, pDoc->m_ksf.m_BPM2.c_str());
	::SetDlgItemText(CDB.m_hWnd, IDC_BPM3, pDoc->m_ksf.m_BPM3.c_str());
	if(pDoc->m_ksf.m_TickCount>=0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_TICKCOUNT, pDoc->m_ksf.m_TickCount, FALSE);
	if(pDoc->m_ksf.m_StartTime1>=0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_STARTTIME1, pDoc->m_ksf.m_StartTime1, FALSE);
	else
		::SetDlgItemText(CDB.m_hWnd, IDC_STARTTIME1, TEXT(""));
	if(pDoc->m_ksf.m_StartTime2>=0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_STARTTIME2, pDoc->m_ksf.m_StartTime2, FALSE);
	else
		::SetDlgItemText(CDB.m_hWnd, IDC_STARTTIME2, TEXT(""));
	if(pDoc->m_ksf.m_StartTime3>=0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_STARTTIME3, pDoc->m_ksf.m_StartTime3, FALSE);
	else
		::SetDlgItemText(CDB.m_hWnd, IDC_STARTTIME3, TEXT(""));
	if(pDoc->m_ksf.m_BunKi1>=0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_BUNKI1, pDoc->m_ksf.m_BunKi1, FALSE);
	else
		::SetDlgItemText(CDB.m_hWnd, IDC_BUNKI1, TEXT(""));
	if(pDoc->m_ksf.m_BunKi2>=0)
		::SetDlgItemInt(CDB.m_hWnd, IDC_BUNKI2, pDoc->m_ksf.m_BunKi2, FALSE);
	else
		::SetDlgItemText(CDB.m_hWnd, IDC_BUNKI2, TEXT(""));
	::SetDlgItemText(CDB.m_hWnd, IDC_INTROFILE, pDoc->m_ksf.m_IntroFile.c_str());
	::SetDlgItemText(CDB.m_hWnd, IDC_SONGFILE, pDoc->m_ksf.m_SongFile.c_str());
	::SetDlgItemText(CDB.m_hWnd, IDC_DISCFILE, pDoc->m_ksf.m_DiscFile.c_str());
	::SetDlgItemText(CDB.m_hWnd, IDC_TITLEFILE, pDoc->m_ksf.m_TitleFile.c_str());
	
	CComboBox* combo = (CComboBox*)CDB.GetDlgItem(IDC_PLAYTYPE);
	if(pDoc->m_ksf.m_Player == TEXT("SINGLE"))
	{
		combo->SetWindowText(TEXT("SINGLE"));
	}
	else if(pDoc->m_ksf.m_Player == TEXT("DOUBLE"))
	{
		combo->SetWindowText(TEXT("DOUBLE"));
	}
	else
	{
		combo->SetWindowText(pDoc->m_ksf.m_Player.c_str());
	}
}