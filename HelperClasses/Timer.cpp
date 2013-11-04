#include "Timer.h"

void Timer::Init()
{
    Cleanup();
}
/**
* Start keeping track of time with an end time in mind
* @param end_time An end time in seconds that we will eventually reach
*/
void Timer::Start(int end_time)
{
    m_iDuration = (end_time * 1000);
    Restart();
}

/**
* Has the timer already been started?
* @return true if started, and false if not started
*/
bool Timer::Started()
{
    if( m_iStartTime )
    {
        return true;
    }

    return false;
}

/**
* Has the timer reached the duration?
* @return True if it has, false otherwise;
*/
bool Timer::Ended()
{
    if( m_iCurrentTime >= m_iEndTime )
    {
        return true;
    }

    return false;
}

/**
* Restart a timer that has already been started before
* uses the same duration
*/
void Timer::Restart()
{
    m_iStartTime = SDL_GetTicks();
    m_iEndTime = m_iStartTime  + m_iDuration;
}

/**
* Get the Amount of time that has elapsed so far in seconds, also increments current_time
* @return seconds_elapsed the amount of seconds that have passed.
*/
int Timer::SecondsElapsed()
{
    Increment();
    float seconds_elapsed = m_iCurrentTime - m_iStartTime;

    // seconds always rounded down
    seconds_elapsed = floor(seconds_elapsed/1000);

    return (int)seconds_elapsed;
}

/** Increment the current time so that our timer will end */
void Timer::Increment()
{
    m_iCurrentTime = SDL_GetTicks();
}

/**
* Zero out all of our timer variables
*/
void Timer::Cleanup()
{
    m_iStartTime = 0;
    m_iEndTime = 0;
    m_iDuration = 0;
    m_iTimeElapsed = 0;
    m_iCurrentTime = 0;
}