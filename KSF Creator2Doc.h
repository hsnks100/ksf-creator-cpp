// KSF Creator2Doc.h : CKSFCreator2Doc 클래스의 인터페이스
//


#pragma once

#include "KSF Creator2View.h"
#include "ksfinfo.h"
#include "CosDlg.h"
#include "KSF Creator2.h"
class CKSFCreator2Doc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CKSFCreator2Doc();
	DECLARE_DYNCREATE(CKSFCreator2Doc)

// 특성입니다.
public:
	ksfinfo m_ksf;
// 작업입니다.
public:
	void GetTextBox(TCHAR* str, int id);
	
// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 구현입니다.
public:
	virtual ~CKSFCreator2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);

	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void SetModifiedFlag(BOOL bModified = 1);

	virtual void OnCloseDocument();

	//afx_msg void OnBnClickedAplly();
	afx_msg void OnEnChangeTitle();
	afx_msg void OnEnChangeDifficulty();
	afx_msg void OnEnChangePlayer();
	afx_msg void OnEnChangeStarttime2();
	afx_msg void OnEnChangeStarttime3();
	afx_msg void OnEnChangeBunki2();
	afx_msg void OnEnChangeBunki1();
	afx_msg void OnEnChangeStarttime1();
	afx_msg void OnEnChangeIntrofile();
	afx_msg void OnEnChangeSongfile();
	afx_msg void OnEnChangeDiscfile();
	afx_msg void OnEnChangeTitlefile();
	afx_msg void OnEnChangeBpm2();
	afx_msg void OnEnChangeBpm3();
	afx_msg void OnEnChangeBpm1();
	afx_msg void OnInsertstep();
	afx_msg void OnPushbackstep();
	afx_msg void OnEnKillfocusTitle();
	afx_msg void OnRemovestep();
	afx_msg void OnEnChangeTickcount();
	afx_msg void OnCbnSelchangePlaytype();
	afx_msg void OnCbnEditchangePlaytype();
	afx_msg void OnStepRotation();
	
	afx_msg void OnSpacesetting();
	afx_msg void OnInsertspeed();
	afx_msg void OnEditPaste();
	afx_msg void OnEditCut();
	afx_msg void OnEditCopy();
private:
	
	
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	
	afx_msg void OnBnClickedSearchsongfile();
	afx_msg void OnBnClickedSearchintrofile();
	afx_msg void OnBnClickedSearchidiscfile();
	afx_msg void OnBnClickedSearchtitlefile();
	
};


