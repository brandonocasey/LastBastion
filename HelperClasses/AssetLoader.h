#pragma once
#include "../Utils.h"

class AssetLoader
{
public:
    void Init();
    void LoadMap(std::string map_location);
    void LoadText(std::string text);
    void GetCurrentMap();
    bool SaveFilesExist(); // Check if save files exist
    void LoadCurrentSave();
    void SaveFileLoaded();
    void LoadSaveData();

private:
    //TmxMap* m_cMap;
    //SaveGame* m_cSaveFile;
};
