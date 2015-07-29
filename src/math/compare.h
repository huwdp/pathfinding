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

#pragma once
#include <limits>
#include <math.h>


//http://floating-point-gui.de/errors/comparison/
// Accessed 2015-07-09 YYYY-MM-DD
// This comparison class is not perfect as it does not take into account relative error
// and does not take how large and the error relativity either.

namespace pathfinder
{
class Compare
{
public:
    static bool isAlmostEqual(float, float);
    static bool isOver(float, float);
    static bool isUnder(float, float);
    static bool isAlmostEqual(double, double);
    static bool isOver(double, double);
    static bool isUnder(double, double);
};
}
