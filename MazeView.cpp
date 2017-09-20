// MazeView.cpp : implementation of the CMazeView class
//

#include "stdafx.h"
#include "Maze.h"

#include "MazeDoc.h"
#include "MazeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMazeView

IMPLEMENT_DYNCREATE(CMazeView, CView)

BEGIN_MESSAGE_MAP(CMazeView, CView)
	//{{AFX_MSG_MAP(CMazeView)
	ON_COMMAND(ID_FILE_PRINT_SCALE, OnFilePrintScale)
	ON_COMMAND(ID_OPTIONS_SIZE, OnOptionsSize)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(ID_OPTIONS_2D, OnOptions2d)
	ON_COMMAND(ID_OPTIONS_3D, OnOptions3d)
	ON_COMMAND(ID_SOLVE, OnSolve)
	ON_COMMAND(ID_OPTIONS_CLEAR, OnOptionsClear)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeView construction/destruction

CMazeView::CMazeView()
{
	m_bPrinting = FALSE;
	m_iPrintScale = 7;
	m_b3D = FALSE;
	m_b3D = FALSE;
}

CMazeView::~CMazeView()
{
}

BOOL CMazeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMazeView drawing

void CMazeView::OnDraw(CDC* pDC)
{
	CMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	/*
	int	origCellSize = pDoc->m_Maze.CellSize();
	if( m_bPrinting )
		pDoc->m_Maze.CellSize( origCellSize * m_iPrintScale );

	if( m_b3D )
		pDoc->m_Maze.Display3D( pDC, m_b2D );
	else
		pDoc->m_Maze.Display( pDC );

	if( m_bPrinting )
		pDoc->m_Maze.CellSize( origCellSize );
	*/

	if( m_bPrinting )
		pDoc->m_Maze.Print( pDC, m_iPrintScale );

	else
	if( m_b3D )
		pDoc->m_Maze.Display3D( pDC, m_b2D );

	else
		pDoc->m_Maze.Display( pDC );
}

/////////////////////////////////////////////////////////////////////////////
// CMazeView printing

BOOL CMazeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMazeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	m_bPrinting = TRUE;
}

void CMazeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	m_bPrinting = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CMazeView diagnostics

#ifdef _DEBUG
void CMazeView::AssertValid() const
{
	CView::AssertValid();
}

void CMazeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMazeDoc* CMazeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMazeDoc)));
	return (CMazeDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMazeView message handlers

#include "PrintScaleDialog.h"

void CMazeView::OnFilePrintScale() 
{
	CPrintScaleDialog	dlg;

	dlg.m_iPrintScale = m_iPrintScale;
	if( dlg.DoModal() == IDOK )
	{
		m_iPrintScale = dlg.m_iPrintScale;
	}
}

#include "MazeSizeDialog.h"

void CMazeView::OnOptionsSize() 
{
	CMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CMazeSizeDialog	dlg;

	dlg.m_nCols = pDoc->m_Maze.Col();
	dlg.m_nRows = pDoc->m_Maze.Row();
	dlg.m_CellSize = pDoc->m_Maze.CellSize();

	if( dlg.DoModal() == IDOK )
	{
		pDoc->m_Maze.Col( dlg.m_nCols );
		pDoc->m_Maze.Row( dlg.m_nRows );
		pDoc->m_Maze.CellSize( dlg.m_CellSize );
		pDoc->m_Maze.Initialize();
		pDoc->m_Maze.Build( GetDC() );
		Invalidate();
	}	
	
}

static BOOL	bKeyDown = FALSE;

void CMazeView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if( bKeyDown ) return;
	bKeyDown = TRUE;

	CMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	switch( nChar )
	{
	case 38:	// forward
		pDoc->m_Maze.MoveForward( GetDC() );
		if( m_b3D ) Invalidate();
		break;

	case 40:	// backward
		pDoc->m_Maze.MoveBackward( GetDC() );
		if( m_b3D ) Invalidate();
		break;

	case 39:	// right
		pDoc->m_Maze.TurnRight( GetDC() );
		if( m_b3D ) Invalidate();
		break;

	case 37:	// left
		pDoc->m_Maze.TurnLeft( GetDC() );
		if( m_b3D ) Invalidate();
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMazeView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	bKeyDown = FALSE;
	
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CMazeView::OnOptions2d() 
{
	if( m_b2D )
		m_b2D = FALSE;
	else
		m_b2D = TRUE;

	Invalidate();
}

void CMazeView::OnOptions3d() 
{
	if( m_b3D )
		m_b3D = FALSE;
	else
		m_b3D = TRUE;

	Invalidate();
}

void CMazeView::OnSolve() 
{
	CMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_Maze.Solve( GetDC() );
}

void CMazeView::OnOptionsClear() 
{
	CMazeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->m_Maze.Clear();
	Invalidate();
}
