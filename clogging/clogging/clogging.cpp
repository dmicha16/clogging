// clogging.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Logger.h"

int main()
{	
	INIT_CLOGGING;	
		
	string test_msg = "this is my message1111";
	CLOG(test_msg);
	
    return 0;
}

