#include "../Lua/lua.hpp"
#include <string_view>
#include <iostream>
#include <format>

#include "Setup.h"










States* States_ = new States;
Setup* Setup_ = new Setup;





int main()
{
    Setup_->SetupState(States_->L);
    Setup_->GTALuaInit(States_->L);
	
    std::string aba;

    while (true)
    {
		
        //std::getline(std::cin, aba);
        std::getline(std::cin, aba);
        luaL_dostring(States_->L, aba.c_str());
    }
	

}


