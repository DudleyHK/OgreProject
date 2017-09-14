/*



*/
#include "OgreApp.h"
// ---------------------
#include "OGRE\OgreWindowEventUtilities.h"

#include "ProjectSetupDefines.h"




Ogre::RenderWindow* OgreApp::getWindow() const
{
	return window;
}



const bool OgreApp::run()
{
	root = OGRE_NEW Ogre::Root("", "", "Ogre.log");

	if (!loadPlugins())      return false;
	if (!loadRenderSystem()) return false;
	if (!loadRenderWindow()) return false;


	while (!window->isClosed())
	{
		Ogre::WindowEventUtilities::messagePump();
	}


	return true;
}


const bool OgreApp::loadPlugins()
{
	pluginNames.push_back(renderSystem);
	for (auto plugin : pluginNames)
	{
		if (OGRE_DEBUG_MODE)
		{
			plugin.append("_d");
		}
		root->loadPlugin(plugin);
	}
	return true;
}



const bool OgreApp::loadRenderSystem()
{
	const Ogre::RenderSystemList& list = root->getAvailableRenderers();
	if (list.empty()) return false;

	Ogre::RenderSystem* syst = list[0];
	root->setRenderSystem(syst);
	root->initialise(false, "");

	return true;
}



const bool OgreApp::loadRenderWindow()
{
	Ogre::NameValuePairList params;
	params["FSAA"] = "0";
	params["vsync"] = "true";

	window = root->createRenderWindow(windowTitle, windowWidth, windowHeight, fullscreen, &params);
	if (!window) return false;
	
	return true;
}



void OgreApp::shutdown()
{
	if (root)
	{
		OGRE_DELETE root;
		root = nullptr;
	}
}
