// Author:        Arash Fatehi
// Date:          2022-08-19
// Description:

// Standard Headers

// Local Headers
#include "event_handler.hpp"

namespace TPP
{

    void EventHandler::Exec()
    {
        while (!finished)
        {
            if (queue.empty())
            {
                AddIdleEvent();
            }
            else
            {
                std::function<void(void*)> next_event = queue.front();
                queue.pop();
                next_event(this);
            }
        }
    }

    void EventHandler::Add(const std::function<void(void*)>& _event)
    {
        std::lock_guard<std::mutex> lock(conditionMutex);
        queue.push(_event);
    }

    void EventHandler::AddIdleEvent(const std::chrono::duration<int, std::micro>& _time_out)
    {
        // clang-format off
        Add([&](void*)
            {
                std::unique_lock<std::mutex> lock(conditionMutex);
                condition.wait_for(lock, _time_out, 
                                   [=]{ return !queue.empty(); }); 
            });
        // clang-format on
    }

    void EventHandler::AddIdleEvent()
    {
        AddIdleEvent(timeOut);
    }

    void EventHandler::AddTerminateEvent()
    {
        Add([&](void*)
            { finished = true; });
    }

} // namespace TPP