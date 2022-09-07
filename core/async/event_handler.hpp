// Author:        Arash Fatehi
// Date:          2022-08-19
// Description:

#pragma once

// Standard Headers
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <functional>
#include <queue>

// Local Header

namespace TPP
{
    class EventHandler
    {
    public:
        void Exec();
        void Add(const std::function<void(void*)>& _event);
        void AddTerminateEvent();
        void AddIdleEvent(const std::chrono::duration<int, std::micro>& _time_out);

    private:
        void AddIdleEvent();

    private:
        unsigned int miliseconds = 250;
        std::chrono::duration<unsigned int, std::micro> timeOut = std::chrono::milliseconds(miliseconds);
        std::atomic<bool> finished = {false};
        std::queue<std::function<void(void*)>> queue;
        std::condition_variable condition;
        std::mutex conditionMutex;
    };

} // namespace TPP
