// Author:        Arash Fatehi
// Date:          2022-08-18
// Description:

// Local Headers
#include "tpp.hpp"

namespace TPP
{
    TPP::TPP(int argc, char** argv)
    {
        configs = std::make_unique<Configs>();
        inputParser = std::make_unique<InputParser>(argc, argv);
        eventHandler = std::make_unique<EventHandler>();
    }

    void TPP::Exec()
    {
        
        eventHandler->Add(
        [&](void* )
        {
            std::string parsed = inputParser->Parse(configs);
            // if (parsed != "")
            // {

            //     eventHandler->AddTerminateEvent();
            // }
        });

    eventHandler->Exec();
    }

} // namespace TPP
