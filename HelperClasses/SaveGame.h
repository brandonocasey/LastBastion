#pragma once

#include "../Utils.h"
/**
* - Should be able to be given a file and parse all of its save data
* - Should be able to then return that data as something usable by
*     the LevelSelect Class
*/
class SaveGame
{
public:
    void Init(std::string character_name); // For use with a new game
    bool ParseSaveData(std::string save_location);
    bool SaveGameData();

    // Implement more methods as necessary
    std::string GetCharacterName();
    int GetRiches();
    int GetLevelsBeaten();
    int GetTalentPoints();

    void SetCharacterName(std::string character_name);
    void SetRiches(int riches);
    void SetLevelsBeaten(int levels_beaten);
    void SetTalentPoints(int talent_points);

private:
    std::string m_sSaveLocation;
    std::string m_sCharacterName;
    int m_iRiches;
    int m_iLevelsBeaten;
    int m_iTalentPoints;
};
