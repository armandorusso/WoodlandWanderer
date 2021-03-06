#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "Assets.h"
#include "Model.h"
#include "Parameters.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>

class CollidableModel : public Model {
public:
	CollidableModel() = default;
	CollidableModel(GLuint VAO, GLuint numVertices, glm::vec3 color);
	~CollidableModel();

	void setModelTransformMatrix(glm::mat4 modelTransformMatrix) override;
	void setColliderTransformMatrix(glm::mat4 transformMatrix) { this->colliderTransformMatrix = transformMatrix; };
	glm::mat4 getColliderTransformMatrix() { return colliderTransformMatrix; }
	GLuint    getColliderVAO() { return colliderVAO; }
	glm::vec3 getColliderPosition();
	glm::vec3 getColliderScale();
	glm::vec3 getCollidableDimensions() { return glm::vec3(this->getColliderScale().x, 0, this->getColliderScale().z); };
	void draw(const GLuint& worldMatrixLocation, const GLuint& colorLocation) override;

private:
	GLuint colliderVAO = AssetsService::getInstance()->getCube().getVAO();
	glm::mat4 colliderTransformMatrix = glm::mat4(1.0f);
};