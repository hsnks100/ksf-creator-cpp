// ChildFrm.h : CChildFrame 클래스의 인터페이스
//


#pragma once

#include "KSF Creator2Doc.h"
class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// 특성입니다.
public:
	CDialogBar CDB;
// 작업입니다.
public:
	void DataToControl(const CKSFCreator2Doc* pDoc);
// 재정의입니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, const RECT& rect = rectDefault, CMDIFrameWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
