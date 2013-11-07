#include "LevelSelectState.h"

// Singleton Yeah!
LevelSelectState LevelSelectState::m_LevelSelectState;

void LevelSelectState::Init(GameEngine* game)
{
    m_sName = "LevelSelect";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    if( game->AssetLoader->SaveFileLoaded() )
    {
        game->AssetLoader->LoadSaveData();
    }
    m_vMenuItems.push_back( new MenuItem("Quit Game", boost::bind(&LevelSelectState::QuitGameCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Quit to Menu", boost::bind(&LevelSelectState::QuitToMenuCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Shop", boost::bind(&LevelSelectState::ShopCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Talents", boost::bind(&LevelSelectState::TalentsCallback, this, _1) ) );
    m_vMenuItems.push_back( new MenuItem("Level 1", boost::bind(&LevelSelectState::LevelCallback, this, _1) ) );
}

void LevelSelectState::TalentsCallback(GameEngine* game)
{
    game->PushState( TalentState::Instance() );
}

void LevelSelectState::ShopCallback(GameEngine* game)
{
    game->PushState( ShopState::Instance() );
}
void LevelSelectState::QuitGameCallback(GameEngine* game)
{
    game->Quit();
}

void LevelSelectState::QuitToMenuCallback(GameEngine* game)
{
    game->ChangeState( MainMenu::Instance() );
}
void LevelSelectState::LevelCallback(GameEngine* game)
{
    std::string map_folder = MAP_FOLDER + "level1.tmx";
    game->AssetLoader->LoadMap( map_folder );
    game->ChangeState( MapState::Instance() );
}

void LevelSelectState::BackCallback(GameEngine* game)
{
    game->RenderHelper->ClearScreen();
    game->PopState();
}

void LevelSelectState::Cleanup( GameEngine* game )
{
    CleanupMenuItems(game);
}

void LevelSelectState::Update( GameEngine* game )
{
    UpdateMenuItems(game);
}

void LevelSelectState::Draw( GameEngine* game )
{
    DrawMenuItems(game);
}