#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "World.h"
#include "ResourceManager.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "stb_image.h"
#include "Texture.h"


const unsigned int SCREEN_WIDTH = 1280;
const unsigned int SCREEN_HEIGHT = 720;

// Call back function for resizing window
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// Call back function for keys
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Call back function for closing window when ESC key is pressed
void closeWindow(GLFWwindow *window);

World Sandbox = World(SCREEN_WIDTH, SCREEN_HEIGHT);

int main()
{
    // Disables MacOs from changing working directory to Resources when initializing glfw
    glfwInitHint(GLFW_COCOA_CHDIR_RESOURCES, GLFW_FALSE);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // Apple deprecated older OpenGL functionality and requires forward-compatible 
    // contexts for OpenGL 3.2 and later in its core-profile implementation
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);


    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "PhysicsCollider", nullptr, nullptr);


    if (window == nullptr)
    {
        std::cerr << "Failed to create GLFW window \n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD\n";
        return -1;
    }

    // Registering callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    // Render Loop
    while (!glfwWindowShouldClose(window))
    {

        closeWindow(window);

        glfwPollEvents();


        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }
    ResourceManager::Clear();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}


void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            Sandbox.Keys[key] = true;

        }
        else if (action == GLFW_RELEASE)
        {
            Sandbox.Keys[key] = false;
        }
    }
}

void closeWindow(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}
