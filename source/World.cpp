#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "World.h"
#include "ResourceManager.h"

World::World(unsigned int width, unsigned int height)
: State(WORLD_NORMAL), Keys(), Width(width), Height(height) { }

World::~World()
{

}

void World::Init()
{
     // Load Shaders
    ResourceManager::LoadShader("Resources/Shaders/default.vert", "Resources/Shaders/default.frag", nullptr, "ShaderProgram");

       // Initialize projection matrix and configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(this->Width),
                        static_cast<float>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("ShaderProgram").Activate();
    ResourceManager::GetShader("ShaderProgram").setInt("image", 0);
    ResourceManager::GetShader("ShaderProgram").setMat4("projection", projection);


    
}

void World::ProcessInput(float dt)
{

}

void World::Update(float dt)
{

}

void World::Render()
{

}
