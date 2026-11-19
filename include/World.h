#ifndef WORLD_H
#define WORLD_H

enum WorldState
{
    WORLD_NORMAL,
    WORLD_STOP,
};

enum Planet // Need to make a separate class or maybe load through a file with stats (e.g. gravity)
{
    EARTH,
    MARS,
    VENUS,
    JUPITER,
    SATURN,
    MERCURY,
    PLUTO,
    URANUS,
    NEPTUNE
};


class World
{
    public:
    
        WorldState      State;
        bool            Keys[1028];
        unsigned int    Width, Height;

        // Constructor + Destructor
        World(unsigned int width, unsigned int height);
        ~World();

        // Initializes the world (Loads shaders/textures)
        void Init();

        // Game Loop
        void ProcessInput(float dt);
        void Update(float dt);
        void Render();


};




#endif
