// CMaze.h: interface for the CMaze class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZE_H__2A4312B4_02F1_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_MAZE_H__2A4312B4_02F1_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define	WAS_VISITED			0x0001

#define	WEST_WALL_OPEN		0x0002
#define	EAST_WALL_OPEN		0x0004
#define	NORTH_WALL_OPEN		0x0008
#define	SOUTH_WALL_OPEN		0x0010

#define	FINISH_CELL			0x0020
#define	TRACKED_CELL		0x0040
#define	BACKTRACKED_CELL	0x0080

#define	ENTER_NORTH			0x0100
#define	ENTER_SOUTH			0x0200
#define	ENTER_EAST			0x0400
#define	ENTER_WEST			0x0800

#define	NORTH		0
#define	SOUTH		1
#define	EAST		2
#define	WEST		3
#define	FLOOR		4
#define	CEILING		5

#include "Point3D.h"

class CMaze  
{
private:
	int		m_nCol;
	int		m_nRow;
	int*	m_pGrid;
	int		m_CellSize;

	int		Index( int row, int col ) {	return ((row * m_nCol) + col); }

	HPEN	m_BlackPen;
	HPEN	m_GreyPen;
	HPEN	m_RedPen;
	HPEN	m_YellowPen;
	HPEN	m_WhitePen;
	HPEN	m_GreenPen;
	HPEN	m_SkyBluePen;
	HPEN	m_OrangePen;

	HBRUSH	m_RedBrush;
	HBRUSH	m_GreenBrush;
	HBRUSH	m_GreyBrush;
	HBRUSH	m_GreyWallBrush;
	HBRUSH	m_GreyBackBrush;
	HBRUSH	m_YellowBrush;
	HBRUSH	m_WhiteBrush;
	HBRUSH	m_SkyBlueBrush;
	HBRUSH	m_OrangeBrush;

	// current cell
	int		m_currentRow;
	int		m_currentCol;
	int		m_currentDirection;

	// clipping info
	CRect	m_clipRect;

	// scale
	double	m_scale;

public:
	void Serialize( CArchive& ar );
	void Build( CDC* pDC );
	void Initialize();

	void Print( CDC* pDC, int printScale );
	void PrintCell( CDC* pDC, int row, int col );

	void Display( CDC* pDC );
	void DisplayCell( CDC* pDC, int row, int col );
	void DisplayCarrot( CDC* pDC, BOOL bErase );
	void DisplaySolved( CDC* pDC );

	void Display3D( CDC* pDC, BOOL bBoth );
	void DisplayCell3D( CDC* pDC, int currentRow, int currentCol, int row, int col, int direction );
	void DisplayWall3D(CDC *pDC, CPoint3D* q, int wall, CRect clipRect );

	void TurnRight( CDC* pDC );
	void TurnLeft( CDC* pDC );
	void MoveForward( CDC* pDC );
	void MoveBackward( CDC* pDC );

	void Solve( CDC* pDC );
	void Clear();

	CMaze();
	virtual ~CMaze();

	int	Col() { return m_nCol; }
	int	Row() { return m_nRow; }

	void Col( int nCol ) { m_nCol = nCol; }
	void Row( int nRow ) { m_nRow = nRow; }

	BOOL	WestWallOpen( int row, int col )  { return (m_pGrid[Index(row,col)] & WEST_WALL_OPEN) ? TRUE : FALSE; }
	BOOL	EastWallOpen( int row, int col )  { return (m_pGrid[Index(row,col)] & EAST_WALL_OPEN) ? TRUE : FALSE; }
	BOOL	NorthWallOpen( int row, int col ) { return (m_pGrid[Index(row,col)] & NORTH_WALL_OPEN) ? TRUE : FALSE; }
	BOOL	SouthWallOpen( int row, int col ) { return (m_pGrid[Index(row,col)] & SOUTH_WALL_OPEN) ? TRUE : FALSE; }

	void	OpenWestWall( int row, int col )  { m_pGrid[Index(row,col)] |= WEST_WALL_OPEN; }
	void	OpenEastWall( int row, int col )  { m_pGrid[Index(row,col)] |= EAST_WALL_OPEN; }
	void	OpenNorthWall( int row, int col ) { m_pGrid[Index(row,col)] |= NORTH_WALL_OPEN; }
	void	OpenSouthWall( int row, int col ) { m_pGrid[Index(row,col)] |= SOUTH_WALL_OPEN; }

	void	Visited( int row, int col ) { m_pGrid[Index(row,col)] |= WAS_VISITED; }
	BOOL	WasVisited( int row, int col ) { return (m_pGrid[Index(row,col)] & WAS_VISITED) ? TRUE : FALSE; }

	void	MarkCell( int row, int col, int mark ) { m_pGrid[Index(row,col)] |= mark; }
	void	UnMarkCell( int row, int col, int mark ) { m_pGrid[Index(row,col)] &= ~mark; }
	BOOL	CellMarked( int row, int col, int mark ) { return (m_pGrid[Index(row,col)] & mark) ? TRUE : FALSE; }

	void	CellSize( int n_CellSize ) { m_CellSize = n_CellSize; }
	int		CellSize() { return m_CellSize; }
};

#endif // !defined(AFX_MAZE_H__2A4312B4_02F1_11D3_ADF5_0060972D9D32__INCLUDED_)
