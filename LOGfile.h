#ifndef LOGFILE_H
#define LOGFILE_H

// LOGfile class declarations

class LOGfile
	{
	private:
		FILE*		m_fp;
		CString	m_filename;

	public:
		LOGfile( char* filename )
		{
			char  *fname;
   
			m_filename = CString( filename );
			fname = m_filename.GetBuffer(100);

			m_fp = fopen( fname, "wa" );

			fprintf( m_fp, "Logfile: %s\n", LPCTSTR( m_filename ) );

			fclose( m_fp );
		}
		
		void	writeln( const char* string )		// write a string in the logfile
		{
			char  *fname;
   
			fname = m_filename.GetBuffer(100);
			m_fp = fopen( fname, "aa" );   

			fprintf( m_fp, "%s\n", LPCTSTR( string ) );

			fclose( m_fp );
		}
		
		void	write( const char* string )		// write a string in the logfile
		{
			char  *fname;
   
			fname = m_filename.GetBuffer(100);
			m_fp = fopen( fname, "aa" );   

			fprintf( m_fp, "%s", LPCTSTR( string ) );

			fclose( m_fp );
		}
		
		void	writeint( int x )		// write an int in the logfile
		{
			char  *fname;
   
			fname = m_filename.GetBuffer(100);
			m_fp = fopen( fname, "aa" );   

			fprintf( m_fp, "%d", x );

			fclose( m_fp );
		}
	};

#endif
