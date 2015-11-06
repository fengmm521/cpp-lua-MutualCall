//
//  LuaCallCppTool.cpp
//  luatest
//
//  Created by woodcol on 15/11/6.
//
//

#include "LuaCallCppTool.hpp"
#include "cocos2d.h"
const char* getLuaCallCppPath()
{
    std::string strtmp = cocos2d::FileUtils::getInstance()->fullPathForFilename("src/luaCtool.lua");
    return strtmp.c_str();
}