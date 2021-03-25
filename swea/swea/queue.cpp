#include <stdio.h>

#define MAX_DATA 100

int nfront = 0;
int nrear = 0;
int queue[MAX_DATA] = {0};

int is_empty()
{
	return nfront == nrear;
}

int is_full()
{
	return nfront = ((nrear + 1) % MAX_DATA);
}

int enqueue(int v)
{
	if (is_full())
		return 0;

	queue[nrear++] = v;
	nrear = nrear % MAX_DATA;

	return 1;
}

int dequeue(int* v)
{
	if (is_empty())
		return 0;

	*v = queue[nfront--];
	nfront = nfront % MAX_DATA;
	
	return 1;
}

int main()
{
	return 0;
}