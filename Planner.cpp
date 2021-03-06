#include "stdafx.h"
#include "Planner.h"


Planner::Planner()
{
}

array<Task^>^ Planner::MakeAPlan(array<Task^>^ taskQueue)
{
	int len = taskQueue->Length;
	array<Task^> ^ plannedTasks = gcnew array<Task^>(len);
	int plannedIndex = 0;
	int appearTime = 0;

	while (true)
	{
		bool flag = false;
		int minWorkTask = 0;

		for (int current = 0; current < len; current++)
		{
			if (!taskQueue[minWorkTask])
			{
				minWorkTask++;
				continue;
			}

			flag = true;
			if (taskQueue[current]
				&& taskQueue[current]->AppearTime <= appearTime
				&& taskQueue[current]->WorkTime < taskQueue[minWorkTask]->WorkTime)
			{
				minWorkTask = current;
			}
		}

		if (!flag)
			break;

		if (taskQueue[minWorkTask]->AppearTime > appearTime)
		{
			appearTime++;
			continue;
		}

		plannedTasks[plannedIndex] = taskQueue[minWorkTask];
		plannedTasks[plannedIndex]->WaitTime = appearTime - plannedTasks[plannedIndex]->AppearTime;
		plannedTasks[plannedIndex]->DoneTime = appearTime + plannedTasks[plannedIndex]->WorkTime;
		plannedIndex++;

		appearTime += taskQueue[minWorkTask]->WorkTime;

		taskQueue[minWorkTask] = nullptr;
	}

	return plannedTasks;
}
