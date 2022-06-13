#include <lua.hpp>
#include <string_view>
#include <iostream>
#include <format>

namespace States
{
	lua_State* L = luaL_newstate();
}





void poststring(std::string_view sv) { std::cout << sv << '\n'; }

void endpost() { std::cout << "---\n"; }

int l_my_print(lua_State* L) {
    int nargs = lua_gettop(L);
    for (int i = 1; i <= nargs; ++i) {
        poststring(luaL_tolstring(L, i, nullptr));
        lua_pop(L, 1); // remove the string
    }
    endpost();
    return 0;
}
static const struct luaL_Reg printlib[] = {
  {"print", l_my_print},
  {NULL, NULL} /* end of array */
};

extern int luaopen_luamylib(lua_State* L)
{
    lua_getglobal(L, "_G");
    // luaL_register(L, NULL, printlib); // for Lua versions < 5.2
    luaL_setfuncs(L, printlib, 0);  // for Lua versions 5.2 or greater
    lua_pop(L, 1);
    return 1;
}

namespace StoredPlayerNames
{
    std::string plrName = "";
    std::string OldName = plrName;
}



int SetPlrName(lua_State* L)
{
    if (lua_type(L, -1) == LUA_TSTRING)
    {
        std::printf("Was a String \n");
        StoredPlayerNames::plrName = lua_tostring(L, 1);
        printf("Enter a player name");
        printf("Player name is: %s\n", StoredPlayerNames::plrName.c_str());
    }
    return 0;
}

int GetPlrName(lua_State* L)
{
    std::string CurrentName = StoredPlayerNames::plrName;
    lua_pushstring(L, CurrentName.c_str());
    return 1;
}

static const struct luaL_Reg aaa[] = {
  {"GetLocalPlayerName", GetPlrName},
  {NULL, NULL} /* end of array */
};

void GTALuaInit()
{
    lua_newtable(States::L);

    lua_pushcfunction(States::L, GetPlrName);
    lua_setfield(States::L, -2, "GetLocalPlayerName");
    //lua_setglobal(States::L, "GetLocalPlayerName"); // GTALua.GetLocalPlayerName(<void>) Returns the LocalPlayers Name

    lua_pushcfunction(States::L, SetPlrName);
    lua_setfield(States::L, -2, "SetLocalPlayerName");
    //lua_setglobal(States::L, "SetLocalPlayerName"); // GTALua.SetLocalPlayerName("Name") Sets it

    lua_setglobal(States::L, "GTALua");
    
}


int main()
{
	
	luaL_openlibs(States::L); // Open A Valid Lua State	

    States::L = lua_newthread(States::L);

    luaopen_luamylib(States::L);
	
    lua_pushcfunction(States::L, l_my_print);
	lua_setglobal(States::L, "print");
	
    
    GTALuaInit();

    lua_getglobal(States::L, "print");
    lua_pushstring(States::L, "Hello Cunts");
    lua_pcall(States::L, 1, 0, 0);
	
    std::string aba;

    while (true)
    {
		
        //std::getline(std::cin, aba);
        std::getline(std::cin, aba);
        luaL_dostring(States::L, aba.c_str());
    }
	

}


