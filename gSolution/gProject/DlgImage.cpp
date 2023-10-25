// DlgImage.cpp : implementation file
//

#include "stdafx.h"
#include "gProject.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage dialog

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{
	m_pParent = pParent; 
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BTN_UP_PARENT, &CDlgImage::OnBnClickedBtnUpParent)
END_MESSAGE_MAP()


// CDlgImage message handlers
#include "gProjectDlg.h"

void CDlgImage::OnBnClickedBtnUpParent()
{
	// TODO: Add your control notification handler code here
	static int n = 100; 
	// call to parent dialog 
	CgProjectDlg *pDlg = (CgProjectDlg*)m_pParent; 
	pDlg->callFunc(n++);
}
