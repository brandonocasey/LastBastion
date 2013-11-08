#include "PopUpState.h"

void PopUpState::Init(std::string question, std::string confirm_answer, std::string deny_answer, boost::function<void(GameEngine* game)> callback_function)
{
    m_sName = "PopUp";
    logger.Init(LOG_FILE, m_sName, LOG_LEVEL);

    m_sQuestion = question;
    m_sConfirmChoice = confirm_answer;
    m_sRejectChoice = deny_answer;

    //m_vMenuItems.push_back( new MenuItem(m_sConfirmChoice, boost::bind(&callback_function, this, _1)) );
    m_vMenuItems.push_back( new MenuItem(m_sRejectChoice, boost::bind(&PopUpState::RejectCallback, this, _1)) );
}

void PopUpState::RejectCallback(GameEngine* game)
{
    game->PopState();
}
void PopUpState::Cleanup(GameEngine* game)
{
}

void PopUpState::PauseState(GameEngine* game)
{
}
void PopUpState::ResumeState(GameEngine* game)
{
}

void PopUpState::HandleEvents(GameEngine* game)
{
}
void PopUpState::Update(GameEngine* game)
{
    UpdateMenuItems(game);
}
void PopUpState::Draw(GameEngine* game)
{
}