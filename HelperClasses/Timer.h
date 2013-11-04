#pragma once
#include <math.h> // Enables us to round down to get seconds using floor()
#include <SDL2/SDL.h>

class Timer
{
public:
    void Start(int end_time);
    bool Started();
    bool Ended();
    void Restart();

    void Increment();
    int SecondsElapsed();
    void Cleanup();
    void Init();

private:
    int m_iStartTime;
    int m_iEndTime;
    int m_iTimeElapsed;
    int m_iDuration;
    int m_iCurrentTime;
};
