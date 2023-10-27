#pragma once

#define MAX_POINT 100000
// CDlgImage dialog

class CDlgImage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgImage)

public:
	CDlgImage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgImage();

	CImage m_image; 
	CWnd* m_pParent; // CWindow : parent 

	int m_nDataCount = 0; 
	CPoint m_ptData[MAX_POINT];
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLGIMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnUpParent();
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
private: 
	void InitImage();
	void drawData(CDC* pDC); 
};
