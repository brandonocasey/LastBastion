#pragma once
/**
* @file PopUpState
* Should pop over all other screens with a yes no option
* should be passed a callback function
* should be passed text options, including question text, and confirm/reject text
*/
#include "../Utils.h"
#include "../Classes/GameEngine.h"
#include "../BaseClasses/BaseMenu.h"

class PopUpState : BaseMenu
{
public:

    void Init(std::string question, std::string confirm_answer, std::string deny_answer);
    void Cleanup(GameEngine* game);

    void PauseState(GameEngine* game);
    void ResumeState(GameEngine* game);

    void HandleEvents(GameEngine* game);
    void Update(GameEngine* game);
    void Draw(GameEngine* game);

    void RejectCallback(GameEngine* game);

protected:
    std::string m_sName;
    std::string m_sConfirmChoice;
    std::string m_sRejectChoice;
    std::string m_sQuestion;
    boost::function<void(GameEngine* game)> m_fMenuCallback;
    // callback
    GameLog logger;
};
