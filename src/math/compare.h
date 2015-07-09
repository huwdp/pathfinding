#include <limits>
#include <math.h>


//http://floating-point-gui.de/errors/comparison/
// Accessed 2015-07-09 YYYY-MM-DD
// This comparison class is not perfect as it does not take into account relative error
// and does not take how large and the error relativity either.

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
