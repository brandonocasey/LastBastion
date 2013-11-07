#include "SaveGame.h"

void SaveGame::Init(std::string character_name)
{
    SetRiches(0);
    SetCharacterName(character_name);
    SetLevelsBeaten(0);
    SetTalentPoints(0);
}

bool SaveGame::ParseSaveData(std::string save_name)
{
    std::fstream save_file;
    std::string save_location = SAVE_FOLDER + save_name;
    save_file.open(save_location, std::ios::in);
    if (save_file.is_open())
    {
        std::string line;
        std::getline(save_file,line);

        SetCharacterName(line);

        getline (save_file,line);
        SetLevelsBeaten(boost::lexical_cast<int>(line));

        getline (save_file,line);
        SetTalentPoints(boost::lexical_cast<int>(line));

        /*
        try {
        int x = boost::lexical_cast<int>( "123" );
        } catch( boost::bad_lexical_cast const& ) {
        std::cout << "Error: input string was not valid" << std::endl;
        }
        */
        getline (save_file,line);
        SetRiches(boost::lexical_cast<int>(line));
    }
    else
    {
        return false;
    }

    save_file.close();
    return true;
}

bool SaveGame::SaveGameData()
{
    // Save all of the users save data to a file
    std::fstream save_file;
    if( m_sSaveLocation.empty() )
    {
        std::string save_location = SAVE_FOLDER + m_sCharacterName;
        m_sSaveLocation = save_location;
    }

    save_file.open( m_sSaveLocation, std::ios::out );
    save_file << m_sCharacterName << std::endl;
    save_file << m_iLevelsBeaten << std::endl;
    save_file << m_iTalentPoints << std::endl;
    save_file << m_iRiches << std::endl;

    save_file.close();
    return true;
}

// Implement more methods as necessary
std::string SaveGame::GetCharacterName()
{
    return m_sCharacterName;
}
int SaveGame::GetRiches()
{
    return m_iRiches;
}
int SaveGame::GetLevelsBeaten()
{
    return m_iLevelsBeaten;
}
int SaveGame::GetTalentPoints()
{
    return m_iTalentPoints;
}

void SaveGame::SetCharacterName(std::string character_name)
{
    m_sCharacterName = character_name;
}

void SaveGame::SetRiches(int riches)
{
    m_iRiches = riches;
}

void SaveGame::SetLevelsBeaten(int levels_beaten)
{
    m_iLevelsBeaten = levels_beaten;
}

void SaveGame::SetTalentPoints(int talent_points)
{
    m_iTalentPoints = talent_points;
}