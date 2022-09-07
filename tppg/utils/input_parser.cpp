// Author:        Arash Fatehi
// Date:          2022-08-18
// Description:

// Local Headers
#include "input_parser.hpp"

namespace TPP
{
    InputParser::InputParser(int _argc, char **_argv)
    {
        for (int i = 0; i < _argc; i++)
            tokens.push_back(std::string(_argv[i]));
    }

    std::string InputParser::Parse(std::shared_ptr<TPP::Configs> _configs)
    {
        return "a";
    }
} // namespace TPP
