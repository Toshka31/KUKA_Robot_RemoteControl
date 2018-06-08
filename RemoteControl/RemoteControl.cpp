// RemoteControl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "KUKAPilot.h"
#include "ScriptParser.h"

int main()
{
	KUKAPilot pilot;
	ComInterpreter com(&pilot);
	ScriptParser scr(&com);

	scr.runScriptFromFile("script.txt");

    return 0;
}

