#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <iostream>
#include "Vector2.h"
#include "GameObject.h"
#include "Player.h"
#include "Ball.h"
#include <vector>


using namespace std;

vector<GameObject*> objects;

void initialize_objects(GLFWwindow* window)
{
	objects.push_back(new Player(new Vector2(400.f, 50.f), 100.f, 30.f, window));
	objects.push_back(new Ball(new Vector2(400.f, 200.f), 10.f, 10.f));

	float xPos = 30.f;
	for (int i = 0; i < 19; i++)
	{
		objects.push_back(new GameObject(new Vector2(xPos, 550.f), 30.f, 20.f));
		xPos += 40.f;
	}
}

void render_loop()
{
	// set background color and drawing color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(10);
	glLineWidth(2.5);
	glColor3f(1.0, 1.0, 1.0);

	// update all game objects
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update();
	}
}

int main(int argc, char *argv[])
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(800, 600, "Breakout", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}


	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// set up view
	glViewport(0, 0, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0, 800.0, 0.0, 600.0, 0.0, 1.0); // this creates a canvas you can do 2D drawing on

	initialize_objects(window);

	while (!glfwWindowShouldClose(window))
	{
		render_loop();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	exit(EXIT_SUCCESS);
}