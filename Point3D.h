// CPoint3D.h: interface for the CPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CPoint3D_H__4E602528_032D_11D3_ADF5_0060972D9D32__INCLUDED_)
#define AFX_CPoint3D_H__4E602528_032D_11D3_ADF5_0060972D9D32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPoint3D
{
public:
	CPoint3D( double x=0.0, double y=0.0, double z=0.0 );
	virtual ~CPoint3D();

	double	m_x;
	double	m_y;
	double	m_z;
	double	m_w;

	// Overloaded Operators

	// Addition
	CPoint3D	operator +(CPoint3D a);
	CPoint3D	operator +(double a);
	void		operator +=(CPoint3D a);
	void		operator +=(double a);
	// Subtraction
	CPoint3D	operator -(CPoint3D a);
	CPoint3D	operator -(double a);
	void		operator -=(CPoint3D a);
	void		operator -=(double a);
	// Multiplication
	CPoint3D	operator *(CPoint3D a);
	CPoint3D	operator *(double a);
	void		operator *=(CPoint3D a);
	void		operator *=(double a);
	// Division
	CPoint3D	operator /(CPoint3D a);
	CPoint3D	operator /(double a);
	void		operator /=(CPoint3D a);
	void		operator /=(double a);

};

#endif // !defined(AFX_CPoint3D_H__4E602528_032D_11D3_ADF5_0060972D9D32__INCLUDED_)
