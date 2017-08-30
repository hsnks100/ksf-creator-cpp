// KSF Creator2View.h : CKSFCreator2View 클래스의 인터페이스
//


#pragma once

#include <vector>
#include <map>
#include "ximage.h"
#include <shlwapi.h>
#include <set>
#include <algorithm>
#include "MainFrm.h"
#include "Rotation.h"
#include "SpaceSetting.h"
#include "fmod.h"
#include "fmod_errors.h"    // optional
using std::vector;
using std::map;



class CKSFCreator2Doc;
class CKSFCreator2View : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	

// 특성입니다.
public:
	CKSFCreator2Doc* GetDocument() const;
	
	unsigned int BeginSel;
	unsigned int EndSel;
	bool Double;
	void SetScroll();
	void MoveScroll(int sel);
	unsigned int speedrate;
	FSOUND_STREAM *stream;
	CBitmap hBit;
	void makewhite();
	void CreatePic(const TCHAR* path, unsigned int height, unsigned int speed);
	virtual ~CKSFCreator2View();
	
// 작업입니다.
private:
	HBITMAP MakeDIBSection(CDC* pDC, int width, int height);
	void drawLine(CDC& hMemDC, const std::set<int>& linelist, int height);
	void drawBack(CDC& hMemDC, const std::vector<POINT>& stepposlist);
	void drawNote(CDC& hMemDC, const std::vector<POINT>& stepposlist);
	void drawWhite(CDC& hMemDC, int height);
	void drawVariableSpeed(CDC& hMemDC, const std::vector<POINT>& stepposlist);
	void drawBackFromVariableSpeed(CDC& hMemDC, const std::vector<POINT>& stepposlist);
	bool adjustLineData(std::set<int>& linelist, std::vector<POINT>& stepposlist, int height);
	CBitmap ArrowImg;
	CBitmap COPImg;
	CBitmap COP2Img;
	CBrush Brush;
	CBrush Brush2;
	CPen Pen;
	CPen Pen2;
	CPen Pen3;
	static signed char F_CALLBACKAPI endcallback(FSOUND_STREAM *stream, void *buff, int len, void *param);
	int getWidth(int h);
	int getHeight();
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
	CKSFCreator2View();
	DECLARE_DYNCREATE(CKSFCreator2View)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSingle();
	afx_msg void OnDouble();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void On1x();
	afx_msg void On2x();
	afx_msg void On3x();
	afx_msg void On4x();
	afx_msg void On5x();
	afx_msg void On8x();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPlayksf();
	afx_msg void OnPlayksf0();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnStop();
	afx_msg void OnKsftopic();
	
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // KSF Creator2View.cpp의 디버그 버전
inline CKSFCreator2Doc* CKSFCreator2View::GetDocument() const
   { return reinterpret_cast<CKSFCreator2Doc*>(m_pDocument); }
#endif
	

