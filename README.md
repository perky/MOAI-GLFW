MOAI-GLFW
=========

GLFW OS X host for MOAI.

Create your windows as normal:

MOAISim.openWindow().

# MOAIHostMgr
A singleton that interfaces GLFW.

## MOAIHostMgr.setWindowSize( width, height )
Sets the size of the window.

## MOAIHostMgr.getTime()
Returns the value of the high precision timer. The time is measured in seconds, and is
returned as a double precision ﬂoating point value.

## MOAIHostMgr.getVideoModes( maxNumberOfVideoModesToReturn )
Returns a table of available video modes. Each video modes is represented as a table with the following keys:
* width
* height
* redBits
* greenBits
* blueBits

## MOAIHostMgr.getDesktopVideoMode()
Returns the current video mode of the desktop, see above.

## MOAIHostMgr.setOnWindowChangedSizeCallback( callbackFunction )
Set a callback that is called whenver the size of the window changes.
    function callbackFunction( width, height )

## MOAIHostMgr.setOnWindowCloseCallback( callbackFunction )
Set a callback that is called when a user requests that the window should be
closed, typically by clicking the window close icon (e.g. the cross in the upper right corner of a
window under Microsoft Windows), and on Mac OS X also when selecting Quit from the
application menu.
    function callbackFunction()

## MOAIHostMgr.minimiseWindow()

## MOAIHostMgr.restoreWindow()

## MOAIHostMgr.getNumberOfProcessors()
Return's the number of processors available.

## MOAIHostMgr.enable( token ) / MOAIHostMgr.disable( token )
Enable and disable certain settings. Token can be one of the followin constants:
* HOST_MOUSE_CURSOR
* HOST_KEY_REPEAT
* HOST_STICKY_KEYS
* HOST_STICKY_MOUSE_BUTTONS
* HOST_SYSTEM_KEYS
See http://www.glfw.org/GLFWReference276.pdf for information on this.