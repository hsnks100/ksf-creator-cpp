// Rotation.cpp : implementation file
//

#include "stdafx.h"
#include "KSF Creator2.h"
#include "Rotation.h"


// Rotation dialog

IMPLEMENT_DYNAMIC(Rotation, CDialog)

Rotation::Rotation(CWnd* pParent /*=NULL*/)
	: CDialog(Rotation::IDD, pParent)
{
	defaultSingle = true;
}

Rotation::~Rotation()
{
}

void Rotation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Rotation, CDialog)
//	ON_COMMAND(ID_STEPROTATION, &Rotation::OnSteprotation)
ON_BN_CLICKED(IDOK, &Rotation::OnBnClickedOk)
ON_BN_CLICKED(IDC_HORI, &Rotation::OnBnClickedHori)
ON_BN_CLICKED(IDC_DOUBLE, &Rotation::OnBnClickedDouble)
ON_BN_CLICKED(IDC_1P, &Rotation::OnBnClicked1p)
ON_BN_CLICKED(IDC_2P, &Rotation::OnBnClicked2p)
END_MESSAGE_MAP()


// Rotation message handlers

//void Rotation::OnSteprotation()
//{
//	// TODO: Add your command handler code here
//}

BOOL Rotation::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	HWND hWnd;
	if(defaultSingle)
	{
		GetDlgItem(IDC_1P, &hWnd);
		::SendMessage(hWnd, BM_SETCHECK, BST_CHECKED, 0);
	}
	else
	{
		GetDlgItem(IDC_DOUBLE, &hWnd);
		::SendMessage(hWnd, BM_SETCHECK, BST_CHECKED, 0);

		GetDlgItem(IDC_PLUS90, &hWnd);
		::EnableWindow(hWnd, FALSE);
		GetDlgItem(IDC_MINUS90, &hWnd);
		::EnableWindow(hWnd, FALSE);
		//GetDlgItem(IDC_2P, &hWnd);
		//::SendMessage(hWnd, BM_SETCHECK, BST_CHECKED, 0);
	}

	GetDlgItem(IDC_HORI, &hWnd);
	::SendMessage(hWnd, BM_SETCHECK, BST_CHECKED, 0);

	//CheckRadioButton(
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void Rotation::OnBnClickedOk()
{
	int player=0;
	if(GetChecked(IDC_1P)) player = 0;
	else if(GetChecked(IDC_2P)) player = 1;
	else if(GetChecked(IDC_DOUBLE)) player = 2;
	
	int rotation=0;
	if(GetChecked(IDC_HORI)) rotation = 0;
	else if(GetChecked(IDC_VERT)) rotation = 1;
	else if(GetChecked(IDC_PLUS90)) rotation = 2;
	else if(GetChecked(IDC_MINUS90)) rotation = 3;
	else if(GetChecked(IDC_MIRROR)) rotation = 4;
	pDoc->m_ksf.Rotation(player, rotation, rangeS, rangeE);
	pDoc->SetModifiedFlag(TRUE);
	// TODO: Add your control notification handler code here
	OnOK();
}

bool Rotation::GetChecked(int id)
{
	HWND hWnd;
	GetDlgItem(id, &hWnd);
	if (::SendMessage(hWnd,BM_GETCHECK,0,0)==BST_CHECKED)
		return true;
	else
		return false;
}
void Rotation::OnBnClickedHori()
{
	// TODO: Add your control notification handler code here
}

void Rotation::OnBnClickedDouble()
{
	// TODO: Add your control notification handler code here
	HWND hWnd;
	GetDlgItem(IDC_PLUS90, &hWnd);
	::EnableWindow(hWnd, FALSE);
	GetDlgItem(IDC_MINUS90, &hWnd);
	::EnableWindow(hWnd, FALSE);

	if(GetChecked(IDC_PLUS90) || GetChecked(IDC_MINUS90))
	{
		GetDlgItem(IDC_HORI, &hWnd);
		::SendMessage(hWnd, BM_SETCHECK, BST_CHECKED, 0);

		GetDlgItem(IDC_PLUS90, &hWnd);
		::SendMessage(hWnd, BM_SETCHECK, BST_UNCHECKED, 0);

		GetDlgItem(IDC_MINUS90, &hWnd);
		::SendMessage(hWnd, BM_SETCHECK, BST_UNCHECKED, 0);
	}
}

void Rotation::OnBnClicked1p()
{
	// TODO: Add your control notification handler code here
	HWND hWnd;
	GetDlgItem(IDC_PLUS90, &hWnd);
	::EnableWindow(hWnd, TRUE);
	GetDlgItem(IDC_MINUS90, &hWnd);
	::EnableWindow(hWnd, TRUE);
}

void Rotation::OnBnClicked2p()
{
	// TODO: Add your control notification handler code here
	HWND hWnd;
	GetDlgItem(IDC_PLUS90, &hWnd);
	::EnableWindow(hWnd, TRUE);
	GetDlgItem(IDC_MINUS90, &hWnd);
	::EnableWindow(hWnd, TRUE);
}
