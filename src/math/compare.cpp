#include "compare.h"

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
    else if (abs(value1-value2) < std::numeric_limits<double>::epsilon())
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
