#include "Functions.h"

namespace StoredPlayerNames
{
    std::string plrName = "";
    std::string OldName = plrName;
}

void poststring(std::string_view sv) { std::cout << sv << '\n'; }

void endpost() { std::cout << "---\n"; }

int Functions::l_my_print(lua_State* L) {
    int nargs = lua_gettop(L);
    for (int i = 1; i <= nargs; ++i) {
        poststring(luaL_tolstring(L, i, nullptr));
        lua_pop(L, 1); // remove the string
    }
    endpost();
    return 0;
}

int Functions::SetPlrName(lua_State* L)
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

int Functions::GetPlrName(lua_State* L)
{
    std::string CurrentName = StoredPlayerNames::plrName;
    lua_pushstring(L, CurrentName.c_str());
    return 1;
}
