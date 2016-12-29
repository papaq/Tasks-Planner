#pragma once
#include <iostream>
#include <ctime>

using namespace System;

value class Task
{
public:
	int Index;
	int AppearTime;
	int WorkTime;
	int WaitTime = -1;
	int DoneTime = -1;
	virtual String^ ToString() new
	{
		return String::Format("{0,5}{1,5}{2,5}{3,5}", AppearTime, WorkTime, WaitTime, DoneTime);
	}
};

ref class QueueGenerator
{
	int const DIFF_RANGE = 10;
	int const APPEAR_TIME = 20;
	double const APPEAR_POSSIBILITY = 0.5;
public:
	QueueGenerator();
	array<Task^> ^ MakeQueue();
	void PrintArray(array<Task^> ^ tasks);
};

