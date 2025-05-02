#include <algorithm>
#include <chrono>
#include <functional>
#include <string>

#include <vector>
class GameTimer
{
  public:
    using Callback = std::function<void()>;

    struct TimedEvent
    {
        float triggerTime;
        Callback callback;
        bool triggered = false;
    };

    GameTimer();
    void Start();
    void Pause();
    void Reset();
    void Update(float deltaTime);
    void AddTimedEvent(float time, Callback callback);
    float GetElapsedTime() const;
    bool IsRunning() const;
    std::string GetFormattedTime() const;

  private:
    float m_elapsedTime;
    bool m_running;
    std::vector<TimedEvent> m_events;
};