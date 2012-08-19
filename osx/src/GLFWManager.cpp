//
//  GLFWManager.cpp
//  MOAI-GLFW
//
//  Created by Luke Perkin on 19/08/2012.
//  Copyright (c) 2012 Locofilm. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <AKU.h>
#include <GL/glfw.h>
#include "GLFWManager.h"
//#include <lauxlib.h>
//#include <lua-headers/moai_lua.h>


GLFWManager* GLFWManager::pInstance = NULL;

GLFWManager* GLFWManager::Instance()
{
    if(pInstance == NULL)
    {
        pInstance = new GLFWManager();
    }
    return pInstance;
}

GLFWManager::GLFWManager()
{
    
}

GLFWManager::~GLFWManager()
{
    pInstance = NULL;
}

int GLFWManager::_setWindowSize( lua_State *L )
{
    /*
    int width = lua_tonumber(L, 1);
    int height = lua_tonumber(L, 1);
    glfwSetWindowSize(width, height);
     */
    return 0;
}

void GLFWManager::RegisterLuaClass()
{
    /*
    lua_State* L = AKUGetLuaState();
    luaL_Reg regTable [] = {
        {"setWindowSize", _setWindowSize},
        {NULL, NULL},
    };
    lua_createtable(L, 0, sizeof(regTable) / sizeof((regTable)[0]) - 1);
    luaL_setfuncs(L, regTable, 0);
    lua_setglobal(L, "GLFWManager");
     */
}

