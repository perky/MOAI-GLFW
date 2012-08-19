//
//  GLFWManager.h
//  MOAI-GLFW
//
//  Created by Luke Perkin on 19/08/2012.
//  Copyright (c) 2012 Locofilm. All rights reserved.
//

#ifndef MOAI_GLFW_GLFWManager_h
#define MOAI_GLFW_GLFWManager_h

#include <string>
using namespace std;


class GLFWManager {
public:
    static GLFWManager* Instance();
    ~GLFWManager();
    void RegisterLuaClass();
protected:
    GLFWManager();
private:
    static GLFWManager* pInstance;
    int _setWindowSize  ( lua_State *L );
};

#endif
