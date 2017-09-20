// PrintScaleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Maze.h"
#include "PrintScaleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPrintScaleDialog dialog


CPrintScaleDialog::CPrintScaleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintScaleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintScaleDialog)
	m_iPrintScale = 0;
	//}}AFX_DATA_INIT
}


void CPrintScaleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintScaleDialog)
	DDX_Text(pDX, IDC_PRINT_SCALE, m_iPrintScale);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintScaleDialog, CDialog)
	//{{AFX_MSG_MAP(CPrintScaleDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPrintScaleDialog message handlers
