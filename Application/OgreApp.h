/*



*/
#pragma once

#include "OGRE\OgreString.h"
#include "OGRE\OgreStringVector.h"


namespace Ogre
{
	class RenderWindow;
	class Root;
}


class OgreApp
{
public:
	OgreApp() = default;
	~OgreApp() = default;

	Ogre::RenderWindow* getWindow() const;


	const bool run();
	const bool loadPlugins();
	const bool loadRenderSystem();
	const bool loadRenderWindow();

	void shutdown();

private:
	Ogre::Root* root = nullptr;
	Ogre::RenderWindow* window = nullptr;
	Ogre::StringVector pluginNames;
	const Ogre::String renderSystem = "RenderSystem_Direct3D11";

	Ogre::String windowTitle = "";
	unsigned int windowWidth = 800;
	unsigned int windowHeight = 600;
	bool fullscreen = false;

};

