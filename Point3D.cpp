// CPoint3D.cpp: implementation of the CPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Point3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPoint3D::CPoint3D( double x, double y, double z )
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = 1.0;
}

CPoint3D::~CPoint3D()
{

}


// Overloaded Operators

// Addition
CPoint3D	CPoint3D::operator +(CPoint3D a)
{
	CPoint3D	b;
	b.m_x = this->m_x + a.m_x;
	b.m_y = this->m_y + a.m_y;
	b.m_z = this->m_z + a.m_z;

	return b;
}

CPoint3D	CPoint3D::operator +(double a)
{
	CPoint3D	b;
	b.m_x = this->m_x + a;
	b.m_y = this->m_y + a;
	b.m_z = this->m_z + a;

	return b;
}

void	CPoint3D::operator +=(CPoint3D a)
{
	this->m_x += a.m_x;
	this->m_y += a.m_y;
	this->m_z += a.m_z;
}

void	CPoint3D::operator +=(double a)
{
	this->m_x += a;
	this->m_y += a;
	this->m_z += a;
}

// Subtraction
CPoint3D	CPoint3D::operator -(CPoint3D a)
{
	CPoint3D	b;
	b.m_x = this->m_x - a.m_x;
	b.m_y = this->m_y - a.m_y;
	b.m_z = this->m_z - a.m_z;

	return b;
}

CPoint3D	CPoint3D::operator -(double a)
{
	CPoint3D	b;
	b.m_x = this->m_x - a;
	b.m_y = this->m_y - a;
	b.m_z = this->m_z - a;

	return b;
}

void	CPoint3D::operator -=(CPoint3D a)
{
	this->m_x -= a.m_x;
	this->m_y -= a.m_y;
	this->m_z -= a.m_z;
}

void	CPoint3D::operator -=(double a)
{
	this->m_x -= a;
	this->m_y -= a;
	this->m_z -= a;
}

// Multiplication
CPoint3D	CPoint3D::operator *(CPoint3D a)
{
	CPoint3D	b;
	b.m_x = this->m_x * a.m_x;
	b.m_y = this->m_y * a.m_y;
	b.m_z = this->m_z * a.m_z;

	return b;
}

CPoint3D	CPoint3D::operator *(double a)
{
	CPoint3D	b;
	b.m_x = this->m_x * a;
	b.m_y = this->m_y * a;
	b.m_z = this->m_z * a;

	return b;
}

void	CPoint3D::operator *=(CPoint3D a)
{
	this->m_x *= a.m_x;
	this->m_y *= a.m_y;
	this->m_z *= a.m_z;
}

void	CPoint3D::operator *=(double a)
{
	this->m_x *= a;
	this->m_y *= a;
	this->m_z *= a;
}

// Division
CPoint3D	CPoint3D::operator /(CPoint3D a)
{
	CPoint3D	b;
	b.m_x = this->m_x / a.m_x;
	b.m_y = this->m_y / a.m_y;
	b.m_z = this->m_z / a.m_z;

	return b;
}

CPoint3D	CPoint3D::operator /(double a)
{
	CPoint3D	b;
	b.m_x = this->m_x / a;
	b.m_y = this->m_y / a;
	b.m_z = this->m_z / a;

	return b;
}

void	CPoint3D::operator /=(CPoint3D a)
{
	this->m_x /= a.m_x;
	this->m_y /= a.m_y;
	this->m_z /= a.m_z;
}

void	CPoint3D::operator /=(double a)
{
	this->m_x /= a;
	this->m_y /= a;
	this->m_z /= a;
}
