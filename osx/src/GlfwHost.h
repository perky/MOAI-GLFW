//
//  GlfwHost.h
//  MOAI-GLFW
//
//  Created by Luke Perkin on 19/08/2012.
//  Copyright (c) 2012 Locofilm. All rights reserved.
//

#ifndef MOAI_GLFW_GlfwHost_h
#define MOAI_GLFW_GlfwHost_h

int		GlfwHost				( int argc, const char * argv[] );
void    LoadAKUModules          ();
void    RefreshAKUContext       ();
void    SetupInputCallbacks     ();
void    SetupInputMapping       ();
void    SetupWindowMapping      ();
void    SetupErrorMapping       ();
void    GlfwEventLoop           ();

static void GLFWCALL onKeyboardKey     ( int key, int action );
static void GLFWCALL onKeyboardChar    ( int unicode, int action);
static void GLFWCALL onMouseButton     ( int button, int action );
static void GLFWCALL onMouseMove       ( int x, int y );
static void GLFWCALL onMouseWheel      ( int pos );

void	_AKUEnterFullscreenFunc ();
void	_AKUExitFullscreenFunc	();
void	_AKUOpenWindowFunc		( const char* title, int width, int height );

#endif
