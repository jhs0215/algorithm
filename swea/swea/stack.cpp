#include <stdint.h>

#define MAX_DATA 100

int ntop = 0;
int stack[MAX_DATA] = {0};

int is_empty()
{
	return ntop == 0;
}

int is_full()
{
	return ntop == MAX_DATA;
}

int push(int v)
{
	if (is_full())
		return 0;

	stack[ntop++] = v;
	return 1;
}

int pop(int* v)
{
	if (is_empty())
		return 0;

	*v = stack[--ntop];
	return 1;
}

int main()
{
	return 0;
}