// MazeView.h : interface of the CMazeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZEVIEW_H__C7EAA8AC_0320_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_MAZEVIEW_H__C7EAA8AC_0320_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMazeView : public CView
{
private:
	BOOL	m_b3D;
	BOOL	m_b2D;
	BOOL	m_bPrinting;
	int		m_iPrintScale;

protected: // create from serialization only
	CMazeView();
	DECLARE_DYNCREATE(CMazeView)

// Attributes
public:
	CMazeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMazeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMazeView)
	afx_msg void OnFilePrintScale();
	afx_msg void OnOptionsSize();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnOptions2d();
	afx_msg void OnOptions3d();
	afx_msg void OnSolve();
	afx_msg void OnOptionsClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MazeView.cpp
inline CMazeDoc* CMazeView::GetDocument()
   { return (CMazeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEVIEW_H__C7EAA8AC_0320_11D3_ADF5_0060972D9D32__INCLUDED_)
