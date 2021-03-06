#pragma once
#define M_PI 3.1415926535897932384626433832795

#include "CollidableModel.h";
#include <GL/glew.h>    // Include GLEW - OpenGL Extension Wrangler
#include <GLFW/glfw3.h> // cross-platform interface for creating a graphical context,
#include <glm/glm.hpp>  // GLM is an optimized math library with syntax to similar to OpenGL Shading Language
#include <glm/gtc/matrix_transform.hpp> // include this to create transformation matrices
#include <glm/common.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Assets.h"
#include "Colours.h"

class Snowman {
public:
	Snowman() = default;
	Snowman(GLuint worldMatrixLoc, 
			GLuint colorLoc, 
			int shader, 
			int sphereVerts, 
			GLuint cubeVAO, 
			GLuint sphereVAO);
	
	void update();

	void draw();
	void drawHelper(glm::mat4 part, glm::vec3 color);
	void drawBody(glm::mat4 part, glm::vec3 color);

	void scaleSnowman(GLFWwindow* window, const bool& shift, bool& canScaleIncrement);
	void rotateSnowman(GLFWwindow* window, const bool& shift, bool& canRotateIncrement);
	void translateSnowman(GLFWwindow* window, const bool& shift, bool& canMoveIncrement);
	void randomTranslationSnowman(GLFWwindow* window, const bool& shift, bool& canRandomPlacement);

	bool CheckCollision(std::vector<CollidableModel>& colliders);
	void CheckCollisionX(std::vector<CollidableModel> colliders, bool isColliding);
	void CheckCollisionZ(std::vector<CollidableModel> colliders, bool isColliding);

	void Snowman::enableRendering();
	void Snowman::disableRendering();

	glm::vec3 getDimensions();
	void adjustKeysToRotation();

	// debug purposes
	GLuint colliderVAO;
	glm::mat4 colliderTransformMatrix = glm::mat4(1.0f);

	glm::vec3 origin;
	glm::vec3 offset;
	float scaleFactor;
	float rotation;
	float globalSpeed;
	float chubbyFactor;

	glm::vec3 const snowmanColor = glm::vec3(0.97, 0.97, 1.0);
	glm::vec3 const snowmanBranchColor = glm::vec3(0.87f, 0.72f, 0.53f);
	glm::vec3 const buttonColor = glm::vec3(0.5f, 0.2f, 0.0f);

	glm::vec3 const carrotColor = glm::vec3(1.0f, 0.647f, 0.00f);
	glm::vec3 const hatColor = glm::vec3(0.0f, 0.0f, 0.0f);

	GLuint worldMatrixLocation;
	GLuint colorLocation;

	int shader;

	int sphereVertices;
	GLuint sphereVAO;
	GLuint cubeVAO;

	glm::mat4 leftFoot;
	glm::mat4 rightFoot;

	glm::mat4 base;
	glm::mat4 middle;
	glm::mat4 head;

	glm::mat4 button1;
	glm::mat4 button2;
	glm::mat4 button3;

	glm::mat4 leftArm;
	glm::mat4 leftArmBranch1;
	glm::mat4 leftArmBranch2;
	glm::mat4 rightArm;
	glm::mat4 rightArmBranch1;
	glm::mat4 rightArmBranch2;

	glm::mat4 hatBrim;
	glm::mat4 hatBody;

	glm::mat4 leftEye;
	glm::mat4 rightEye;
	glm::mat4 carrot;
	glm::mat4 mouth;

	float animate;
	float animateHat;

	bool isFreeRight;
	bool isFreeLeft;
	bool isFreeForwards;
	bool isFreeBackwards;

private:
	bool canRender = true;

};
