; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "串口助手.h"

ClassCount=3
Class1=CMyApp
Class2=CMyDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_MY_DIALOG

[CLS:CMyApp]
Type=0
HeaderFile=串口助手.h
ImplementationFile=串口助手.cpp
Filter=N

[CLS:CMyDlg]
Type=0
HeaderFile=串口助手Dlg.h
ImplementationFile=串口助手Dlg.cpp
Filter=D
LastObject=IDC_COMBO_CommSelect
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=串口助手Dlg.h
ImplementationFile=串口助手Dlg.cpp
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
ControlCount=23
Control1=IDC_MSCOMM1,{648A5600-2C6E-101B-82B6-000000000014},1342242816
Control2=IDC_EDIT_RXDATA,edit,1352728580
Control3=IDC_BUTTON_MANUALSEND,button,1342242816
Control4=IDC_EDIT_TXDATA,edit,1352732868
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_COMBO_CommSelect,combobox,1344339971
Control13=IDC_COMBO_BaudRate_Select,combobox,1344339971
Control14=IDC_COMBO_StopBit,combobox,1344339971
Control15=IDC_COMBO_Date_Select,combobox,1344339971
Control16=IDC_COMBO_ParityCheck,combobox,1344339971
Control17=IDC_BUTTON1,button,1342242816
Control18=IDC_EDIT_Timer,edit,1350631552
Control19=IDC_STATIC,static,1342308352
Control20=IDC_BUTTON_AutoSend,button,1342242816
Control21=IDC_BUTTON_StopAutoSend,button,1342242816
Control22=IDC_CHECK_HexSend,button,1342242819
Control23=IDC_BUTTON_CleanRXData,button,1342242816

