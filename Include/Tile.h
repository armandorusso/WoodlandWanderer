#pragma once
#include "Model.h"
#include "../Include/Colours.h"
#include "../Include/Assets.h"
#include "Firefly.h"
#include "Parameters.h"
#include "CollidableModel.h"
#include "Tree.h"
#include "Grass.h"
#include "BigRock.h"
#include "SmallRock.h"


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class Tile {
public: 
	Tile() = default;
	~Tile();
	Tile(glm::vec3 translation);
	
	void draw(const GLuint& worldMatrixLocation, const GLuint& colorLocation);
	void setTranslation(glm::vec3 translation) { this->translation = translation; };
	Model* getOccupant() { return this->occupant; }

private:
	Model platform;
	Model* occupant; 
	Firefly firefly;
	glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
};