#include <stdio.h>
#include <stdlib.h>
#include "testharness.h"

using namespace std;

int main()
{
    TestHarness *testHarness = new TestHarness();
    testHarness->checkTests();
    return 1;
}
