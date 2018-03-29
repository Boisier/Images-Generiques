//
//  ken02.hpp
//  Xcode
//
//  Created by Valentin Dufois on 19/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef ken02_hpp
#define ken02_hpp

//////////////////////
//Forward declarations
class Mesh;
class VectorImage;

#include "Scene.hpp"
namespace Scenes
{
	class ken02: public Scene
	{
	public:
		/**
		 Fast-forward method to instanciate, init and in the scene App
		 */
		static void load();

		/**
		 Initialize the scene
		 */
		void init();

		/**
		 Execute all the actions in the scene
		 */
		void execute();

		/**
		 Render the scene on the screen
		 */
		void render();

		/**
		 Destructor, used to properly free all the memory used by the scene
		 */
		~ken02() {};

	private:

		//Elements
		std::vector<VectorImage*> m_svg;
		std::vector<Mesh*> m_mesh;
		float m_zoomLevel;
	};
}

#endif /* ken02_hpp */
