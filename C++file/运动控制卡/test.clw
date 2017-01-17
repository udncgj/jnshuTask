; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CIOChackDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "test.h"
ODLFile=test.odl

ClassCount=13
Class1=CTestApp
Class2=CTestDlg
Class3=CAboutDlg
Class4=CTestDlgAutoProxy

ResourceCount=9
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_SETTING_DIALOG
Resource4=IDD_IO_DIALOG
Resource5=IDD_SETTING1
Class5=CIOChackDlg
Class6=CSettingDlg
Resource6=IDD_SETTING3
Class7=CPara1
Class8=CPara2
Class9=CResult
Class10=CNewButton
Resource7=IDD_SETTING2
Resource8=IDD_TEST_DIALOG
Class11=SETTING3
Class12=SETTING1
Class13=SETTING2
Resource9=IDR_MENU

[CLS:CTestApp]
Type=0
HeaderFile=test.h
ImplementationFile=test.cpp
Filter=N

[CLS:CTestDlg]
Type=0
HeaderFile=testDlg.h
ImplementationFile=testDlg.cpp
Filter=D
LastObject=ID_SELECT
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=testDlg.h
ImplementationFile=testDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[CLS:CTestDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_TEST_DIALOG]
Type=1
Class=CTestDlg
ControlCount=44
Control1=IDC_EDIT_DATA,edit,1350631552
Control2=IDC_BUTSTART,button,1342242816
Control3=IDC_BUTTON2,button,1342242816
Control4=IDC_BUTTON3,button,1342242816
Control5=IDC_BUTTON4,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_FORWARDY,button,1342242816
Control13=IDC_BACKWARDY,button,1342242816
Control14=IDC_LIFTX,button,1342242816
Control15=IDC_RIGHTX,button,1342242816
Control16=IDC_POSX,static,1342308352
Control17=IDC_POSZ,static,1342308352
Control18=IDC_POSY,static,1342308352
Control19=IDC_RUNSPEEDX,static,1342308352
Control20=IDC_RUNSPEEDZ,static,1342308352
Control21=IDC_RUNSPEEDY,static,1342308352
Control22=IDC_POSACTX,static,1342308352
Control23=IDC_POSACTZ,static,1342308352
Control24=IDC_POSACTY,static,1342308352
Control25=IDC_UPPERZ,button,1342242816
Control26=IDC_DOWNZ,button,1342242816
Control27=IDC_LIST,SysListView32,1350631425
Control28=IDC_ADDPOS,button,1342242816
Control29=IDC_DELPOS,button,1342242816
Control30=IDC_MODIFYPOS,button,1342242816
Control31=IDC_INSERTPOS,button,1342242816
Control32=IDC_BUTTON7,button,1342242816
Control33=IDC_MESSAGE,listbox,1352728835
Control34=IDC_STATIC,static,1342308352
Control35=IDC_STATIC,static,1342308352
Control36=IDC_STATIC_NUM,static,1342308352
Control37=IDC_STATIC_STEP,static,1342308352
Control38=IDC_STATIC,static,1342308352
Control39=IDC_STATIC_CYCLES,static,1342308352
Control40=IDC_STATIC,static,1342308352
Control41=IDC_STATIC_I,static,1342308352
Control42=IDC_POSDRAW,listbox,1352728835
Control43=IDC_SAVE1,button,1342242816
Control44=IDC_READ1,button,1342242816

[DLG:IDD_SETTING_DIALOG]
Type=1
Class=CSettingDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_TAB_SETTING,SysTabControl32,1342177280

[DLG:IDD_IO_DIALOG]
Type=1
Class=CIOChackDlg
ControlCount=9
Control1=IDC_STATIC,button,1342178055
Control2=IDC_STATIC,button,1342178055
Control3=IDC_IN1,static,1342177294
Control4=IDC_RESET,button,1342242816
Control5=IDC_IN_NAME1,static,1342308352
Control6=IDC_OUT1,static,1342177294
Control7=IDC_OUT_NAME1,static,1342308352
Control8=IDC_NAME_CHANGE,edit,1350631552
Control9=IDC_BUTTON2,button,1342279424

[MNU:IDR_MENU]
Type=1
Class=?
Command1=ID_OPEN
Command2=ID_SAVE
Command3=ID_IOCHACK
Command4=ID_SELECT
Command5=ID_SETTING
CommandCount=5

[CLS:CIOChackDlg]
Type=0
HeaderFile=IOChackDlg.h
ImplementationFile=IOChackDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_IN1
VirtualFilter=dWC

[CLS:CSettingDlg]
Type=0
HeaderFile=SettingDlg.h
ImplementationFile=SettingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_TAB_SETTING
VirtualFilter=dWC

[CLS:CPara1]
Type=0
HeaderFile=Para1.h
ImplementationFile=Para1.cpp
BaseClass=CDialog
Filter=D
LastObject=CPara1
VirtualFilter=dWC

[CLS:CPara2]
Type=0
HeaderFile=Para2.h
ImplementationFile=Para2.cpp
BaseClass=CDialog
Filter=D
LastObject=CPara2
VirtualFilter=dWC

[CLS:CResult]
Type=0
HeaderFile=Result.h
ImplementationFile=Result.cpp
BaseClass=CDialog
Filter=D
LastObject=CResult
VirtualFilter=dWC

[CLS:CNewButton]
Type=0
HeaderFile=NewButton.h
ImplementationFile=NewButton.cpp
BaseClass=CButton
Filter=W
LastObject=CNewButton

[DLG:IDD_SETTING1]
Type=1
Class=SETTING1
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[DLG:IDD_SETTING2]
Type=1
Class=SETTING2
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_SETTING3]
Type=1
Class=SETTING3
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:SETTING3]
Type=0
HeaderFile=SETTING3.h
ImplementationFile=SETTING3.cpp
BaseClass=CDialog
Filter=D
LastObject=ID_IOCHACK

[CLS:SETTING1]
Type=0
HeaderFile=SETTING1.h
ImplementationFile=SETTING1.cpp
BaseClass=CDialog
Filter=D
LastObject=SETTING1

[CLS:SETTING2]
Type=0
HeaderFile=SETTING2.h
ImplementationFile=SETTING2.cpp
BaseClass=CDialog
Filter=D

