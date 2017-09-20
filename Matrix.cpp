// Matrix.cpp: implementation of the CMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Matrix.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMatrix::CMatrix()
{
	memset( m_mat, 0, sizeof(double)*16 );

	m_mat[0][0] = 1.0;
	m_mat[1][1] = 1.0;
	m_mat[2][2] = 1.0;
	m_mat[3][3] = 1.0;
}

CMatrix::~CMatrix()
{

}

void	CMatrix::Scale( double s )
{
	m_mat[0][0] = s;
	m_mat[1][1] = s;
	m_mat[2][2] = s;
}

void	CMatrix::Translate( CPoint3D t )
{
	m_mat[0][3] = t.m_x;
	m_mat[1][3] = t.m_y;
	m_mat[2][3] = t.m_z;
}

void	CMatrix::Perspective( double d )
{
	if( d != 0.0 )
	{
		m_mat[3][2] = 1.0 / d;
		m_mat[3][3] = 0.0;
	}
}

CPoint3D	CMatrix::operator *( CPoint3D p )
{
	CPoint3D	r;

	if( p.m_z < 0 )
	{
		r = p;
		return r;
	}

	r.m_x = p.m_x * m_mat[0][0] +
			p.m_y * m_mat[0][1] +
			p.m_z * m_mat[0][2] +
			p.m_w * m_mat[0][3]; 

	r.m_y = p.m_x * m_mat[1][0] +
			p.m_y * m_mat[1][1] +
			p.m_z * m_mat[1][2] +
			p.m_w * m_mat[1][3]; 

	r.m_z = p.m_x * m_mat[2][0] +
			p.m_y * m_mat[2][1] +
			p.m_z * m_mat[2][2] +
			p.m_w * m_mat[2][3]; 

	r.m_w = p.m_x * m_mat[3][0] +
			p.m_y * m_mat[3][1] +
			p.m_z * m_mat[3][2] +
			p.m_w * m_mat[3][3]; 

	if( r.m_w != 0.0 )
	{
		r.m_x /= r.m_w;
		r.m_y /= r.m_w;
		r.m_z /= r.m_w;
		r.m_w /= r.m_w;
	}

	return r;
}

CMatrix	CMatrix::operator *( CMatrix s )
{
	CMatrix	t;

	t.m_mat[0][0] = this->m_mat[0][0] * s.m_mat[0][0] +
					this->m_mat[1][0] * s.m_mat[0][1] +
					this->m_mat[2][0] * s.m_mat[0][2] +
					this->m_mat[3][0] * s.m_mat[0][3];

	t.m_mat[1][0] = this->m_mat[0][0] * s.m_mat[1][0] +
					this->m_mat[1][0] * s.m_mat[1][1] +
					this->m_mat[2][0] * s.m_mat[1][2] +
					this->m_mat[3][0] * s.m_mat[1][3];

	t.m_mat[2][0] = this->m_mat[0][0] * s.m_mat[2][0] +
					this->m_mat[1][0] * s.m_mat[2][1] +
					this->m_mat[2][0] * s.m_mat[2][2] +
					this->m_mat[3][0] * s.m_mat[2][3];

	t.m_mat[3][0] = this->m_mat[0][0] * s.m_mat[3][0] +
					this->m_mat[1][0] * s.m_mat[3][1] +
					this->m_mat[2][0] * s.m_mat[3][2] +
					this->m_mat[3][0] * s.m_mat[3][3];

	t.m_mat[0][1] = this->m_mat[0][1] * s.m_mat[0][0] +
					this->m_mat[1][1] * s.m_mat[0][1] +
					this->m_mat[2][1] * s.m_mat[0][2] +
					this->m_mat[3][1] * s.m_mat[0][3];

	t.m_mat[1][1] = this->m_mat[0][1] * s.m_mat[1][0] +
					this->m_mat[1][1] * s.m_mat[1][1] +
					this->m_mat[2][1] * s.m_mat[1][2] +
					this->m_mat[3][1] * s.m_mat[1][3];

	t.m_mat[2][1] = this->m_mat[0][1] * s.m_mat[2][0] +
					this->m_mat[1][1] * s.m_mat[2][1] +
					this->m_mat[2][1] * s.m_mat[2][2] +
					this->m_mat[3][1] * s.m_mat[2][3];

	t.m_mat[3][1] = this->m_mat[0][1] * s.m_mat[3][0] +
					this->m_mat[1][1] * s.m_mat[3][1] +
					this->m_mat[2][1] * s.m_mat[3][2] +
					this->m_mat[3][1] * s.m_mat[3][3];

	t.m_mat[0][2] = this->m_mat[0][2] * s.m_mat[0][0] +
					this->m_mat[1][2] * s.m_mat[0][1] +
					this->m_mat[2][2] * s.m_mat[0][2] +
					this->m_mat[3][2] * s.m_mat[0][3];

	t.m_mat[1][2] = this->m_mat[0][2] * s.m_mat[1][0] +
					this->m_mat[1][2] * s.m_mat[1][1] +
					this->m_mat[2][2] * s.m_mat[1][2] +
					this->m_mat[3][2] * s.m_mat[1][3];

	t.m_mat[2][2] = this->m_mat[0][2] * s.m_mat[2][0] +
					this->m_mat[1][2] * s.m_mat[2][1] +
					this->m_mat[2][2] * s.m_mat[2][2] +
					this->m_mat[3][2] * s.m_mat[2][3];

	t.m_mat[3][2] = this->m_mat[0][2] * s.m_mat[3][0] +
					this->m_mat[1][2] * s.m_mat[3][1] +
					this->m_mat[2][2] * s.m_mat[3][2] +
					this->m_mat[3][2] * s.m_mat[3][3];

	t.m_mat[0][3] = this->m_mat[0][3] * s.m_mat[0][0] +
					this->m_mat[1][3] * s.m_mat[0][1] +
					this->m_mat[2][3] * s.m_mat[0][2] +
					this->m_mat[3][3] * s.m_mat[0][3];

	t.m_mat[1][3] = this->m_mat[0][3] * s.m_mat[1][0] +
					this->m_mat[1][3] * s.m_mat[1][1] +
					this->m_mat[2][3] * s.m_mat[1][2] +
					this->m_mat[3][3] * s.m_mat[1][3];

	t.m_mat[2][3] = this->m_mat[0][3] * s.m_mat[2][0] +
					this->m_mat[1][3] * s.m_mat[2][1] +
					this->m_mat[2][3] * s.m_mat[2][2] +
					this->m_mat[3][3] * s.m_mat[2][3];

	t.m_mat[3][3] = this->m_mat[0][3] * s.m_mat[3][0] +
					this->m_mat[1][3] * s.m_mat[3][1] +
					this->m_mat[2][3] * s.m_mat[3][2] +
					this->m_mat[3][3] * s.m_mat[3][3];

	return t;
}

void	CMatrix::operator *=( CMatrix s )
{
	CMatrix	t;

	t.m_mat[0][0] = this->m_mat[0][0] * s.m_mat[0][0] +
					this->m_mat[1][0] * s.m_mat[0][1] +
					this->m_mat[2][0] * s.m_mat[0][2] +
					this->m_mat[3][0] * s.m_mat[0][3];

	t.m_mat[1][0] = this->m_mat[0][0] * s.m_mat[1][0] +
					this->m_mat[1][0] * s.m_mat[1][1] +
					this->m_mat[2][0] * s.m_mat[1][2] +
					this->m_mat[3][0] * s.m_mat[1][3];

	t.m_mat[2][0] = this->m_mat[0][0] * s.m_mat[2][0] +
					this->m_mat[1][0] * s.m_mat[2][1] +
					this->m_mat[2][0] * s.m_mat[2][2] +
					this->m_mat[3][0] * s.m_mat[2][3];

	t.m_mat[3][0] = this->m_mat[0][0] * s.m_mat[3][0] +
					this->m_mat[1][0] * s.m_mat[3][1] +
					this->m_mat[2][0] * s.m_mat[3][2] +
					this->m_mat[3][0] * s.m_mat[3][3];

	t.m_mat[0][1] = this->m_mat[0][1] * s.m_mat[0][0] +
					this->m_mat[1][1] * s.m_mat[0][1] +
					this->m_mat[2][1] * s.m_mat[0][2] +
					this->m_mat[3][1] * s.m_mat[0][3];

	t.m_mat[1][1] = this->m_mat[0][1] * s.m_mat[1][0] +
					this->m_mat[1][1] * s.m_mat[1][1] +
					this->m_mat[2][1] * s.m_mat[1][2] +
					this->m_mat[3][1] * s.m_mat[1][3];

	t.m_mat[2][1] = this->m_mat[0][1] * s.m_mat[2][0] +
					this->m_mat[1][1] * s.m_mat[2][1] +
					this->m_mat[2][1] * s.m_mat[2][2] +
					this->m_mat[3][1] * s.m_mat[2][3];

	t.m_mat[3][1] = this->m_mat[0][1] * s.m_mat[3][0] +
					this->m_mat[1][1] * s.m_mat[3][1] +
					this->m_mat[2][1] * s.m_mat[3][2] +
					this->m_mat[3][1] * s.m_mat[3][3];

	t.m_mat[0][2] = this->m_mat[0][2] * s.m_mat[0][0] +
					this->m_mat[1][2] * s.m_mat[0][1] +
					this->m_mat[2][2] * s.m_mat[0][2] +
					this->m_mat[3][2] * s.m_mat[0][3];

	t.m_mat[1][2] = this->m_mat[0][2] * s.m_mat[1][0] +
					this->m_mat[1][2] * s.m_mat[1][1] +
					this->m_mat[2][2] * s.m_mat[1][2] +
					this->m_mat[3][2] * s.m_mat[1][3];

	t.m_mat[2][2] = this->m_mat[0][2] * s.m_mat[2][0] +
					this->m_mat[1][2] * s.m_mat[2][1] +
					this->m_mat[2][2] * s.m_mat[2][2] +
					this->m_mat[3][2] * s.m_mat[2][3];

	t.m_mat[3][2] = this->m_mat[0][2] * s.m_mat[3][0] +
					this->m_mat[1][2] * s.m_mat[3][1] +
					this->m_mat[2][2] * s.m_mat[3][2] +
					this->m_mat[3][2] * s.m_mat[3][3];

	t.m_mat[0][3] = this->m_mat[0][3] * s.m_mat[0][0] +
					this->m_mat[1][3] * s.m_mat[0][1] +
					this->m_mat[2][3] * s.m_mat[0][2] +
					this->m_mat[3][3] * s.m_mat[0][3];

	t.m_mat[1][3] = this->m_mat[0][3] * s.m_mat[1][0] +
					this->m_mat[1][3] * s.m_mat[1][1] +
					this->m_mat[2][3] * s.m_mat[1][2] +
					this->m_mat[3][3] * s.m_mat[1][3];

	t.m_mat[2][3] = this->m_mat[0][3] * s.m_mat[2][0] +
					this->m_mat[1][3] * s.m_mat[2][1] +
					this->m_mat[2][3] * s.m_mat[2][2] +
					this->m_mat[3][3] * s.m_mat[2][3];

	t.m_mat[3][3] = this->m_mat[0][3] * s.m_mat[3][0] +
					this->m_mat[1][3] * s.m_mat[3][1] +
					this->m_mat[2][3] * s.m_mat[3][2] +
					this->m_mat[3][3] * s.m_mat[3][3];

	*this = t;
}
