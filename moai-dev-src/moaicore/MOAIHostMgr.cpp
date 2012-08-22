// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include "pch.h"
#include <moaicore/MOAIHostMgr.h>
#include <GL/glfw.h>

//================================================================//
// lua
//================================================================//

int MOAIHostMgr::_setWindowSize ( lua_State* L )
{
	int width = lua_tointeger(L, 1);
	int height = lua_tointeger(L, 2);
	glfwSetWindowSize( width, height );
	return 0;
}

int MOAIHostMgr::_getTime( lua_State* L )
{
	double time = glfwGetTime();
	lua_pushnumber(L, time);
	return 1;
}

static void pushLuaKeyNumberValue( lua_State* L, const char* s, int value )
{
	lua_pushstring(L, s);
	lua_pushnumber(L, value);
	lua_settable(L, -3);
}

int MOAIHostMgr::_getVideoModes( lua_State* L )
{
	int maxModes = lua_tointeger(L, 1);
	int numModes;
	GLFWvidmode videoModes[ maxModes ];
	numModes = glfwGetVideoModes(videoModes, maxModes);
	
	lua_newtable(L);
	int luaVideoModesTableIndex = lua_gettop(L);
	
	for (int i = 0; i < numModes; i++) {
		GLFWvidmode videoMode = videoModes[i];
		lua_pushnumber(L, i + 1);
		lua_newtable(L);
		pushLuaKeyNumberValue(L, "width",		videoMode.Width);
		pushLuaKeyNumberValue(L, "height",		videoMode.Height);
		pushLuaKeyNumberValue(L, "redBits",		videoMode.RedBits);
		pushLuaKeyNumberValue(L, "greenBits",	videoMode.GreenBits);
		pushLuaKeyNumberValue(L, "blueBits",	videoMode.BlueBits);
		lua_settable(L, luaVideoModesTableIndex);
	}
	
	return 1;
}

int MOAIHostMgr::_getDesktopVideoMode( lua_State* L )
{
	GLFWvidmode videoMode;
	glfwGetDesktopMode(&videoMode);
	lua_newtable(L);
	pushLuaKeyNumberValue(L, "width", videoMode.Width);
	pushLuaKeyNumberValue(L, "height", videoMode.Height);
	pushLuaKeyNumberValue(L, "redBits", videoMode.RedBits);
	pushLuaKeyNumberValue(L, "greenBits", videoMode.GreenBits);
	pushLuaKeyNumberValue(L, "blueBits", videoMode.BlueBits);
	return 1;
}

int MOAIHostMgr::_setOnWindowChangedSizeCallback( lua_State* L )
{	
	MOAI_LUA_SETUP(MOAIHostMgr, "U");
	MOAIHostMgr::Get().mOnWindowChangedSize.SetStrongRef(state, 1);
	return 0;
}

int MOAIHostMgr::_setWindowPos( lua_State *L )
{
	int x = lua_tointeger(L, 1);
	int y = lua_tointeger(L, 2);
	glfwSetWindowPos(x, y);
	return 0;
}

int MOAIHostMgr::_minimiseWindow( lua_State* L )
{
	UNUSED(L);
	glfwIconifyWindow();
	return 0;
}

int MOAIHostMgr::_restoreWindow( lua_State* L )
{
	UNUSED(L);
	glfwRestoreWindow();
	return 0;
}

int MOAIHostMgr::_getNumberOfProcessors( lua_State* L )
{
	int processors = glfwGetNumberOfProcessors();
	lua_pushinteger(L, processors);
	return 1;
}

int MOAIHostMgr::_enable( lua_State* L )
{
	int token = lua_tointeger(L, 1);
	glfwEnable(token);
	return 0;
}

int MOAIHostMgr::_disable( lua_State* L )
{
	int token = lua_tointeger(L, 1);
	glfwDisable(token);
	return 0;
}

void GLFWCALL onWindowSizeChanged( int width, int height );
void GLFWCALL onWindowSizeChanged( int width, int height )
{
	MOAILuaStateHandle state = MOAIHostMgr::Get().GetOnWindowSizeChangedLuaFunction().GetSelf();
	lua_pushnumber(state, width);
	lua_pushnumber(state, height);
	state.DebugCall(2, 0);
}

void GLFWCALL onWindowClosed();
void GLFWCALL onWindowClosed()
{
	MOAILuaStateHandle state = MOAIHostMgr::Get().GetOnWindowClosedLuaFunction().GetSelf();
	state.DebugCall(0, 0);
}

MOAILuaRef MOAIHostMgr::GetOnWindowSizeChangedLuaFunction()
{
	return mOnWindowChangedSize;
}

MOAILuaRef MOAIHostMgr::GetOnWindowClosedLuaFunction()
{
	return mOnWindowClosed;
}

//================================================================//
// MOAIHostMgr
//================================================================//

//----------------------------------------------------------------//
MOAIHostMgr::MOAIHostMgr () {
	// register all classes MOAIHostMgr derives from
	// we need this for custom RTTI implementation
	RTTI_BEGIN
		RTTI_EXTEND ( MOAILuaObject )
		// and any other objects from multiple inheritance...
		// RTTI_EXTEND ( MOAIFooMgrBase )
	RTTI_END
	
	glfwSetWindowSizeCallback(onWindowSizeChanged);
}

//----------------------------------------------------------------//
MOAIHostMgr::~MOAIHostMgr () {
}

//----------------------------------------------------------------//
void MOAIHostMgr::RegisterLuaClass ( MOAILuaState& state ) {
	// call any initializers for base classes here:
	// MOAIFooBase::RegisterLuaClass ( state );
	// also register constants:
	// state.SetField ( -1, "FOO_CONST", ( u32 )FOO_CONST );
	state.SetField(-1, "HOST_MOUSE_CURSOR", (u32)GLFW_MOUSE_CURSOR);
	state.SetField(-1, "HOST_KEY_REPEAT", (u32)GLFW_KEY_REPEAT);
	state.SetField(-1, "HOST_STICKY_KEYS", (u32)GLFW_STICKY_KEYS);
	state.SetField(-1, "HOST_STICKY_MOUSE_BUTTONS", (u32)GLFW_STICKY_MOUSE_BUTTONS);
	state.SetField(-1, "HOST_SYSTEM_KEYS", (u32)GLFW_SYSTEM_KEYS);
	
	// here are the class methods:
	luaL_Reg regTable [] = {
		{ "setWindowSize",		_setWindowSize },
		{ "getTime",			_getTime },
		{ "getVideoModes",		_getVideoModes },
		{ "getDesktopVideoMode", _getDesktopVideoMode },
		{ "setOnWindowChangedSizeCallback", _setOnWindowChangedSizeCallback },
		{ "setOnWindowCloseCallback", _setOnWindowCloseCalback },
		{ "minimiseWindow", _minimiseWindow },
		{ "restoreWindow", _restoreWindow },
		{ "setWindowPosition", _setWindowPos },
		{ "getNumberOfProcessors", _getNumberOfProcessors },
		{ "enable", _enable },
		{ "disable", _disable },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}
