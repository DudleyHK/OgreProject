/*



*/
#include <memory>
#include <Windows.h>


#include "OgreApp.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	std::unique_ptr<OgreApp> ogreApp = std::make_unique<OgreApp>();
	if (!ogreApp->run());
		// Oops Error

	ogreApp->shutdown();
	return 0;
}