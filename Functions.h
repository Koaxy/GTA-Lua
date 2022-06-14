#pragma once
#include <string>
#include <string_view>
#include <iostream>
#include "Lua/lua.hpp"

namespace StoredPlayerNames
{
    extern std::string plrName;
    extern std::string OldName;
}


namespace Functions
{
    int l_my_print(lua_State* L);
    int SetPlrName(lua_State* L);
    int GetPlrName(lua_State* L);
}

