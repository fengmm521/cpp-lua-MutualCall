//
//  luaCFunc.c
//  luatest
//
//  Created by woodcol on 15/11/6.
//
//

#include "luaCFunc.h"
//testlua.c

#include <stdio.h>

#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"

extern const char* getLuaCallCppPath();

lua_State* L;

int netSend(lua_State* L)
{
    //从L栈中取出索引为1的数值，并检查
    int x = luaL_checkint(L,1);
    //从L栈中取出索引为2的数值，并检查
    const char* y = luaL_checkstring(L,2);
    printf("result:%d,str=%s\n",x,y);
    return 1;
}

int loadLuaScript(lua_State* Ltmp)
{
    L = Ltmp;
    //初始化全局L
    //打开库
    luaL_openlibs(L);
    //把函数压入栈中
    lua_pushcfunction(L, netSend);
    //设置全局ADD
    lua_setglobal(L, "NetSend");
    printf("lua path=%s\n",getLuaCallCppPath());
    //加载我们的lua脚本文件
    if (luaL_loadfile(L,getLuaCallCppPath()))
    {
        printf("error\n");
    }
    //安全检查
    lua_pcall(L,0,0,0);
    return 0;
}


int cppCallLua(int ptype,const char* msg,int isPush)
{
    //push进lua函数
    lua_getglobal(L, "NetRecive");
    lua_pushnumber(L, ptype);
    lua_pushstring(L, msg);
    lua_pushboolean(L, isPush);
    
    if (lua_pcall(L, 3, 0, 0) != 0)
    {
        printf("error running function netrecive\n");
    }
    
    printf("lua p=%d,%s,%d\n",ptype,msg,isPush);
    
    printf("hello my lua\n");
    return 0;
}
