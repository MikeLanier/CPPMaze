// MazeDoc.cpp : implementation of the CMazeDoc class
//

#include "stdafx.h"
#include "Maze.h"

#include "MazeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMazeDoc

IMPLEMENT_DYNCREATE(CMazeDoc, CDocument)

BEGIN_MESSAGE_MAP(CMazeDoc, CDocument)
	//{{AFX_MSG_MAP(CMazeDoc)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMazeDoc construction/destruction

CMazeDoc::CMazeDoc()
{
}

CMazeDoc::~CMazeDoc()
{
}

BOOL CMazeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	m_Maze.Initialize();
	m_Maze.Build( NULL );

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMazeDoc serialization

void CMazeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}

	m_Maze.Serialize( ar );

	UpdateAllViews( NULL );
}

/////////////////////////////////////////////////////////////////////////////
// CMazeDoc diagnostics

#ifdef _DEBUG
void CMazeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMazeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMazeDoc commands

void CMazeDoc::OnFileNew() 
{
	m_Maze.Initialize();
	m_Maze.Build( NULL );
	UpdateAllViews( NULL );
}

