// Matrix.h: interface for the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MATRIX_H__4BBD7813_0333_11D3_A325_C2721E940013__INCLUDED_)
#define AFX_MATRIX_H__4BBD7813_0333_11D3_A325_C2721E940013__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Point3D.h"

class CMatrix  
{
public:
	CMatrix();
	virtual ~CMatrix();

	double	m_mat[4][4];

	void	Scale( double s );
	void	Translate( CPoint3D t );
	void	Perspective( double d );

	CPoint3D	operator *( CPoint3D p );
	CMatrix		operator *( CMatrix s );
	void		operator *=( CMatrix s );

};

#endif // !defined(AFX_MATRIX_H__4BBD7813_0333_11D3_A325_C2721E940013__INCLUDED_)
