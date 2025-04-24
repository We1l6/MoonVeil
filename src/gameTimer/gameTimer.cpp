#include "gameTimer.h"

GameTimer::GameTimer() : m_elapsedTime(0.0f), m_running(false) {}

void GameTimer::Start() { m_running = true; }
void GameTimer::Pause() { m_running = false; }
void GameTimer::Reset()
{
    m_elapsedTime = 0.0f;
    m_events.clear();
}

void GameTimer::Update(float deltaTime)
{
    if (!m_running)
        return;

    m_elapsedTime += deltaTime;

    for (auto &event : m_events)
    {
        if (!event.triggered && m_elapsedTime >= event.triggerTime)
        {
            event.callback();
            event.triggered = true;
        }
    }
    m_events.erase(std::remove_if(m_events.begin(), m_events.end(),
                                  [](const TimedEvent &event)
                                  { return event.triggered; }),
                   m_events.end());
}

void GameTimer::AddTimedEvent(float time, Callback callback)
{
    m_events.push_back({time, callback, false});
}

std::string GameTimer::GetFormattedTime() const
{
    int minutes = static_cast<int>(m_elapsedTime) / 60;
    int seconds = static_cast<int>(m_elapsedTime) % 60;
    char buffer[6];
    snprintf(buffer, sizeof(buffer), "%02d:%02d", minutes, seconds);
    return std::string(buffer);
}
