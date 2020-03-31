#pragma once
#include "LoadedObject.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class Forest {
public: 
	Forest();
	void draw(const GLfloat* value4fv, const GLfloat* value3fv, GLuint& worldMatrixLocationColor, GLuint colorLocation);
	GLuint getVAO() { return this->VAO; };

private:
	GLuint VAO;
	GLuint VBO;
	std::vector<glm::vec3> vertices;
};