// Author:        Arash Fatehi
// Date:          2022-08-18
// Description:

// Sandard Headers
#include <memory>
#include <thread>

// Local Headers
#include "tpp.hpp"
#include "graphics/main_window.hpp"



int main(int _argc, char** _argv)
{
    {
        TPP::TPP tpp(_argc, _argv);

        std::thread tpp_thread([&tpp]()
        {
            tpp.Exec();
        });
        tpp_thread.detach();

        TPP::MainWindow mainWindow(tpp);

        mainWindow.Exec();
    }
    return 0;
}
