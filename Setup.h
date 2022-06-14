#pragma once
#include "Functions.h"

class States
{
public:
	lua_State* L = luaL_newstate();
private:
};

class Setup
{
	// Can keep this as a class
public:
	
	void SetupState(lua_State* State);

	void GTALuaInit(lua_State* State);
};

