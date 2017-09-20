; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMazeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Maze.h"
LastPage=0

ClassCount=7
Class1=CMazeApp
Class2=CMazeDoc
Class3=CMazeView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDD_MAZE_SIZE
Class6=CMazeSizeDialog
Resource3=IDD_PRINT_SCALE
Class7=CPrintScaleDialog
Resource4=IDR_MAINFRAME

[CLS:CMazeApp]
Type=0
HeaderFile=Maze.h
ImplementationFile=Maze.cpp
Filter=N

[CLS:CMazeDoc]
Type=0
HeaderFile=MazeDoc.h
ImplementationFile=MazeDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CMazeDoc

[CLS:CMazeView]
Type=0
HeaderFile=MazeView.h
ImplementationFile=MazeView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_OPTIONS_CLEAR


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=Maze.cpp
ImplementationFile=Maze.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SCALE
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_OPTIONS_SIZE
Command12=ID_OPTIONS_3D
Command13=ID_OPTIONS_2D
Command14=ID_OPTIONS_CLEAR
Command15=ID_SOLVE
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_OPTIONS_2D
Command2=ID_OPTIONS_3D
Command3=ID_OPTIONS_CLEAR
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_FILE_SAVE
Command7=ID_SOLVE
Command8=ID_OPTIONS_SIZE
CommandCount=8

[DLG:IDD_MAZE_SIZE]
Type=1
Class=CMazeSizeDialog
ControlCount=8
Control1=IDC_NUM_ROWS,edit,1350631552
Control2=IDC_NUM_COLS,edit,1350631552
Control3=IDC_CELL_SIZE,edit,1350631552
Control4=IDOK,button,1342242817
Control5=IDCANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352

[CLS:CMazeSizeDialog]
Type=0
HeaderFile=MazeSizeDialog.h
ImplementationFile=MazeSizeDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CMazeSizeDialog

[DLG:IDD_PRINT_SCALE]
Type=1
Class=CPrintScaleDialog
ControlCount=4
Control1=IDC_PRINT_SCALE,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CPrintScaleDialog]
Type=0
HeaderFile=PrintScaleDialog.h
ImplementationFile=PrintScaleDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPrintScaleDialog

