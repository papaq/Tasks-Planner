// PlannerSJF.cpp : main project file.

#include "stdafx.h"
#include "QueueGenerator.h"
#include "Planner.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	QueueGenerator ^queueGen = gcnew QueueGenerator();
	Planner ^plannerInst = gcnew Planner();

	array<Task^> ^ tasksToSolve = queueGen->MakeQueue();
	queueGen->PrintArray(tasksToSolve);
	array<Task^> ^ tasksPlanned = plannerInst->MakeAPlan(tasksToSolve);
	queueGen->PrintArray(tasksPlanned);

	System::Console::ReadKey();
    return 0;
}
