// Maze.cpp: implementation of the CMaze class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Maze.h"
#include "CMaze.h"

#include "Point3D.h"

/*
#include "Logfile.h"
static LOGfile	log( "d:\\mike\\maze\\maze.log" );
*/

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMaze::CMaze()
{
	m_nCol = 20;
	m_nRow = 10;
	m_CellSize = 15;
	m_pGrid = NULL;

	time_t	t;
	srand( int(time(&t)) );

	m_BlackPen = CreatePen( PS_SOLID, 1, RGB(0,0,0) );
	m_RedPen   = CreatePen( PS_SOLID, 1, RGB(255,0,0) );
	m_YellowPen   = CreatePen( PS_SOLID, 1, RGB(255,255,0) );
	m_WhitePen = CreatePen( PS_SOLID, 1, RGB(255,255,255) );
	m_GreenPen = CreatePen( PS_SOLID, 1, RGB(0,255,0) );
	m_GreyPen = CreatePen( PS_SOLID, 1, RGB(200,200,200) );

	m_RedBrush = CreateSolidBrush( RGB(255,0,0) );
	m_YellowBrush = CreateSolidBrush( RGB(255,255,0) );
	m_WhiteBrush = CreateSolidBrush( RGB(255,255,255) );
	m_GreenBrush = CreateSolidBrush( RGB(0,255,0) );
	m_GreyBrush = CreateSolidBrush( RGB(200,200,200) );
	m_GreyWallBrush = CreateSolidBrush( RGB(180,180,180) );
	m_GreyBackBrush = CreateSolidBrush( RGB(230,230,230) );
	m_SkyBlueBrush = CreateSolidBrush( RGB(127,127,255) );

	m_currentRow = 0;
	m_currentCol = 0;
	m_currentDirection = EAST;

	m_scale = 1.0;
}

CMaze::~CMaze()
{
}

//////////////////////////////////////////////////////////////////////
// 2D Display Functions
//////////////////////////////////////////////////////////////////////

void CMaze::DisplayCell(CDC *pDC, int row, int col)
{
	if( pDC == NULL ) return;

	// compute the x,y coordinate of the upper right of the cell
	int	x = 10 + col*m_CellSize;
	int	y = 10 + row*m_CellSize;

	// display the cell background

	if( CellMarked( row, col, FINISH_CELL ) )
	{
		pDC->SelectObject( m_YellowBrush );
		pDC->SelectObject( m_YellowPen );
	}
	else
	if( CellMarked( row, col, BACKTRACKED_CELL ) )
	{
		pDC->SelectObject( m_GreyBrush );
		pDC->SelectObject( m_GreyPen );
	}
	else
	if( CellMarked( row, col, TRACKED_CELL ) )
	{
		pDC->SelectObject( m_GreenBrush );
		pDC->SelectObject( m_GreenPen );
	}
	else
	{
		pDC->SelectObject( m_WhiteBrush );
		pDC->SelectObject( m_WhitePen );
	}

	CRect	rect( x, y, x+m_CellSize+1, y+m_CellSize+1 );
	pDC->Rectangle( &rect );

	pDC->SelectObject( m_WhiteBrush );
	pDC->SelectObject( m_WhitePen );

	// draw the cell
	if( !WestWallOpen( row,col ) )
	{
		pDC->SelectObject( m_BlackPen );
		pDC->MoveTo( x, y );
		pDC->LineTo( x, y+m_CellSize );
	}
	else
	{
		pDC->SelectObject( m_WhitePen );
		pDC->MoveTo( x, y+1 );
		pDC->LineTo( x, y-1+m_CellSize );
	}


	if( !EastWallOpen( row,col ) )
	{
		pDC->SelectObject( m_BlackPen );
		pDC->MoveTo( x+m_CellSize, y );
		pDC->LineTo( x+m_CellSize, y+m_CellSize );
	}
	else
	{
		pDC->SelectObject( m_WhitePen );
		pDC->MoveTo( x+m_CellSize, y+1 );
		pDC->LineTo( x+m_CellSize, y-1+m_CellSize );
	}


	if( !NorthWallOpen( row,col ) )
	{
		pDC->SelectObject( m_BlackPen );
		pDC->MoveTo( x, y );
		pDC->LineTo( x+m_CellSize, y );
	}
	else
	{
		pDC->SelectObject( m_WhitePen );
		pDC->MoveTo( x+1, y );
		pDC->LineTo( x-1+m_CellSize, y );
	}


	if( !SouthWallOpen( row,col ) )
	{
		pDC->SelectObject( m_BlackPen );
		pDC->MoveTo( x, y+m_CellSize );
		pDC->LineTo( x+m_CellSize, y+m_CellSize );
	}
	else
	{
		pDC->SelectObject( m_WhitePen );
		pDC->MoveTo( x+1, y+m_CellSize );
		pDC->LineTo( x-1+m_CellSize, y+m_CellSize );
	}

} // DisplayCell

void CMaze::DisplayCarrot( CDC* pDC, BOOL bErase )
{
	CPoint	p[3];

	// compute the x,y coordinate of the upper right of the cell
	int x = 10 + m_currentCol * m_CellSize;
	int y = 10 + m_currentRow * m_CellSize;

	// select white for erase and red for draw
	if( bErase )
	{
		pDC->SelectObject( m_WhitePen );
		pDC->SelectObject( m_WhiteBrush );
	}
	else
	{
		pDC->SelectObject( m_RedPen );
		pDC->SelectObject( m_RedBrush );
	}

	// draw dependent on direction
	switch( m_currentDirection )
	{
	case WEST:
		p[0] = CPoint( x+(m_CellSize/4), y+(m_CellSize/2) );
		p[1] = CPoint( p[0].x + (m_CellSize/2), y+(m_CellSize/4) );
		p[2] = CPoint( p[0].x + (m_CellSize/2), p[1].y + (m_CellSize/2) );
		break;

	case EAST:
		p[0] = CPoint( x+(m_CellSize/4), y+(m_CellSize/4) );
		p[1] = CPoint( p[0].x, p[0].y + (m_CellSize/2) );
		p[2] = CPoint( p[0].x + (m_CellSize/2), y+(m_CellSize/2) );
		break;

	case NORTH:
		p[0] = CPoint( x+(m_CellSize/2), y+(m_CellSize/4) );
		p[1] = CPoint( x+(m_CellSize/4), p[0].y+(m_CellSize/2) );
		p[2] = CPoint( p[1].x+(m_CellSize/2), p[0].y+(m_CellSize/2) );
		break;

	case SOUTH:
		p[0] = CPoint( x+(m_CellSize/4), y+(m_CellSize/4) );
		p[1] = CPoint( p[0].x+(m_CellSize/2), y+(m_CellSize/4) );
		p[2] = CPoint( x+(m_CellSize/2), p[1].y+(m_CellSize/2) );
		break;
	}

	pDC->Polygon( p, 3 );

} // DisplayCarrot

void CMaze::DisplaySolved( CDC* pDC )
{
	pDC->SelectObject( m_BlackPen );
	pDC->SelectObject( m_WhiteBrush );

	CRect	rect;
	pDC->GetWindow()->GetWindowRect( &rect );

	CRect	rect2(	(rect.right-rect.left)/2 - 200, (rect.bottom-rect.top)/2 - 100,
					(rect.right-rect.left)/2 + 200, (rect.bottom-rect.top)/2 + 100 );

	pDC->Rectangle( &rect2 );

	LOGFONT  font;

	font.lfHeight = (int)(rect.bottom-rect.top)/4;
	font.lfWidth = 0;
	font.lfEscapement = 0;
	font.lfOrientation = 0;
	font.lfWeight = 400;
	font.lfItalic = FALSE;
	font.lfUnderline = FALSE;
	font.lfStrikeOut = FALSE;
	font.lfCharSet = ANSI_CHARSET;
	font.lfOutPrecision = OUT_DEFAULT_PRECIS;
	font.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	font.lfQuality = DEFAULT_QUALITY;
	font.lfPitchAndFamily = DEFAULT_PITCH | FF_SWISS;
	font.lfFaceName[0] = 0;

	HFONT hFont = CreateFontIndirect( &font );

	HFONT hOldFont = (HFONT)pDC->SelectObject( hFont );

	pDC->SetBkMode( TRANSPARENT );
	pDC->SetTextColor( RGB( 0,0,0 ) );
	pDC->TextOut( rect2.left+2, rect2.top+20, "Solved" );
	pDC->SetTextColor( RGB( 255,0,0 ) );
	pDC->TextOut( rect2.left+4, rect2.top+22, "Solved" );

	pDC->SelectObject( hOldFont );
}

void CMaze::Display(CDC *pDC)
{
	if( pDC == NULL ) return;

	int	row, col;

	int origCellSize = CellSize();
	CellSize( (int)(origCellSize * m_scale) );

	// Draw maze
	for( row=0; row<m_nRow; row++ )
		for( col=0; col<m_nCol; col++ )
		{
			DisplayCell( pDC, row, col );
		}

	DisplayCarrot( pDC, FALSE );

	CellSize( origCellSize );

} // Display

//////////////////////////////////////////////////////////////////////
// 3D Display Functions
//////////////////////////////////////////////////////////////////////

#define	BACK	0
#define	LEFT	1
#define	RIGHT	2
#define	FRONT	3
#define	TOP		4
#define	BOTTOM	5

static void	ClipEdge( CPoint* edge, CRect clipRect )
{
	CPoint	p;

	if( edge[0].x < clipRect.left && edge[1].x < clipRect.left )
	{
		edge[0].x = clipRect.left;
		edge[1].x = clipRect.left;

		if( edge[0].y < clipRect.top ) edge[0].y = clipRect.top;
		if( edge[1].y < clipRect.top ) edge[1].y = clipRect.top;

		if( edge[0].y > clipRect.bottom ) edge[0].y = clipRect.bottom;
		if( edge[1].y > clipRect.bottom ) edge[1].y = clipRect.bottom;
	}

	if( edge[0].x > clipRect.right && edge[1].x > clipRect.right )
	{
		edge[0].x = clipRect.right;
		edge[1].x = clipRect.right;

		if( edge[0].y < clipRect.top ) edge[0].y = clipRect.top;
		if( edge[1].y < clipRect.top ) edge[1].y = clipRect.top;

		if( edge[0].y > clipRect.bottom ) edge[0].y = clipRect.bottom;
		if( edge[1].y > clipRect.bottom ) edge[1].y = clipRect.bottom;
	}


	if( edge[0].x < clipRect.left )
	{
		p.x = clipRect.left;
		p.y = edge[1].y - (long)((double)(edge[1].y - edge[0].y) * (double)(edge[1].x - p.x) / (double)(edge[1].x - edge[0].x));

		edge[0] = p;
	}

	if( edge[1].x < clipRect.left )
	{
		p.x = clipRect.left;
		p.y = edge[0].y - (long)((double)(edge[0].y - edge[1].y) * (double)(edge[0].x - p.x) / (double)(edge[0].x - edge[1].x));

		edge[1] = p;
	}

	if( edge[0].x > clipRect.right )
	{
		p.x = clipRect.right;
		p.y = edge[1].y - (long)((double)(edge[1].y - edge[0].y) * (double)(edge[1].x - p.x) / (double)(edge[1].x - edge[0].x));

		edge[0] = p;
	}

	if( edge[1].x > clipRect.right )
	{
		p.x = clipRect.right;
		p.y = edge[0].y - (long)((double)(edge[0].y - edge[1].y) * (double)(edge[0].x - p.x) / (double)(edge[0].x - edge[1].x));

		edge[1] = p;
	}


	if( edge[0].y < clipRect.top )
	{
		p.y = clipRect.top;
		p.x = edge[1].x - (long)((double)(edge[1].x - edge[0].x) * (double)(edge[1].y - p.y) / (double)(edge[1].y - edge[0].y));

		edge[0] = p;
	}

	if( edge[1].y < clipRect.top )
	{
		p.y = clipRect.top;
		p.x = edge[0].x - (long)((double)(edge[0].x - edge[1].x) * (double)(edge[0].y - p.y) / (double)(edge[0].y - edge[1].y));

		edge[1] = p;
	}

	if( edge[0].y > clipRect.bottom )
	{
		p.y = clipRect.bottom;
		p.x = edge[1].x - (long)((double)(edge[1].x - edge[0].x) * (double)(edge[1].y - p.y) / (double)(edge[1].y - edge[0].y));

		edge[0] = p;
	}

	if( edge[1].y > clipRect.bottom )
	{
		p.y = clipRect.bottom;
		p.x = edge[0].x - (long)((double)(edge[0].x - edge[1].x) * (double)(edge[0].y - p.y) / (double)(edge[0].y - edge[1].y));

		edge[1] = p;
	}
}

static void ClipPolygon( CDC* pDC, CPoint* polygon, int npoints, CRect clipRect )
{
	CPoint	edge[4][2];
	CPoint	p[8];

	// collect the edges from the polygon
	edge[0][0] = polygon[0];
	edge[0][1] = polygon[1];

	edge[1][0] = polygon[1];
	edge[1][1] = polygon[2];

	edge[2][0] = polygon[2];
	edge[2][1] = polygon[3];

	edge[3][0] = polygon[3];
	edge[3][1] = polygon[0];

	// clip edges
	ClipEdge( &edge[0][0], clipRect );
	ClipEdge( &edge[1][0], clipRect );
	ClipEdge( &edge[2][0], clipRect );
	ClipEdge( &edge[3][0], clipRect );

	// build new polygon
	int	i=0;
	p[i] = edge[0][0];
	if( edge[0][1] != p[i] ) p[++i] = edge[0][1];
	if( edge[1][0] != p[i] ) p[++i] = edge[1][0];
	if( edge[1][1] != p[i] ) p[++i] = edge[1][1];
	if( edge[2][0] != p[i] ) p[++i] = edge[2][0];
	if( edge[2][1] != p[i] ) p[++i] = edge[2][1];
	if( edge[3][0] != p[i] ) p[++i] = edge[3][0];
	if( edge[3][1] != p[i] ) p[++i] = edge[3][1];

	pDC->Polygon( p, i+1 );

} // ClipPolygon

void CMaze::DisplayWall3D(CDC *pDC, CPoint3D* q, int wall, CRect clipRect )
{
	CPoint	r[4];

	switch( wall )
	{
	case LEFT:
		pDC->SelectObject( m_GreyWallBrush );
		r[0] = CPoint( (int)q[0].m_x, (int)q[0].m_y );
		r[1] = CPoint( (int)q[4].m_x, (int)q[4].m_y );
		r[2] = CPoint( (int)q[6].m_x, (int)q[6].m_y );
		r[3] = CPoint( (int)q[2].m_x, (int)q[2].m_y );
		break;

	case RIGHT:
		pDC->SelectObject( m_GreyWallBrush );
		r[0] = CPoint( (int)q[1].m_x, (int)q[1].m_y );
		r[1] = CPoint( (int)q[5].m_x, (int)q[5].m_y );
		r[2] = CPoint( (int)q[7].m_x, (int)q[7].m_y );
		r[3] = CPoint( (int)q[3].m_x, (int)q[3].m_y );
		break;

	case BACK:
		pDC->SelectObject( m_GreyBackBrush );
		r[0] = CPoint( (int)q[4].m_x, (int)q[4].m_y );
		r[1] = CPoint( (int)q[5].m_x, (int)q[5].m_y );
		r[2] = CPoint( (int)q[7].m_x, (int)q[7].m_y );
		r[3] = CPoint( (int)q[6].m_x, (int)q[6].m_y );
		break;

	case FRONT:
		r[0] = CPoint( (int)q[0].m_x, (int)q[0].m_y );
		r[1] = CPoint( (int)q[1].m_x, (int)q[1].m_y );
		r[2] = CPoint( (int)q[3].m_x, (int)q[3].m_y );
		r[3] = CPoint( (int)q[2].m_x, (int)q[2].m_y );
		break;

	case BOTTOM:
		r[0] = CPoint( (int)q[2].m_x, (int)q[2].m_y );
		r[1] = CPoint( (int)q[3].m_x, (int)q[3].m_y );
		r[2] = CPoint( (int)q[7].m_x, (int)q[7].m_y );
		r[3] = CPoint( (int)q[6].m_x, (int)q[6].m_y );
		break;

	case TOP:
		r[0] = CPoint( (int)q[0].m_x, (int)q[0].m_y );
		r[1] = CPoint( (int)q[1].m_x, (int)q[1].m_y );
		r[2] = CPoint( (int)q[5].m_x, (int)q[5].m_y );
		r[3] = CPoint( (int)q[4].m_x, (int)q[4].m_y );
		break;
	}

	//if( Clip( r, 4, clipRect ) )
		//pDC->Polygon( r, 4 );
	ClipPolygon( pDC, r, 4, clipRect );

} // DisplayWall3D

void CMaze::DisplayCell3D(CDC *pDC, int currentRow, int currentCol, int row, int col, int direction)
{
	if( pDC == NULL ) return;

	if( row < 0 || row > m_nRow ) return;
	if( col < 0 || col > m_nCol ) return;

	double	xoff, zoff;
	double	cellWidth = 100.0 * m_scale;
	double  halfCellWidth = cellWidth / 2.0;

	// determine the offset from the current cell to the cell to draw.  x if always right to left
	// and z is always depth, with respect to the location and direction of the viewer.
	switch( direction )
	{
	case EAST:
		xoff = (double)(row - currentRow) * cellWidth - halfCellWidth;
		zoff = (double)(col - currentCol) * cellWidth - halfCellWidth;
		break;

	case SOUTH:
		xoff = (double)(currentCol - col) * cellWidth - halfCellWidth;
		zoff = (double)(row - currentRow) * cellWidth - halfCellWidth;
		break;

	case WEST:
		xoff = (double)(currentRow - row) * cellWidth - halfCellWidth;
		zoff = (double)(currentCol - col) * cellWidth - halfCellWidth;
		break;

	case NORTH:
		xoff = (double)(col - currentCol) * cellWidth - halfCellWidth;
		zoff = (double)(currentRow - row) * cellWidth - halfCellWidth;
		break;

	}

	// compute the coordinates of the cell box.
	CPoint3D	p[8], q[8];

	p[0] = CPoint3D( xoff,           -halfCellWidth, zoff );
	p[1] = CPoint3D( xoff+cellWidth, -halfCellWidth, zoff );
	p[2] = CPoint3D( xoff,            halfCellWidth, zoff );
	p[3] = CPoint3D( xoff+cellWidth,  halfCellWidth, zoff );

	p[4] = CPoint3D( xoff,           -halfCellWidth, zoff+cellWidth );
	p[5] = CPoint3D( xoff+cellWidth, -halfCellWidth, zoff+cellWidth );
	p[6] = CPoint3D( xoff,            halfCellWidth, zoff+cellWidth );
	p[7] = CPoint3D( xoff+cellWidth,  halfCellWidth, zoff+cellWidth );

	double	d = cellWidth * 2;	// perspective depth

	// translate to center of window
	CRect	rect;
	pDC->GetWindow()->GetWindowRect( &rect );
	rect.bottom -= rect.top;	rect.top = 0;
	rect.right -= rect.left;	rect.left = 0;

	for( int i=0; i<8; i++ )
	{
		// apply perspective to point
		if( p[i].m_z > 0.0 )
		{
			q[i].m_x = p[i].m_x * (d / p[i].m_z);
			q[i].m_y = p[i].m_y * (d / p[i].m_z);
		}

		else
		if( p[i].m_z < 0.0 )
		{
			q[i].m_x = p[i].m_x * (-p[i].m_z * d);
			q[i].m_y = p[i].m_y * (-p[i].m_z * d);
		}

		else
		{
			q[i].m_x = p[i].m_x;
			q[i].m_y = p[i].m_y;
		}

		// translate point
		q[i].m_x += (double)((rect.right - rect.left) / 2);
		q[i].m_y += (double)((rect.bottom - rect.top) / 2);
	}

	if( CellMarked( row, col, FINISH_CELL ) )		pDC->SelectObject( m_YellowBrush );	else
	if( CellMarked( row, col, BACKTRACKED_CELL ) )	pDC->SelectObject( m_GreyBrush );	else
	if( CellMarked( row, col, TRACKED_CELL ) )		pDC->SelectObject( m_GreenBrush );	else
													pDC->SelectObject( m_WhiteBrush );

	pDC->SelectObject( m_BlackPen );

	DisplayWall3D( pDC, q, BOTTOM, m_clipRect );

	pDC->SelectObject( m_WhiteBrush );
	pDC->SelectObject( m_BlackPen );

	switch( direction )
	{
	case EAST:
		if( !EastWallOpen( row, col ) ) DisplayWall3D( pDC, q, BACK, m_clipRect );
		if( !NorthWallOpen( row, col ) ) DisplayWall3D( pDC, q, LEFT, m_clipRect );
		if( !SouthWallOpen( row, col ) ) DisplayWall3D( pDC, q, RIGHT, m_clipRect );
		break;

	case WEST:
		if( !WestWallOpen( row, col ) ) DisplayWall3D( pDC, q, BACK, m_clipRect );
		if( !NorthWallOpen( row, col ) ) DisplayWall3D( pDC, q, RIGHT, m_clipRect );
		if( !SouthWallOpen( row, col ) ) DisplayWall3D( pDC, q, LEFT, m_clipRect );
		break;

	case NORTH:
		if( !NorthWallOpen( row, col ) ) DisplayWall3D( pDC, q, BACK, m_clipRect );
		if( !EastWallOpen( row, col ) ) DisplayWall3D( pDC, q, RIGHT, m_clipRect );
		if( !WestWallOpen( row, col ) ) DisplayWall3D( pDC, q, LEFT, m_clipRect );
		break;

	case SOUTH:
		if( !SouthWallOpen( row, col ) ) DisplayWall3D( pDC, q, BACK, m_clipRect );
		if( !EastWallOpen( row, col ) ) DisplayWall3D( pDC, q, LEFT, m_clipRect );
		if( !WestWallOpen( row, col ) ) DisplayWall3D( pDC, q, RIGHT, m_clipRect );
		break;
	}

	//DisplayWall3D( pDC, q, TOP );

} // DisplayCell3D

void CMaze::Display3D(CDC *pDC, BOOL bBoth)
{
	if( pDC == NULL ) return;

	//Draw background
	CRect	windowRect;
	pDC->GetWindow()->GetWindowRect( &windowRect );

	m_scale = (double)(windowRect.bottom - windowRect.top) / 500.0;

	int	depthMax = 5;
	int depth = 0;
	int	width = (windowRect.bottom - windowRect.top)/2;
	m_clipRect = CRect(	(windowRect.right-windowRect.left)/2 - width, 0,
						(windowRect.right-windowRect.left)/2 + width, windowRect.bottom-windowRect.top );

	m_clipRect = CRect( 5, 5, windowRect.right-windowRect.left-10, windowRect.bottom-windowRect.top-10 );

	pDC->SelectObject( m_BlackPen );
	pDC->SelectObject( m_SkyBlueBrush );
	pDC->Rectangle( &m_clipRect );

	width = 2;

	// draw cell
	if( m_currentDirection == EAST )
	{
		depth = m_nCol - m_currentCol - 1;
		if( depth > depthMax ) depth = depthMax;

		for( int i=depth; i>=0; i-- )
		{
			for( int j=width; j>0; j-- )
			{
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow+j, m_currentCol+i, m_currentDirection );
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow-j, m_currentCol+i, m_currentDirection );
			}

			DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow, m_currentCol+i, m_currentDirection );
		}
	}

	else
	if( m_currentDirection == SOUTH )
	{
		depth = m_nRow - m_currentRow - 1;
		if( depth > depthMax ) depth = depthMax;

		for( int i=depth; i>=0; i-- )
		{
			for( int j=width; j>0; j-- )
			{
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow+i, m_currentCol+j, m_currentDirection );
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow+i, m_currentCol-j, m_currentDirection );
			}

			DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow+i, m_currentCol, m_currentDirection );
		}
	}
	else

	if( m_currentDirection == WEST )
	{
		depth = m_currentCol < depthMax ? m_currentCol : depthMax;

		for( int i=depth; i>=0; i-- )
		{
			for( int j=width; j>0; j-- )
			{
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow+j, m_currentCol-i, m_currentDirection );
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow-j, m_currentCol-i, m_currentDirection );
			}

			DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow, m_currentCol-i, m_currentDirection );
		}
	}

	else
	if( m_currentDirection == NORTH )
	{
		depth = m_currentRow < depthMax ? m_currentRow : depthMax;

		for( int i=depth; i>=0; i-- )
		{
			for( int j=width; j>0; j-- )
			{
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow-i, m_currentCol+j, m_currentDirection );
				DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow-i, m_currentCol-j, m_currentDirection );
			}

			DisplayCell3D( pDC, m_currentRow, m_currentCol, m_currentRow-i, m_currentCol, m_currentDirection );
		}
	}

	if( bBoth ) Display( pDC );

} // Display3D

//////////////////////////////////////////////////////////////////////
// Printing Functions
//////////////////////////////////////////////////////////////////////

void CMaze::PrintCell(CDC *pDC, int row, int col)
{
	if( pDC == NULL ) return;

	// compute the x,y coordinate of the upper right of the cell
	int	x = 10 + col*m_CellSize;
	int	y = 10 + row*m_CellSize;

	// draw the cell
	if( !WestWallOpen( row,col ) )
	{
		pDC->MoveTo( x, y );
		pDC->LineTo( x, y+m_CellSize );
	}

	if( !EastWallOpen( row,col ) )
	{
		pDC->MoveTo( x+m_CellSize, y );
		pDC->LineTo( x+m_CellSize, y+m_CellSize );
	}

	if( !NorthWallOpen( row,col ) )
	{
		pDC->MoveTo( x, y );
		pDC->LineTo( x+m_CellSize, y );
	}

	if( !SouthWallOpen( row,col ) )
	{
		pDC->MoveTo( x, y+m_CellSize );
		pDC->LineTo( x+m_CellSize, y+m_CellSize );
	}

} // PrintCell

void CMaze::Print(CDC *pDC, int printScale)
{
	if( pDC == NULL ) return;

	int	row, col;

	int origCellSize = CellSize();
	CellSize( origCellSize * printScale );

	// Draw maze
	for( row=0; row<m_nRow; row++ )
		for( col=0; col<m_nCol; col++ )
		{
			PrintCell( pDC, row, col );
		}

	CellSize( origCellSize );

} // Print

//////////////////////////////////////////////////////////////////////
// Movement Functions
//////////////////////////////////////////////////////////////////////

void CMaze::TurnRight( CDC* pDC )
{
	// erase the carrot in the current direction
	DisplayCarrot( pDC, TRUE );

	// change the direction
	if( m_currentDirection == EAST ) m_currentDirection = SOUTH; else
	if( m_currentDirection == SOUTH ) m_currentDirection = WEST; else
	if( m_currentDirection == WEST ) m_currentDirection = NORTH; else
	if( m_currentDirection == NORTH ) m_currentDirection = EAST;

	// draw the carrot in the new direction
	DisplayCarrot( pDC, FALSE );

} // TurnRight

void CMaze::TurnLeft( CDC* pDC )
{
	// erase the carrot in the current direction
	DisplayCarrot( pDC, TRUE );

	// change the direction
	if( m_currentDirection == EAST ) m_currentDirection = NORTH; else
	if( m_currentDirection == NORTH ) m_currentDirection = WEST; else
	if( m_currentDirection == WEST ) m_currentDirection = SOUTH; else
	if( m_currentDirection == SOUTH ) m_currentDirection = EAST;

	// draw the carrot in the new direction
	DisplayCarrot( pDC, FALSE );

} // TurnLeft

void CMaze::MoveForward( CDC* pDC )
{
	// Move one cell forward in the current direction
	// make sure the wall in that direction is open
	switch( m_currentDirection )
	{
	case EAST:
		if( !EastWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_EAST ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		// erase the old carrot, change the column and draw the new carrot
		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentCol++;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_WEST );

		break;

	case NORTH:
		if( !NorthWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_NORTH ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		// erase the old carrot, change the row and draw the new carrot
		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentRow--;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_SOUTH );

		break;

	case WEST:
		if( !WestWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_WEST ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		// erase the old carrot, change the column and draw the new carrot
		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentCol--;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_EAST );

		break;

	case SOUTH:
		if( !SouthWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_SOUTH ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		// erase the old carrot, change to row and draw the new carrot
		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentRow++;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_NORTH );

		break;
	}

	MarkCell( m_currentRow, m_currentCol, TRACKED_CELL );

	//if( CellMarked( m_currentRow, m_currentCol, FINISH_CELL ) )
		//DisplaySolved( pDC );

} // MoveForward

void CMaze::MoveBackward( CDC* pDC )
{
	// Move one cell backward from the current direction
	// make sure the wall in that direction is open
	switch( m_currentDirection )
	{
	case EAST:
		if( !WestWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_WEST ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentCol--;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_EAST );

		break;

	case NORTH:
		if( !SouthWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_SOUTH ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentRow++;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_NORTH );

		break;

	case WEST:
		if( !EastWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_EAST ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentCol++;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_WEST );

		break;

	case SOUTH:
		if( !NorthWallOpen( m_currentRow, m_currentCol ) ) return;

		// if you leave a cell the same way you entered mark it backtracked
		if( CellMarked( m_currentRow, m_currentCol, ENTER_NORTH ) )
			MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
		else
			UnMarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );

		DisplayCell( pDC, m_currentRow, m_currentCol );
		m_currentRow--;
		DisplayCarrot( pDC, FALSE );

		// if the cell has not been entered before, mark the direction it was entered
		if( !CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
			MarkCell( m_currentRow, m_currentCol, ENTER_SOUTH );

		break;
	}

	if( CellMarked( m_currentRow, m_currentCol, TRACKED_CELL ) )
		MarkCell( m_currentRow, m_currentCol, BACKTRACKED_CELL );
	else
		MarkCell( m_currentRow, m_currentCol, TRACKED_CELL );

	//if( CellMarked( m_currentRow, m_currentCol, FINISH_CELL ) )
		//DisplaySolved( pDC );

} // MoveBackward

//////////////////////////////////////////////////////////////////////
// Maze Building Functions
//////////////////////////////////////////////////////////////////////

void CMaze::Initialize()
{
	if( m_pGrid ) free( m_pGrid );
	m_pGrid = (int *)malloc( sizeof(int) * ( m_nCol * m_nRow ) );
	memset( m_pGrid, 0, (sizeof(int) * (m_nCol * m_nRow) ) );
}

static int	Random(int max)
{
	int r = rand();
	return (r*max)/RAND_MAX;
}

#include "Stack.h"

void CMaze::Build( CDC* pDC )
{
	// Initialize the maze
	Initialize();

	// compute the number of cells
	int	nCells = Row() * Col();
	int	nCellsVisited = 0;

	// create the stack
	CStack	Stack( nCells*2 );

	// get finish point
	int row = Random(Row());
	int col = Random(Col());
	row = Row()-1;
	col = Col()-1;

	MarkCell( row, col, FINISH_CELL );

	// get starting point
	m_currentRow = Random(Row());
	m_currentCol = Random(Col());
	m_currentRow=0;
	m_currentCol=0;
	MarkCell( m_currentRow, m_currentCol, TRACKED_CELL );

	// start building the maze
	// get starting cell for build
	row = Random(Row());
	col = Random(Col());

	Display( pDC );

	// maked the starting cell as visited and push him on the stack
	Visited( row, col );
	nCellsVisited++;
	Stack.Push(row);
	Stack.Push(col);

	while( nCellsVisited < nCells )
	{
		int	nUnvisitedNeighbors = 0;
		int	mNeighbors = 0;

#		define NEIGHBOR_NORTH	0x01
#		define NEIGHBOR_EAST	0x02
#		define NEIGHBOR_SOUTH	0x04
#		define NEIGHBOR_WEST	0x08

		// check for unvisited neighbors
		if( row-1 >= 0 && !WasVisited( row-1, col ) )
		{
			nUnvisitedNeighbors++;
			mNeighbors |= NEIGHBOR_NORTH;
		}

		if( col+1 < Col() && !WasVisited( row, col+1 ) )
		{
			nUnvisitedNeighbors++;
			mNeighbors |= NEIGHBOR_EAST;
		}

		if( row+1 < Row() && !WasVisited( row+1, col ) )
		{
			nUnvisitedNeighbors++;
			mNeighbors |= NEIGHBOR_SOUTH;
		}

		if( col-1 >= 0 && !WasVisited( row, col-1 ) )
		{
			nUnvisitedNeighbors++;
			mNeighbors |= NEIGHBOR_WEST;
		}

		// if there is at least one unvisited neighbor then continue,
		// else get the last cell off the stack
		if( nUnvisitedNeighbors > 0 )
		{
			BOOL found = FALSE;
			while( !found )
			{
				int	which = Random(4);
				switch( which )
				{
				case 0:	// north
					if( mNeighbors & NEIGHBOR_NORTH )
					{
						found = TRUE;
						OpenNorthWall( row,col );
						OpenSouthWall( --row,col );
					}
					break;

				case 1:	// east
					if( mNeighbors & NEIGHBOR_EAST )
					{
						found = TRUE;
						OpenEastWall( row,col );
						OpenWestWall( row,++col );
					}
					break;

				case 2:	// south
					if( mNeighbors & NEIGHBOR_SOUTH )
					{
						found = TRUE;
						OpenSouthWall( row,col );
						OpenNorthWall( ++row,col );
					}
					break;

				case 3:	// west
					if( mNeighbors & NEIGHBOR_WEST )
					{
						found = TRUE;
						OpenWestWall( row,col );
						OpenEastWall( row,--col );
					}
					break;
				}
			}

			DisplayCell( pDC, row, col );

			Visited( row, col );
			nCellsVisited++;
			Stack.Push(row);
			Stack.Push(col);
		}
		else
		{
			col = Stack.Pop();
			row = Stack.Pop();
		}
	}

} // Build

//////////////////////////////////////////////////////////////////////
// Load/Save Functions
//////////////////////////////////////////////////////////////////////

void CMaze::Serialize(CArchive &ar)
{
	int	i, n;

	if (ar.IsStoring())
	{
		ar << m_nRow;
		ar << m_nCol;
		ar << m_CellSize;

		n = m_nRow * m_nCol;
		for( i=0; i<n; i++ )
			ar << m_pGrid[i];
	}
	else
	{
		ar >> m_nRow;
		ar >> m_nCol;
		ar >> m_CellSize;

		n = m_nRow * m_nCol;
		m_pGrid = (int *)malloc( sizeof(int) * n );
		for( i=0; i<n; i++ )
			ar >> m_pGrid[i];
	}

} // Serialize

#include <time.h>

/* Pauses for a specified number of milliseconds. */
static void sleep( clock_t wait )
{
	clock_t goal;
	goal = wait + clock();
	while( goal > clock() );
}

void CMaze::Solve( CDC* pDC )
{
	int	i = 0;

	while( !CellMarked( m_currentRow, m_currentCol, FINISH_CELL ) )
	{

		// try east
		if( EastWallOpen( m_currentRow, m_currentCol ) && 
			!CellMarked( m_currentRow, m_currentCol+1, TRACKED_CELL ) )
		{
			while( m_currentDirection != EAST ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// try south
		if( SouthWallOpen( m_currentRow, m_currentCol ) && 
			!CellMarked( m_currentRow+1, m_currentCol, TRACKED_CELL ) )
		{
			while( m_currentDirection != SOUTH ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// try west
		if( WestWallOpen( m_currentRow, m_currentCol ) && 
			!CellMarked( m_currentRow, m_currentCol-1, TRACKED_CELL ) )
		{
			while( m_currentDirection != WEST ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// try north
		if( NorthWallOpen( m_currentRow, m_currentCol ) && 
			!CellMarked( m_currentRow-1, m_currentCol, TRACKED_CELL ) )
		{
			while( m_currentDirection != NORTH ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// could not find an open wall with an un tracked neighbor cell
		// try tracked neighbor cell, not backtracked
		// try east
		if( EastWallOpen( m_currentRow, m_currentCol ) && 
			CellMarked( m_currentRow, m_currentCol+1, TRACKED_CELL ) &&
			!CellMarked( m_currentRow, m_currentCol+1, BACKTRACKED_CELL ) )
		{
			while( m_currentDirection != EAST ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// try south
		if( SouthWallOpen( m_currentRow, m_currentCol ) && 
			CellMarked( m_currentRow+1, m_currentCol, TRACKED_CELL ) &&
			!CellMarked( m_currentRow+1, m_currentCol, BACKTRACKED_CELL ) )
		{
			while( m_currentDirection != SOUTH ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// try west
		if( WestWallOpen( m_currentRow, m_currentCol ) && 
			CellMarked( m_currentRow, m_currentCol-1, TRACKED_CELL ) &&
			!CellMarked( m_currentRow, m_currentCol-1, BACKTRACKED_CELL ) )
		{
			while( m_currentDirection != WEST ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else

		// try north
		if( NorthWallOpen( m_currentRow, m_currentCol ) && 
			CellMarked( m_currentRow-1, m_currentCol, TRACKED_CELL ) &&
			!CellMarked( m_currentRow-1, m_currentCol, BACKTRACKED_CELL ) )
		{
			while( m_currentDirection != NORTH ) TurnRight( pDC );
			MoveForward( pDC );
		}
		else
			return;

		//sleep( ((clock_t)1 * CLOCKS_PER_SEC) / 64 );
	}
} // Solve

void CMaze::Clear()
{
	for( int i=0; i<m_nRow; i++ )
		for( int j=0; j<m_nCol; j++ )
		{
			UnMarkCell( i, j, TRACKED_CELL );
			UnMarkCell( i, j, BACKTRACKED_CELL );
		}
}