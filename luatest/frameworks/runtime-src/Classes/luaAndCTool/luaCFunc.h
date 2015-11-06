//
//  luaCFunc.h
//  luatest
//
//  Created by woodcol on 15/11/6.
//
//

#ifndef luaCFunc_h
#define luaCFunc_h

#include <stdio.h>
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"


int loadLuaScript(lua_State* Ltmp);
int luaCallCpp(lua_State* L);
int cppCallLua(int ptype,const char* msg,int isPush);

#endif /* luaCFunc_h */


