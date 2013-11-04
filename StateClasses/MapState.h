#pragma once

/**
* @file MapState
* Required Features:
* Needs to be able to switch to Pause State on button press
* Needs to have a layer for map, monsters, towers, UI, and player control
* Needs to spawn monster on button press or thirty seconds after a wave
* Needs to handle user tower building
* Needs to let the user move around the map when the mouse hits an edge
* Needs to let the user zoom in and out
* Needs to maintain a current collision array
*
*/

class MapState : BaseGameState
{
public:
    virtual void Init(GameEngine* game) = 0;
    virtual void Cleanup(GameEngine* game) = 0;

    virtual void PauseState(GameEngine* game) = 0;
    virtual void ResumeState(GameEngine* game) = 0;

    virtual void HandleEvents(GameEngine* game) = 0;
    virtual void Update(GameEngine* game) = 0;
    virtual void Draw(GameEngine* game) = 0;

    void PauseGameplay(GameEngine* game);
    void DrawMap(GameEngine* game);
    void DrawMonsters(GameEngine* game);
    void DrawTowers(GameEngine* game);
    void DrawPlayer(GameEngine* game);
    void LoadMap(GameEngine* game);

private:
    std::vector m_vMonsterList;
    std::vector m_vTowerList;
    int* collision;
    MapState();
    ~MapState();
};
