#pragma once

#include "../BaseClasses/BaseMenu.h"
#include "../StateClasses/SettingsState.h"
#include "../StateClasses/LevelSelectState.h"
#include "../StateClasses/LoadGameState.h"
class PauseGameState : BaseMenu
{
public:
    void Init(GameEngine* game);
    void ResumeState(GameEngine* game);
    void PauseState(GameEngine* game);
    void Cleanup(GameEngine* game);
    void Draw(GameEngine* game);
    void Update(GameEngine* game);
    void HandleEvents(GameEngine* game);

    void QuitGameCallback(GameEngine* game);
    void QuitToMenuCallback(GameEngine* game);
    void SaveCallback(GameEngine* game);
    void LoadCallback(GameEngine* game);
    void SettingsCallback(GameEngine* game);
    void BackToGame(GameEngine* game);

private:
    GameLog logger;
};
