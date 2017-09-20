// Stack.cpp: implementation of the CStack class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Maze.h"
#include "Stack.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStack::CStack( int nNodes )
{
	m_pNodes = (int *)malloc( sizeof(int) * nNodes );
	m_nNodes = nNodes;
}

CStack::~CStack()
{
	if( m_pNodes ) free( m_pNodes );
}

void CStack::Push(int item)
{
	for( int i=(m_nNodes-1); i>0; i-- )
		m_pNodes[i] = m_pNodes[i-1];

	m_pNodes[0] = item;
}

int CStack::Pop()
{
	int	item = m_pNodes[0];
	for( int i=0; i<(m_nNodes-1); i++ )
		m_pNodes[i] = m_pNodes[i+1];

	return item;
}
