// KSF Creator2Doc.cpp : CKSFCreator2Doc 클래스의 구현
//

#include "stdafx.h"

#include "KSF Creator2Doc.h"

#include "KSF Creator2View.h"
#include "ksfinfo.h"
#include "ChildFrm.h"
#include "Rotation.h"
#include "SpaceSetting.h"

#include "MainFrm.h"
#include <io.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKSFCreator2Doc

IMPLEMENT_DYNCREATE(CKSFCreator2Doc, CDocument)

BEGIN_MESSAGE_MAP(CKSFCreator2Doc, CDocument)
	ON_EN_CHANGE(IDC_TITLE, &CKSFCreator2Doc::OnEnChangeTitle)
	ON_EN_CHANGE(IDC_DIFFICULTY, &CKSFCreator2Doc::OnEnChangeDifficulty)
	ON_EN_CHANGE(IDC_PLAYER, &CKSFCreator2Doc::OnEnChangePlayer)
	ON_EN_CHANGE(IDC_STARTTIME2, &CKSFCreator2Doc::OnEnChangeStarttime2)
	ON_EN_CHANGE(IDC_STARTTIME3, &CKSFCreator2Doc::OnEnChangeStarttime3)
	ON_EN_CHANGE(IDC_BUNKI2, &CKSFCreator2Doc::OnEnChangeBunki2)
	ON_EN_CHANGE(IDC_BUNKI1, &CKSFCreator2Doc::OnEnChangeBunki1)
	ON_EN_CHANGE(IDC_STARTTIME1, &CKSFCreator2Doc::OnEnChangeStarttime1)
	ON_EN_CHANGE(IDC_INTROFILE, &CKSFCreator2Doc::OnEnChangeIntrofile)
	ON_EN_CHANGE(IDC_SONGFILE, &CKSFCreator2Doc::OnEnChangeSongfile)
	ON_EN_CHANGE(IDC_DISCFILE, &CKSFCreator2Doc::OnEnChangeDiscfile)
	ON_EN_CHANGE(IDC_TITLEFILE, &CKSFCreator2Doc::OnEnChangeTitlefile)
	ON_EN_CHANGE(IDC_BPM2, &CKSFCreator2Doc::OnEnChangeBpm2)
	ON_EN_CHANGE(IDC_BPM3, &CKSFCreator2Doc::OnEnChangeBpm3)
	ON_EN_CHANGE(IDC_BPM1, &CKSFCreator2Doc::OnEnChangeBpm1)
	ON_COMMAND(ID_INSERTSTEP, &CKSFCreator2Doc::OnInsertstep)
	ON_COMMAND(ID_PUSHBACKSTEP, &CKSFCreator2Doc::OnPushbackstep)
	ON_COMMAND(ID_STEPROTATION, &CKSFCreator2Doc::OnStepRotation)
	ON_EN_KILLFOCUS(IDC_TITLE, &CKSFCreator2Doc::OnEnKillfocusTitle)
	ON_COMMAND(ID_REMOVESTEP, &CKSFCreator2Doc::OnRemovestep)
	ON_EN_CHANGE(IDC_TICKCOUNT, &CKSFCreator2Doc::OnEnChangeTickcount)
	ON_CBN_SELCHANGE(IDC_PLAYTYPE, &CKSFCreator2Doc::OnCbnSelchangePlaytype)
	ON_CBN_EDITCHANGE(IDC_PLAYTYPE, &CKSFCreator2Doc::OnCbnEditchangePlaytype)
	ON_COMMAND(ID_EDIT_COPY, &CKSFCreator2Doc::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CKSFCreator2Doc::OnEditPaste)
	ON_COMMAND(ID_EDIT_CUT, &CKSFCreator2Doc::OnEditCut)
	//ON_COMMAND(ID_EDIT_UNDO, &CKSFCreator2Doc::OnEditUndo)
	//ON_COMMAND(ID_EDIT_REDO, &CKSFCreator2Doc::OnEditRedo)
	ON_COMMAND(ID_SPACESETTING, &CKSFCreator2Doc::OnSpacesetting)
	ON_BN_CLICKED(IDC_SEARCHSONGFILE, &CKSFCreator2Doc::OnBnClickedSearchsongfile)
	ON_BN_CLICKED(IDC_SEARCHINTROFILE, &CKSFCreator2Doc::OnBnClickedSearchintrofile)
	ON_BN_CLICKED(IDC_SEARCHIDISCFILE, &CKSFCreator2Doc::OnBnClickedSearchidiscfile)
	ON_BN_CLICKED(IDC_SEARCHTITLEFILE, &CKSFCreator2Doc::OnBnClickedSearchtitlefile)
	ON_COMMAND(ID_INSERTSPEED, &CKSFCreator2Doc::OnInsertspeed)
END_MESSAGE_MAP()


// CKSFCreator2Doc 생성/소멸



CKSFCreator2Doc::CKSFCreator2Doc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
}

CKSFCreator2Doc::~CKSFCreator2Doc()
{
}

BOOL CKSFCreator2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	mainframe->DataToControl(this);

	m_ksf.unredo.saveHistory(m_ksf.getStepData());
	return TRUE;
}




// CKSFCreator2Doc serialization

void CKSFCreator2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CKSFCreator2Doc 진단

#ifdef _DEBUG
void CKSFCreator2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKSFCreator2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKSFCreator2Doc 명령

BOOL CKSFCreator2Doc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO:  Add your specialized creation code here
	if(m_ksf.LoadKSF(lpszPathName) == FALSE)
	{
		AfxGetMainWnd()->MessageBox(TEXT("잘못된 KSF파일입니다."));
		return FALSE;
	}
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	mainframe->DataToControl(this);
	if(m_ksf.m_Player == TEXT("SINGLE"))
		pView->Double = false;
	else
		pView->Double = true;

	m_ksf.unredo.saveHistory(m_ksf.getStepData());
	return TRUE;
}

BOOL CKSFCreator2Doc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: Add your specialized code here and/or call the base class
	m_ksf.SaveKSF(lpszPathName);
	SetModifiedFlag(FALSE);
	return TRUE;
	//return CDocument::OnSaveDocument(lpszPathName);
}

void CKSFCreator2Doc::OnCloseDocument()
{
	// TODO: Add your specialized code here and/or call the base class

	CDocument::OnCloseDocument();
}



void CKSFCreator2Doc::OnEnChangeTitle()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_TITLE);
	m_ksf.m_Title = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeDifficulty()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_DIFFICULTY);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_Difficulty = -1;
	else
		m_ksf.m_Difficulty = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangePlayer()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_PLAYER);
	m_ksf.m_Player = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeStarttime2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_STARTTIME2);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_StartTime2 = -1;
	else
		m_ksf.m_StartTime2 = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeStarttime3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_STARTTIME3);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_StartTime3 = -1;
	else
		m_ksf.m_StartTime3 = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeBunki2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_BUNKI2);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_BunKi2 = -1;
	else
		m_ksf.m_BunKi2 = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeBunki1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_BUNKI1);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_BunKi1 = -1;
	else
		m_ksf.m_BunKi1 = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeStarttime1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_STARTTIME1);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_StartTime1 = -1;
	else
		m_ksf.m_StartTime1 = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeIntrofile()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_INTROFILE);
	m_ksf.m_IntroFile = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeSongfile()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_SONGFILE);
	m_ksf.m_SongFile = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeDiscfile()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_DISCFILE);
	m_ksf.m_DiscFile = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeTitlefile()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_TITLEFILE);
	m_ksf.m_TitleFile = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeBpm2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_BPM2);
	m_ksf.m_BPM2 = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnEnChangeBpm3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_BPM3);
	m_ksf.m_BPM3 = tmp;
	SetModifiedFlag(TRUE);
}


void CKSFCreator2Doc::OnEnChangeBpm1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	TCHAR tmp[256];
	GetTextBox(tmp, IDC_BPM1);
	m_ksf.m_BPM1 = tmp;
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnInsertstep()
{
	// TODO: Add your command handler code here
	// 자기 위치 <= i 인 경우는 뒤로 다 땡김
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	m_ksf.Insert(pView->EndSel, abs((int)pView->EndSel - (int)pView->BeginSel));
	SetModifiedFlag(TRUE);

	pView->SetScroll();
	pView->Invalidate(FALSE);
	
}

void CKSFCreator2Doc::OnPushbackstep()
{
	// TODO: Add your command handler code here
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	m_ksf.Pushback(abs((int)pView->EndSel - (int)pView->BeginSel));
	SetModifiedFlag(TRUE);

	pView->SetScroll();
	pView->Invalidate(FALSE);
}

void CKSFCreator2Doc::OnEnKillfocusTitle()
{
	// TODO: Add your control notification handler code here
}



void CKSFCreator2Doc::OnRemovestep()
{
	// TODO: Add your command handler code here
	
	POSITION pos;
	pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	int bs = pView->BeginSel;
	int es = pView->EndSel;
	if(bs>es)
	{
		int t = bs;
		bs = es;
		es = t;
	}
	m_ksf.Remove(bs, es);

	
	SetModifiedFlag(TRUE);

	if(pView->BeginSel > m_ksf.getStepInfo().size()-1)
		pView->BeginSel = m_ksf.getStepInfo().size()-1;
	pView->EndSel = pView->BeginSel;

	pView->SetScroll();
	pView->Invalidate(TRUE);
}

void CKSFCreator2Doc::SetModifiedFlag(BOOL bModified)
{	
	CDocument::SetModifiedFlag(bModified);
	/* ************************ 아래 코드는 바뀌면 타이틀뒤에 * 붙이려다가 구현실패 */
	//SetTitle(TEXT("몰라"));
	//CString st;
	//st = GetTitle();
	/*if(bModified == TRUE && IsModified() == TRUE)
	{
		POSITION pos;
		pos = GetFirstViewPosition();
		CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
		CString oldtitle;
		//CString str;
		//oldtitle = GetTitle();
		pView->GetParentFrame()->GetWindowText(oldtitle);
		if(oldtitle != "" && oldtitle[oldtitle.GetLength()-1] != '*')
		{
			oldtitle += "*";
			//SetTitle(oldtitle);
			pView->GetParentFrame()->SetWindowText(oldtitle);
		}
	}*/
}

void CKSFCreator2Doc::GetTextBox(TCHAR* str, int id)
{
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	//TCHAR tmp[256];
	GetDlgItemText(mainframe->CDB.m_hWnd, id, str, 256);
}
void CKSFCreator2Doc::OnEnChangeTickcount()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDocument::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	TCHAR tmp[256];
	GetTextBox(tmp, IDC_TICKCOUNT);
	if(_tcscmp(tmp, TEXT("")) == 0)
		m_ksf.m_TickCount = -1;
	else
		m_ksf.m_TickCount = _ttoi(tmp);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnCbnSelchangePlaytype()
{
	// TODO: Add your control notification handler code here
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	CComboBox* combo = (CComboBox*)mainframe->CDB.GetDlgItem(IDC_PLAYTYPE);
	TCHAR tmp[256];
	combo->GetLBText(combo->GetCurSel(), tmp);
	m_ksf.m_Player = tmp;
	if(m_ksf.m_Player == TEXT("SINGLE"))
		pView->Double = false;
	else
		pView->Double = true;
	pView->Invalidate(FALSE);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnCbnEditchangePlaytype()
{
	// TODO: Add your control notification handler code here
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	CComboBox* combo = (CComboBox*)mainframe->CDB.GetDlgItem(IDC_PLAYTYPE);
	TCHAR tmp[256];
	combo->GetWindowText(tmp, 256);
	m_ksf.m_Player = tmp;
	if(m_ksf.m_Player == TEXT("SINGLE"))
		pView->Double = false;
	else
		pView->Double = true;
	pView->Invalidate(FALSE);
	SetModifiedFlag(TRUE);
}

void CKSFCreator2Doc::OnStepRotation()
{
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	int s, e;
	s = pView->BeginSel;
	e = pView->EndSel;
	if(s>e)
	{
		int t = s;
		s = e;
		e = t;
	}
	Rotation rot;
	rot.rangeS = s;
	rot.rangeE = e;
	rot.pDoc = this;
	if(pView->Double)
		rot.defaultSingle = false;
	else
		rot.defaultSingle = true;
	rot.DoModal();
	
	pView->Invalidate(FALSE);
	
}
void CKSFCreator2Doc::OnEditCopy()
{
	// TODO: Add your command handler code here

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	int s, e;
	s = pView->BeginSel;
	e = pView->EndSel;
	if(s>e)
	{
		int t = s;
		s = e;
		e = t;
	}
	//변속 iterator
	map<int, vector<tstring> >::const_iterator cop = m_ksf.getChangeOfSpeed().begin();
	//TCHAR data[50000] = {0,};
	tstring data;
	// 스텝 파일 검색
	for(int i=s; i<=e; i++) 
	{
		// 해당 자리에 변속이 있으면
		if(cop != m_ksf.getChangeOfSpeed().end() && cop->first == i) 
		{
			//변속 내용 쓰기
			for(size_t j=0; j<cop->second.size(); j++)
			{
				data += cop->second[j];
				data += TEXT("\r\n");
			}
			cop++;
		}
		data += m_ksf.getStepInfo()[i];
		data += TEXT("\r\n");
	}
	HGLOBAL hResult = GlobalAlloc(GHND/*|GMEM_DDESHARE*/, sizeof(TCHAR)*(data.size()+1));
	TCHAR* lptstrCopy = (TCHAR*)GlobalLock(hResult);
	_tcscpy(lptstrCopy, data.c_str());
	GlobalUnlock(hResult);

	OpenClipboard(NULL);
	EmptyClipboard();
#ifdef _UNICODE
	SetClipboardData(CF_UNICODETEXT, hResult);
#else
	SetClipboardData(CF_TEXT, hResult);
#endif
	
	CloseClipboard();
	
	
	
}



void CKSFCreator2Doc::OnEditPaste()
{
	// TODO: Add your command handler code here
	OpenClipboard(NULL);
#ifdef _UNICODE
	HGLOBAL hResult = GetClipboardData(CF_UNICODETEXT);
#else
	HGLOBAL hResult = GetClipboardData(CF_TEXT);
#endif
	TCHAR* data = (TCHAR*)GlobalLock(hResult);
	CloseClipboard();
	tmatch results;
	tregex expression;
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	expression = TEXT("(\\r\\n)*(^([014]{13}|\\|[BTDE](\\d+\\.?\\d+|\\d+)\\||^#(BPM|TICKCOUNT|DELAY|DELAYBEAT):(\\d+\\.?\\d+|\\d+);)(\\r\\n)*)+");
	if(regex_match(data, expression))
	{
		pView->EndSel = m_ksf.InputTextInfo(data, pView->EndSel);
		pView->BeginSel = pView->EndSel;
		SetModifiedFlag(TRUE);
		
		pView->SetScroll();
		pView->Invalidate(FALSE);
	}
	else
	{
		pView->MessageBox(TEXT("붙여넣을 수 없습니다."));
	}	
}

void CKSFCreator2Doc::OnEditCut()
{
	// TODO: Add your command handler code here
	OnEditCopy();
	OnRemovestep();
}

void CKSFCreator2Doc::OnEditUndo()
{
	// TODO: Add your command handler code here
	m_ksf.setStepData(m_ksf.unredo.unDo());

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	
	if(pView->EndSel > m_ksf.getStepInfo().size()-1)
		pView->EndSel = m_ksf.getStepInfo().size()-1;
	pView->BeginSel = pView->EndSel;
	SetModifiedFlag(TRUE);

	pView->SetScroll();
	pView->Invalidate(FALSE);
}

void CKSFCreator2Doc::OnEditRedo()
{
	// TODO: Add your command handler code here
	m_ksf.setStepData(m_ksf.unredo.reDo());

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	if(pView->EndSel > m_ksf.getStepInfo().size()-1)
		pView->EndSel = m_ksf.getStepInfo().size()-1;
	pView->BeginSel = pView->EndSel;
	SetModifiedFlag(TRUE);
	
	pView->SetScroll();
	pView->Invalidate(FALSE);
}


void CKSFCreator2Doc::OnSpacesetting()
{
	// TODO: Add your command handler code here

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	int s, e;
	s = pView->BeginSel;
	e = pView->EndSel;
	if(s>e)
	{
		int t = s;
		s = e;
		e = t;
	}
	SpaceSetting rot;
	rot.rangeS = s;
	rot.rangeE = e;
	rot.pDoc = this;
	rot.Double = pView->Double;
	
	rot.DoModal();
	

	pView->makewhite();
	pView->SetScroll();
	pView->Invalidate(FALSE);

}

void CKSFCreator2Doc::OnBnClickedSearchsongfile()
{
	// TODO: Add your control notification handler code here

	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER, 
		TEXT("모든파일 (*.*)|*.*||"));

	dlg.m_ofn.lpstrInitialDir = (const TCHAR*)GetPathName();
	dlg.DoModal();

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	::SetDlgItemText(mainframe->CDB.m_hWnd, IDC_SONGFILE, dlg.GetFileName().GetBuffer());
}

void CKSFCreator2Doc::OnBnClickedSearchintrofile()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER, 
		TEXT("모든파일 (*.*)|*.*||"));
	dlg.m_ofn.lpstrInitialDir = (const TCHAR*)GetPathName();
	dlg.DoModal();

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	::SetDlgItemText(mainframe->CDB.m_hWnd, IDC_INTROFILE, dlg.GetFileName().GetBuffer());
}

void CKSFCreator2Doc::OnBnClickedSearchidiscfile()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER, 
		TEXT("모든파일 (*.*)|*.*||"));
	dlg.m_ofn.lpstrInitialDir = (const TCHAR*)GetPathName();
	dlg.DoModal();

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	::SetDlgItemText(mainframe->CDB.m_hWnd, IDC_DISCFILE, dlg.GetFileName().GetBuffer());
}

void CKSFCreator2Doc::OnBnClickedSearchtitlefile()
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE, NULL, NULL, OFN_EXPLORER, 
		TEXT("모든파일 (*.*)|*.*||"));
	dlg.m_ofn.lpstrInitialDir = (const TCHAR*)GetPathName();
	dlg.DoModal();

	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	CChildFrame* mainframe = (CChildFrame*)pView->GetParentFrame();
	::SetDlgItemText(mainframe->CDB.m_hWnd, IDC_TITLEFILE, dlg.GetFileName().GetBuffer());
}

void CKSFCreator2Doc::OnInsertspeed()
{
	// TODO: Add your command handler code here
	POSITION pos = GetFirstViewPosition();
	CKSFCreator2View* pView = (CKSFCreator2View*)GetNextView(pos);
	unsigned int dbsel = pView->EndSel;

	CosDlg cd;
	cd.steppos = dbsel;
	cd.pDoc = this;
	cd.DoModal();
	pView->Invalidate(FALSE);
}
