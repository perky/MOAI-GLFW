//
//  main.cpp
//  MOAI-GLFW
//
//  Created by Luke Perkin on 19/08/2012.
//  Copyright (c) 2012 Locofilm. All rights reserved.
//

#include <iostream>
#include <GL/glfw.h>
#include "GlfwHost.h"

void initializeGLFW ();
void createOpenGLWindow ();

void initializeGLFW ()
{
    if( !glfwInit() )
    {
        exit(EXIT_FAILURE);
    }
}

void createOpenGLWindow()
{
    if( !glfwOpenWindow(1024, 768, 0, 0, 0, 0, 0, 0, GLFW_WINDOW) )
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
}

int main (int argc, const char * argv[])
{
    initializeGLFW();
    GlfwHost(argc, argv);
    
    std::cout << "Goodbye, World!\n";
    glfwTerminate();
    exit(EXIT_SUCCESS);
    return 0;
}
