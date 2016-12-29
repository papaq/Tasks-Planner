#pragma once
#include <iostream>
#include <ctime>

using namespace System;

value class Task
{
public:
	int AppearTime;
	int WorkTime;
	virtual String^ ToString() new
	{
		return String::Format("{0,5}{1,5}", AppearTime, WorkTime);
	}
};

ref class QueueGenerator
{
	int const DIFF_RANGE = 10;
	int const APPEAR_TIME = 10;
	double const APPEAR_POSSIBILITY = 0.5;
public:
	QueueGenerator();
	array<Task^> ^ MakeQueue();
	void PrintArray(array<Task^> ^ tasks);
};

