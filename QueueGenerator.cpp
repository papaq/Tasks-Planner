#include "stdafx.h"
#include "QueueGenerator.h"


QueueGenerator::QueueGenerator()
{

}

array<Task^ > ^ QueueGenerator::MakeQueue()
{
	srand((unsigned)time(NULL));
	array<Task^ > ^queue = gcnew array<Task^>(APPEAR_TIME);

	int nextTaskTime = 0, i = 0;
	while (nextTaskTime < APPEAR_TIME)
	{
		if (rand() % 100 > APPEAR_POSSIBILITY * 100)
		{
			nextTaskTime++;
			continue;
		}

		queue[i] = gcnew Task;
		queue[i]->AppearTime = nextTaskTime;
		queue[i]->WorkTime = (rand() % DIFF_RANGE) + 1;
		nextTaskTime++;
		i++;
	}

	return queue;
}

void QueueGenerator::PrintArray(array<Task^> ^ tasks)
{
	System::Console::WriteLine("{0,7}:{1,7}{2,5}", "Index", "Appear", "Hard");

	for (int i = 0; i < tasks->Length; i++)
	{
		if (tasks[i] == nullptr)
		{
			return;
		}
		System::Console::WriteLine("{0,7}:{1,12}",i,tasks[i]->ToString());
	}
}
