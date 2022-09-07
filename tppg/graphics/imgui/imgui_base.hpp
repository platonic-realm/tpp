// Author:        Arash Fatehi
// Date:          2022-08-24
// Description:

#pragma once

// Local Headers
#include "tpp.hpp"

namespace TPP
{

class IMGUIBase
{
public:
    IMGUIBase(TPP& _tpp)
        : tpp(_tpp){};

protected:
    TPP& tpp;

    // clang-format off
    // Monitor Attributes
    int   widthPixel;
    int   widthMM;     // Milimeter
    float widthPPM;    // Pixel per milimeter
    int   heightPixel;
    int   heightMM;    // Milimeter
    float heightPPM;   // Pixel per milimeter
    // clang-format on
};

} // namespace TPP
