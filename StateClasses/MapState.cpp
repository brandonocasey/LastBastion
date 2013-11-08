#include "MapState.h"

MapState MapState::m_MapState;

void MapState::Init(GameEngine* game)
{
//    m_cMap = game->AssetLoader->GetCurrentMap();

    // Render a loading screen

    // Load All Map Assets
    //
    // Load All sound Assets
    //
    // Load All graphic Assets
    //
    // Render the map in the background
    //
    // Clear the loading screen
    //
    // Present the map
    // Initiate collision array with map size
}

void MapState::LoadMap(GameEngine* game)
{
    /*
    // Loop through m_cMap tiles
    for (int i = 0; i < map->GetNumTilesets(); ++i)
    {
    // Get a tileset.
    const Tmx::Tileset *tileset = map->GetTileset(i);

    TileSet * formatted_tileset;
    tileset->Init(Game, tileset->GetTileWidth(), tileset->GetTileHeight(), tileset->GetImage()->GetSource());

    std::vector<Tmx::Tile*> tiles = tileset->GetTiles();

    // Loop Through Tile Properties
    while (tiles.size() > 0)
    {
    // Get a tile from the tileset.
    const Tmx::Tile *tile = (tiles.back());

    // Print the properties of a tile.
    std::map< std::string, std::string > list = tile->GetProperties().GetList();
    std::map< std::string, std::string >::iterator iter;
    for (iter = list.begin(); iter != list.end(); ++iter)
    {
    if(iter->first == "collision")
    {
    bool collision = false;
    if( iter->second == 'true' )
    {
    collision = true;
    }

    formatted_tileset->SetCollision(tile->GetId(), collision);
    }
    }
    tiles.pop_back();
    }

    m_hTileSet[i] = formatted_tileset;
    */
}

/**
* Set our collision vector to the correct size, so we can put collision in there
* @param game             Pointer to game
* @param map_height_tiles The height in tiles of our map
* @param map_width_tiles  the width in tiles of our map
*/
void MapState::LoadCollision(GameEngine* game, int map_height_tiles, int map_width_tiles)
{
    m_vviCollision.resize(map_height_tiles);
    for(std::vector< std::vector<int> >::size_type i = 0; i != m_vviCollision.size(); i++)
    {
        m_vviCollision[i].resize(map_width_tiles);
    }

    /* Loop Through Collision
    for(std::vector< std::vector<int> >::size_type i = 0; i != collision.size(); i++)
    {
    for(std::vector<int>::size_type z = 0; z != collision[i].size(); z++)
    {
    std::cout << "i : " << i << " z: " << z << " value: " << collision[i][z] << std::endl;
    }
    }
    */
}

void MapState::Cleanup(GameEngine* game)
{
    // Unload all the assets
    //
    // Cleanup pointers
}

void MapState::PauseState(GameEngine* game)
{
    // When the game loses focus
}

void MapState::ResumeState(GameEngine* game)
{
    // When the game regains focus
}

void MapState::HandleEvents(GameEngine* game)
{
    // Handle all the player events
}
void MapState::Update(GameEngine* game)
{
   // UpdateTowers(game);
    //UpdateCollision(game);
//    UpdateMonsters(game);
    //UpdatePlayer(game);
}
void MapState::Draw(GameEngine* game)
{
    DrawMap(game);
    DrawMonsters(game);
    DrawTowers(game);
    DrawPlayer(game);
}
void MapState::PauseGameplay(GameEngine* game)
{
    game->PushState( PauseGameState::Instance() );
}
void MapState::DrawMap(GameEngine* game)
{
    /*
    logger->Log("Drawing Map");
    for (int i = 0; i < m_cMap->GetNumLayers(); ++i)
    {
        const Tmx::Layer *layer = m_cMap->GetLayer(i);

        for (int y = 0; y < layer->GetHeight(); ++y)
        {
            for (int x = 0; x < layer->GetWidth(); ++x)
            {
                int tileset_id = layer->GetTile(x,y).tilesetId;
                // Draw a tile these things
                m_hTileSet[tileset_id]->DrawTile(game, x, y, layer->GetTileId(x, y));
                if( m_hTileSet[tileset_id]->DrawTile(tileset_id) )
                {
                    // get the collision and add it to our collision array for one tile
                    m_vviCollision[x][y] = m_hTileSet[tileset_id]->GetCollision(tileset_id);
                }
            }
        }
    }
    */
}

void MapState::DrawMonsters(GameEngine* game)
{
    if( ! m_vMonsterList.empty() )
    {
        for(BaseMonster* monster : m_vMonsterList)
        {
            //monster->Draw(game);
        }
    }
}
void MapState::DrawTowers(GameEngine* game)
{
    if( ! m_vTowerList.empty() )
    {
        for(BaseTower* tower : m_vTowerList)
        {
            //tower->Draw(game);
        }
    }
}
void MapState::DrawPlayer(GameEngine* game)
{
}

void MapState::UpdateMonsters()
{
    if( m_vMonsterList.empty() )
    {
        // Spawns at spawn point
        //m_vTowerList.push_back( new BaseMonster)
    }
    else
    {
        for(BaseMonster* monster : m_vMonsterList)
        {
            //monster.Update(m_vviCollision);
        }
    }
}

void MapState::UpdateTowers()
{
    if( m_vTowerList.empty() )
    {
       // m_vTowerList.push_back( new TestTower(5, 5) );
    }
    else
    {
        for(BaseTower* tower : m_vTowerList)
        {
            //tower->Update(m_vMonsterList);
        }
    }
}