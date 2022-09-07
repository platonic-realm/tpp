// Author:        Arash Fatehi
// Date:          2022-08-18
// Description:

#ifndef INPUT_PARSER_HPP
#define INPUT_PARSER_HPP

// Standard Headers
#include <string>
#include <vector>
#include <memory>

// Local Headers
#include "configs.hpp"

namespace TPP
{
    class InputParser
    {
    public:
        InputParser(int _argc, char** _argv);
        std::string Parse(std::shared_ptr<TPP::Configs> _configs);

    private:
        std::vector<std::string> tokens;
    };

} // namespace TPP

#endif // INPUT_PARSER_HPP