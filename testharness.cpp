#include "testharness.h"

TestHarness::TestHarness()
{
    // Test 1

    // Test 2

    // Test 3

    // Etc

    // Check tests in tests list
}

TestHarness::~TestHarness()
{
    for (vector<Test*>::iterator it = tests.begin() ; it != tests.end(); ++it)
    {
        delete (*it);
    }
}
