#pragma once
/**
* @file PopUpState
* Should pop over all other screens with a yes no option
* should be passed a callback function
* should be passed text options, including question text, and confirm/reject text
*/

class PopUpState : BaseGameState
{
public:
    void Init(GameEngine* game) = 0;
    void Cleanup(GameEngine* game) = 0;

    void PauseState(GameEngine* game) = 0;
    void ResumeState(GameEngine* game) = 0;

    void HandleEvents(GameEngine* game) = 0;
    void Update(GameEngine* game) = 0;
    void Draw(GameEngine* game) = 0;

    PopUpState* Instance(std::string name, std::string confirm_choice, std::string reject_choice, std::string question, boost::function confirm_callback);

protected:
    PopUpMenu() { } // Constructor
    std::string m_sName;
    std::string m_sConfirmChoice;
    std::string m_sRejectChoice;
    std::string m_sQuestion;
    boost::function m_cCallbackOnConfirm;
    // callback
    GameLog* logger;
};
