// MazeSizeDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Maze.h"
#include "MazeSizeDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMazeSizeDialog dialog


CMazeSizeDialog::CMazeSizeDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CMazeSizeDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMazeSizeDialog)
	m_nCols = 0;
	m_nRows = 0;
	m_CellSize = 0;
	//}}AFX_DATA_INIT
}


void CMazeSizeDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMazeSizeDialog)
	DDX_Text(pDX, IDC_NUM_COLS, m_nCols);
	DDX_Text(pDX, IDC_NUM_ROWS, m_nRows);
	DDX_Text(pDX, IDC_CELL_SIZE, m_CellSize);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMazeSizeDialog, CDialog)
	//{{AFX_MSG_MAP(CMazeSizeDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeSizeDialog message handlers
