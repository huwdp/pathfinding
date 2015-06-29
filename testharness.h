#pragma once
#include <vector>
#include "test.h"

using namespace std;

class TestHarness
{
private:
    vector<Test *> tests;
public:
    TestHarness();
    ~TestHarness();
    void checkTests();
};
