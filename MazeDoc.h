// MazeDoc.h : interface of the CMazeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZEDOC_H__58AF2EDA_02F3_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_MAZEDOC_H__58AF2EDA_02F3_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CMaze.h"


class CMazeDoc : public CDocument
{
protected: // create from serialization only
	CMazeDoc();
	DECLARE_DYNCREATE(CMazeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	CMaze m_Maze;
	virtual ~CMazeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMazeDoc)
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEDOC_H__58AF2EDA_02F3_11D3_ADF5_0060972D9D32__INCLUDED_)
