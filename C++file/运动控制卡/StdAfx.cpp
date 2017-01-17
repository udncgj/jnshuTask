// stdafx.cpp : source file that includes just the standard includes
//	test.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"



void	DoEvent()
{
	static MSG msg;
	if(::PeekMessage(&msg,NULL,0,0,PM_REMOVE))
	{
	  ::TranslateMessage( &msg );
	  ::DispatchMessage( &msg );
	}
}
void Delay(long time)
{
	long tm = GetTickCount();
	while(true)
	{
		if((long)GetTickCount()-tm >= time)
			break;
		::DoEvent();
	}
}