//
//  Shape.hpp
//  Xcode
//
//  Created by Valentin Dufois on 16/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef Shape_hpp
#define Shape_hpp

//////////////////////
//Forward declarations
class Mesh;

#include "libraries.hpp"

#include "Utils/DrawCursor.hpp"
#include "Bezier.hpp"

class Shape
{
public:
	Shape();

	Shape(const std::vector<Bezier> &paths):
	m_paths(paths) {};

	Shape(const float &posX, const float &posY, const float &width, const float &height):
		m_size(glm::vec2(width, height)),
		m_position(glm::vec2(posX, posY)) {};

	Shape(const std::vector<Bezier> &paths, const float &left, const float &bottom, const float &right, const float &top):
		m_size(glm::vec2(right - left, top - bottom)),
		m_position(glm::vec2(left, bottom)),
		m_paths(paths) {};

	/**
	 Return all the paths in the shape

	 @return Vector of bezier paths
	 */
	inline std::vector<Bezier> getPaths() const { return m_paths; };

	/**
	 Return all the points in the shape

	 @return Vector of 2D points
	 */
	inline std::vector<glm::vec2> getPoints() const { return getPoints(1); };

	/**
	 Return all the points in the shape
	 with n points per path

	 @return Vector of 2D points
	 */
	std::vector<glm::vec2> getPoints(const float &precision) const;

	/**
	 Return the shape as a Mesh

	 @return A Mesh
	 */
	Mesh * getMesh() const;

	/////////////////
	//Transformations

	inline DrawCursor * getCursor() { return &m_cursor; };

	inline void applyCursor()
	{
		applyCursor(&m_cursor);
		m_cursor.setMatrix(glm::mat4(1.0));
	};

	void applyCursor(DrawCursor * cursor);

private:

	//Dimensions
	glm::vec2 m_size;
	glm::vec2 m_position;

	std::vector<Bezier> m_paths;

	DrawCursor m_cursor;
};

#endif /* Shape_hpp */
