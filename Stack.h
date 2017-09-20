// Stack.h: interface for the CStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STACK_H__0BA41591_02FD_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_STACK_H__0BA41591_02FD_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStack  
{
private:
	int*	m_pNodes;
	int		m_nNodes;

public:
	int Pop();
	void Push( int item );
	CStack( int nNodes );
	virtual ~CStack();

};

#endif // !defined(AFX_STACK_H__0BA41591_02FD_11D3_ADF5_0060972D9D32__INCLUDED_)
