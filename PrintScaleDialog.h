#if !defined(AFX_PRINTSCALEDIALOG_H__77AE8541_0322_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_PRINTSCALEDIALOG_H__77AE8541_0322_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintScaleDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPrintScaleDialog dialog

class CPrintScaleDialog : public CDialog
{
// Construction
public:
	CPrintScaleDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPrintScaleDialog)
	enum { IDD = IDD_PRINT_SCALE };
	int		m_iPrintScale;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintScaleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintScaleDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTSCALEDIALOG_H__77AE8541_0322_11D3_ADF5_0060972D9D32__INCLUDED_)
