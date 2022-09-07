// Author:        Arash Fatehi
// Date:          2022-08-18
// Description:

#ifndef TPPG_H
#define TPPG_H

// Standard Headers
#include <memory>

// Local Headers
#include "async/event_handler.hpp"
#include "utils/input_parser.hpp"
#include "utils/configs.hpp"


namespace TPP
{
    class TPP
    {
    public:
        TPP(int argc, char** argv);
        void Exec();
    private:
    private:
        // Configs
        std::shared_ptr<InputParser> inputParser;
        std::shared_ptr<EventHandler> eventHandler;
        std::shared_ptr<Configs> configs;
    };
} // namespace TPP

#endif // TPPG_H
