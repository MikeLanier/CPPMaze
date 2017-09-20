# Microsoft Developer Studio Generated NMAKE File, Based on Maze.dsp
!IF "$(CFG)" == ""
CFG=Maze - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Maze - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Maze - Win32 Release" && "$(CFG)" != "Maze - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Maze.mak" CFG="Maze - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Maze - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Maze - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Maze - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : ".\Maze.exe" "$(OUTDIR)\Maze.bsc"


CLEAN :
	-@erase "$(INTDIR)\CMaze.obj"
	-@erase "$(INTDIR)\CMaze.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\Maze.obj"
	-@erase "$(INTDIR)\Maze.pch"
	-@erase "$(INTDIR)\Maze.res"
	-@erase "$(INTDIR)\Maze.sbr"
	-@erase "$(INTDIR)\MazeDoc.obj"
	-@erase "$(INTDIR)\MazeDoc.sbr"
	-@erase "$(INTDIR)\MazeSizeDialog.obj"
	-@erase "$(INTDIR)\MazeSizeDialog.sbr"
	-@erase "$(INTDIR)\MazeView.obj"
	-@erase "$(INTDIR)\MazeView.sbr"
	-@erase "$(INTDIR)\Point3D.obj"
	-@erase "$(INTDIR)\Point3D.sbr"
	-@erase "$(INTDIR)\PrintScaleDialog.obj"
	-@erase "$(INTDIR)\PrintScaleDialog.sbr"
	-@erase "$(INTDIR)\Stack.obj"
	-@erase "$(INTDIR)\Stack.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Maze.bsc"
	-@erase ".\Maze.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Maze.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Maze.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Maze.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CMaze.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\Maze.sbr" \
	"$(INTDIR)\MazeDoc.sbr" \
	"$(INTDIR)\MazeSizeDialog.sbr" \
	"$(INTDIR)\MazeView.sbr" \
	"$(INTDIR)\Point3D.sbr" \
	"$(INTDIR)\PrintScaleDialog.sbr" \
	"$(INTDIR)\Stack.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\Maze.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Maze.pdb" /machine:I386 /out:"Maze.exe" 
LINK32_OBJS= \
	"$(INTDIR)\CMaze.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Maze.obj" \
	"$(INTDIR)\MazeDoc.obj" \
	"$(INTDIR)\MazeSizeDialog.obj" \
	"$(INTDIR)\MazeView.obj" \
	"$(INTDIR)\Point3D.obj" \
	"$(INTDIR)\PrintScaleDialog.obj" \
	"$(INTDIR)\Stack.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Maze.res"

".\Maze.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Maze - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Maze.exe" "$(OUTDIR)\Maze.bsc"


CLEAN :
	-@erase "$(INTDIR)\CMaze.obj"
	-@erase "$(INTDIR)\CMaze.sbr"
	-@erase "$(INTDIR)\MainFrm.obj"
	-@erase "$(INTDIR)\MainFrm.sbr"
	-@erase "$(INTDIR)\Maze.obj"
	-@erase "$(INTDIR)\Maze.pch"
	-@erase "$(INTDIR)\Maze.res"
	-@erase "$(INTDIR)\Maze.sbr"
	-@erase "$(INTDIR)\MazeDoc.obj"
	-@erase "$(INTDIR)\MazeDoc.sbr"
	-@erase "$(INTDIR)\MazeSizeDialog.obj"
	-@erase "$(INTDIR)\MazeSizeDialog.sbr"
	-@erase "$(INTDIR)\MazeView.obj"
	-@erase "$(INTDIR)\MazeView.sbr"
	-@erase "$(INTDIR)\Point3D.obj"
	-@erase "$(INTDIR)\Point3D.sbr"
	-@erase "$(INTDIR)\PrintScaleDialog.obj"
	-@erase "$(INTDIR)\PrintScaleDialog.sbr"
	-@erase "$(INTDIR)\Stack.obj"
	-@erase "$(INTDIR)\Stack.sbr"
	-@erase "$(INTDIR)\StdAfx.obj"
	-@erase "$(INTDIR)\StdAfx.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Maze.bsc"
	-@erase "$(OUTDIR)\Maze.exe"
	-@erase "$(OUTDIR)\Maze.ilk"
	-@erase "$(OUTDIR)\Maze.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Maze.pch" /Yu"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x409 /fo"$(INTDIR)\Maze.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Maze.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\CMaze.sbr" \
	"$(INTDIR)\MainFrm.sbr" \
	"$(INTDIR)\Maze.sbr" \
	"$(INTDIR)\MazeDoc.sbr" \
	"$(INTDIR)\MazeSizeDialog.sbr" \
	"$(INTDIR)\MazeView.sbr" \
	"$(INTDIR)\Point3D.sbr" \
	"$(INTDIR)\PrintScaleDialog.sbr" \
	"$(INTDIR)\Stack.sbr" \
	"$(INTDIR)\StdAfx.sbr"

"$(OUTDIR)\Maze.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Maze.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Maze.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\CMaze.obj" \
	"$(INTDIR)\MainFrm.obj" \
	"$(INTDIR)\Maze.obj" \
	"$(INTDIR)\MazeDoc.obj" \
	"$(INTDIR)\MazeSizeDialog.obj" \
	"$(INTDIR)\MazeView.obj" \
	"$(INTDIR)\Point3D.obj" \
	"$(INTDIR)\PrintScaleDialog.obj" \
	"$(INTDIR)\Stack.obj" \
	"$(INTDIR)\StdAfx.obj" \
	"$(INTDIR)\Maze.res"

"$(OUTDIR)\Maze.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Maze.dep")
!INCLUDE "Maze.dep"
!ELSE 
!MESSAGE Warning: cannot find "Maze.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Maze - Win32 Release" || "$(CFG)" == "Maze - Win32 Debug"
SOURCE=.\CMaze.cpp

"$(INTDIR)\CMaze.obj"	"$(INTDIR)\CMaze.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\MainFrm.cpp

"$(INTDIR)\MainFrm.obj"	"$(INTDIR)\MainFrm.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\Maze.cpp

"$(INTDIR)\Maze.obj"	"$(INTDIR)\Maze.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\Maze.rc

"$(INTDIR)\Maze.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)


SOURCE=.\MazeDoc.cpp

"$(INTDIR)\MazeDoc.obj"	"$(INTDIR)\MazeDoc.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\MazeSizeDialog.cpp

"$(INTDIR)\MazeSizeDialog.obj"	"$(INTDIR)\MazeSizeDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\MazeView.cpp

"$(INTDIR)\MazeView.obj"	"$(INTDIR)\MazeView.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\Point3D.cpp

"$(INTDIR)\Point3D.obj"	"$(INTDIR)\Point3D.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\PrintScaleDialog.cpp

"$(INTDIR)\PrintScaleDialog.obj"	"$(INTDIR)\PrintScaleDialog.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\Stack.cpp

"$(INTDIR)\Stack.obj"	"$(INTDIR)\Stack.sbr" : $(SOURCE) "$(INTDIR)" "$(INTDIR)\Maze.pch"


SOURCE=.\StdAfx.cpp

!IF  "$(CFG)" == "Maze - Win32 Release"

CPP_SWITCHES=/nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Maze.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Maze.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ELSEIF  "$(CFG)" == "Maze - Win32 Debug"

CPP_SWITCHES=/nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Maze.pch" /Yc"stdafx.h" /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 

"$(INTDIR)\StdAfx.obj"	"$(INTDIR)\StdAfx.sbr"	"$(INTDIR)\Maze.pch" : $(SOURCE) "$(INTDIR)"
	$(CPP) @<<
  $(CPP_SWITCHES) $(SOURCE)
<<


!ENDIF 


!ENDIF 

