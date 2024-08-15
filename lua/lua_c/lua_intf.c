#include <stdio.h>
#include <math.h>
#include <lua5.4/lua.h>
#include <lua5.4/lualib.h>
#include <lua5.4/lauxlib.h>

static int l_sin(lua_State *L) {
    double d = lua_tonumber(L, 1);
    lua_pushnumber(L, sin(d));
    return 1;
}

static const struct luaL_Reg mylib[] = {
    {"l_sin", l_sin},
    {NULL, NULL},
};

int luaopen_mylib(lua_State *L) {
    luaL_newlib(L, mylib);
    return 1;
}
