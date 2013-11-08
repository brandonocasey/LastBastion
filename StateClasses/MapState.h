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
#include "../BaseClasses/BaseTower.h"
#include "../BaseClasses/BaseMonster.h"
#include "../GameClasses/SpriteSheet.h"
#include "../Utils.h"
#include "../Classes/GameEngine.h"
#include "../BaseClasses/BaseGameState.h"


#include "../StateClasses/PauseGameState.h"

class MapState : public BaseGameState
{
public:
    void Init(GameEngine* game);
    void Cleanup(GameEngine* game);
    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);
    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);
    void LoadMap(GameEngine* game);
    void LoadCollision(GameEngine* game, int map_height_tiles, int map_width_tiles);

    void PauseGameplay(GameEngine* game);
    void DrawMap(GameEngine* game);
    void DrawTile(GameEngine* game);
    void DrawMonsters(GameEngine* game);
    void DrawTowers(GameEngine* game);
    void DrawPlayer(GameEngine* game);

    void UpdateMonsters();
    void UpdateTowers();

    static MapState* Instance()
    {
        return &m_MapState;
    }
    std::string GetName()
    {
        if( m_sName.empty() )
        {
            m_sName = "Unknown";
        }
        return m_sName;
    }

private:

    static MapState m_MapState;
    std::vector<BaseMonster*> m_vMonsterList;
    std::vector<BaseTower*> m_vTowerList;
    std::vector< std::vector<int> > m_vviCollision;
    std::hash_map<int, SpriteSheet*> m_hTileSet;
};
