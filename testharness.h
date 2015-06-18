#pragma once
#include <vector>
#include "test.h"

using namespace std;

class TestHarness
{
public:
    TestHarness();
    ~TestHarness();
    vector<Test *> tests;
};
