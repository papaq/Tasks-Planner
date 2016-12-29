#pragma once
#include "QueueGenerator.h"

using namespace System;

ref class Planner
{

public:
	Planner();
	array<Task^> ^ MakeAPlan(array<Task^> ^ taskQueue);
};

