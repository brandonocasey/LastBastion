#pragma once

#include "../Utils.h"
#include "../HelperClasses/AudioHelper.h"
#include "../HelperClasses/EventHelper.h"
#include "../HelperClasses/RenderHelper.h"
#include "../HelperClasses/SaveGameHandler.h"

class BaseGameState; // Forward deceleration so that we can use GameEngines in Base Game States

class GameEngine
{
public:
    // Creating and destroying the state machine
    int Init(const char* title, int width, int height, bool fullscreen);
    void Cleanup();

    // Transit between states
    void ChangeState(BaseGameState* state);
    void PushState(BaseGameState* state);
    void PopState();

    // The three important actions within a game loop
    // (these will be handled by the top state in the stack)
    void HandleEvents();
    void Update();
    void Draw();

    // Tells the main loop whether to keep looping or not.
    bool Running();

    // Run the main loop with only one function call
    void Run();

    // sets m_bRunning to false which makes running return false
    void Quit();

    AudioHelper* AudioHelper;
    RenderHelper* RenderHelper;
    //EventHelper* EventHelper;
    //SaveGameHandler* SaveHelper;

private:
    std::string m_sName;
    std::vector<BaseGameState*> states;
    GameLog *logger;
    bool m_bRunning;
};
