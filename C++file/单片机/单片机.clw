; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "单片机.h"

ClassCount=4
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_SETTING
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG
Resource4=IDD_ABOUTBOX
Class4=CSetting
Resource5=IDR_MENU

[CLS:CMyApp]
Type=0
HeaderFile=单片机.h
ImplementationFile=单片机.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=单片机Dlg.h
ImplementationFile=单片机Dlg.cpp
Filter=D
LastObject=IDC_ADD_READTIME
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=单片机Dlg.h
ImplementationFile=单片机Dlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MY_DIALOG]
Type=1
Class=CMyDlg
ControlCount=20
Control1=IDC_ADD_READ1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_ADD_READ2,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SCMModel,combobox,1344339971
Control6=IDC_TEST1,edit,1350631552
Control7=IDC_TEST2,edit,1350631552
Control8=IDC_BUTSCM,button,1342242816
Control9=IDC_ADD_WRITE,edit,1350631552
Control10=IDC_DATA_WRITE,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_SEND,edit,1350631552
Control14=IDC_MESSAGE,listbox,1352728835
Control15=IDC_TCHART,{B6C10489-FB89-11D4-93C9-006008A7EED4},1342242816
Control16=IDC_MSCOMM,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control17=IDC_CHART1,button,1342242819
Control18=IDC_CHART2,button,1342242819
Control19=IDC_STATIC,static,1342308352
Control20=IDC_ADD_READTIME,edit,1350631552

[MNU:IDR_MENU]
Type=1
Class=CMyDlg
Command1=ID_SERIAL
CommandCount=1

[DLG:IDD_SETTING]
Type=1
Class=CSetting
ControlCount=13
Control1=IDC_STATIC,static,1342308864
Control2=IDC_CommSelect,combobox,1344340227
Control3=IDC_STATIC,static,1342308864
Control4=IDC_BaudRateSelect,combobox,1344339971
Control5=IDC_STATIC,static,1342308864
Control6=IDC_DateSelect,combobox,1344340227
Control7=IDC_STATIC,static,1342308864
Control8=IDC_StopBit,combobox,1344340227
Control9=IDC_STATIC,static,1342308864
Control10=IDC_ParityCheck,combobox,1344340227
Control11=IDC_HexSend,button,1342242819
Control12=IDOK,button,1342242817
Control13=IDCANCEL,button,1342242816

[CLS:CSetting]
Type=0
HeaderFile=Setting.h
ImplementationFile=Setting.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BaudRateSelect
VirtualFilter=dWC

