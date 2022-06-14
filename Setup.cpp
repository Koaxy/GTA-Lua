#include "Setup.h"

void Setup::SetupState(lua_State* State)
{
	luaL_openlibs(State); // Open A Valid Lua State	

	State = lua_newthread(State);

	std::printf("Threaded State: %p \n", State);
}

void Setup::GTALuaInit(lua_State* State)
{
    
        lua_newtable(State);

        lua_pushcfunction(State, Functions::GetPlrName);
        lua_setfield(State, -2, "GetLocalPlayerName");

        lua_pushcfunction(State, Functions::SetPlrName);
        lua_setfield(State, -2, "SetLocalPlayerName");
        //lua_setglobal(States::L, "SetLocalPlayerName"); // GTALua.SetLocalPlayerName("Name") Sets it

        lua_setglobal(State, "GTALua");

        lua_pushcfunction(State, Functions::l_my_print);
        lua_setglobal(State, "print");

    
}
