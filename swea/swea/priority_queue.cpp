#include <iostream>

#define MAX_DATA 100

int nqueue = 0;
int queue[MAX_DATA] = {0};

int is_empty()
{
	return nqueue == 0;
}

int is_full()
{
	return nqueue == MAX_DATA;
}

void swap(int* i, int* j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

int insert(int v)
{
	if (is_full())
		return 0;

	queue[nqueue] = v;

	int current = nqueue;
	while (current > 0 && queue[current] < queue[(current - 1) / 2])
	{
		int parent = (current - 1) / 2;
		swap(&queue[current], &queue[parent]);
		current = parent;
	}

	nqueue++;

	return 1;
}

int pop(int* v)
{
	if (is_empty())
		return 0;

	*v = queue[0];

	queue[0] = queue[--nqueue];
	int current = 0;

	while (current < (current * 2 + 1))
	{
		int child = 0;
		if (current * 2 + 2 == nqueue)
		{
			child = current * 2 + 1;
		}
		else
		{
			if (queue[current * 2 + 1] < queue[current * 2 + 2])
				child = current * 2 + 1;
			else
				child = current * 2 + 2;
		}

		if (queue[current] < queue[child])
			break;

		swap(&queue[current], &queue[child]);
		current = child;
	}
	
	return 1;
}

int main()
{
	return 0;
}