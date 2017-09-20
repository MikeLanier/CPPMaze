#if !defined(AFX_MAZESIZEDIALOG_H__311789C0_030B_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_MAZESIZEDIALOG_H__311789C0_030B_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MazeSizeDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMazeSizeDialog dialog

class CMazeSizeDialog : public CDialog
{
// Construction
public:
	CMazeSizeDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMazeSizeDialog)
	enum { IDD = IDD_MAZE_SIZE };
	int		m_nCols;
	int		m_nRows;
	int		m_CellSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeSizeDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMazeSizeDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZESIZEDIALOG_H__311789C0_030B_11D3_ADF5_0060972D9D32__INCLUDED_)
