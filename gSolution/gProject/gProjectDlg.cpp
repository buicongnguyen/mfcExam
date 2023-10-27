
// gProjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gProject.h"
#include "gProjectDlg.h"
#include "afxdialogex.h"

#include<iostream>

using namespace std; 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CgProjectDlg dialog



CgProjectDlg::CgProjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_GPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CgProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CgProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_TEST, &CgProjectDlg::OnBnClickedBtnTest)
END_MESSAGE_MAP()


// CgProjectDlg message handlers

BOOL CgProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	MoveWindow(0, 0, 1280, 800); // Main dialog set at 0, 0, size 1280x800 

	m_pDlgImage = new CDlgImage; // init --> need to add delete later. 
	m_pDlgImage->Create(IDD_DLGIMAGE, this); // id, windows 
	m_pDlgImage->ShowWindow(SW_SHOW); // show the dialog 
	// move dlgImage dialog to left place 
	m_pDlgImage->MoveWindow(0, 0, 640, 480);

	m_pDlgImgResult = new CDlgImage; // init --> need to add delete later. 
	m_pDlgImgResult->Create(IDD_DLGIMAGE, this); // id, windows type as IDD_DLGIMAGE
	m_pDlgImgResult->ShowWindow(SW_SHOW); // show the dialog 
	// move 2nd dialog to the right side: 
	m_pDlgImgResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CgProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CgProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CgProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CgProjectDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	if (m_pDlgImage)
		delete m_pDlgImage;
	if (m_pDlgImgResult)
		delete m_pDlgImgResult;
}

void CgProjectDlg::callFunc(int n) {
	int nData = n; 
	std::cout << n << std::endl; 
}

void CgProjectDlg::OnBnClickedBtnTest()
{
	// TODO: Add your control notification handler code here
	unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits(); // need unsigned char to access image data 
	int nWidth = m_pDlgImage->m_image.GetWidth();
	int nHeight = m_pDlgImage->m_image.GetHeight();;
	int nPitch = m_pDlgImage->m_image.GetPitch();;

	memset(fm, 0, sizeof(unsigned char) * nWidth * nHeight);
	//memset(fm, 0xff, nWidth * nHeight);
	for (int k = 0; k < MAX_POINT; k++) {
		int x = rand() % nWidth; 
		int y = rand() % nHeight; 
		fm[y*nPitch + x] = rand()%0xff; 
	}
	//m_pDlgImage->Invalidate(); 
	//memset(fm, 0xff, sizeof(unsigned char) * nWidth * nHeight);

	m_pDlgImgResult->m_nDataCount = 0;
	int nIndex = 0; 
	int nTh = 100; 
	
	
	for (int j = 0; j < nHeight; j++) {
		for (int i = 0; i < nWidth; i++) {
			if (fm[j*nPitch + i] >nTh) {	// if left frame = 0 
				//cout << nSum << ":" << i << "," << j <<  endl;
				//nSum++;
				// save the random point to m_ptData 
				// size = 100, cannot save more than 100 
				if (m_pDlgImgResult->m_nDataCount <MAX_POINT){
					cout << nIndex << ":" << i << "," << j << endl;
					m_pDlgImgResult->m_ptData[nIndex].x = i; 
					m_pDlgImgResult->m_ptData[nIndex].y = j;
					m_pDlgImgResult->m_nDataCount = ++nIndex; // plus nIndex first 
				}
			}
		}
	}
	
	m_pDlgImage->Invalidate();
	m_pDlgImgResult->Invalidate();

	//cout << nSum << endl; 
}
