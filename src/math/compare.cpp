/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Huw David Pritchard
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "compare.h"
#include <cmath>

namespace pathfinder
{
    bool Compare::isAlmostEqual(float value1, float value2)
    {
        if (value1 == value2)
            return true;
        else if (fabs(value1-value2) < std::numeric_limits<float>::epsilon())
            return true;
        return false;
    }

    bool Compare::isOver(float value1, float value2)
    {
        if (isAlmostEqual(value1, value2))
            return false;
        else if (value1 > value2)
            return true;
        return false;
    }

    bool Compare::isUnder(float value1, float value2)
    {
        if (isAlmostEqual(value1, value2))
            return false;
        else if (value1 < value2)
            return true;
        return false;
    }

    bool Compare::isAlmostEqual(double value1, double value2)
    {
        if (value1 == value2)
            return true;
        else if (std::abs(value1-value2) < std::numeric_limits<double>::epsilon())
            return true;
        return false;
    }

    bool Compare::isOver(double value1, double value2)
    {
        if (isAlmostEqual(value1, value2))
            return false;
        else if (value1 > value2)
            return true;
        return false;
    }

    bool Compare::isUnder(double value1, double value2)
    {
        if (isAlmostEqual(value1, value2))
            return false;
        else if (value1 < value2)
            return true;
        return false;
    }
}
