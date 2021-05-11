#include <iostream>

#define MAX_DATA 100

int list[MAX_DATA] = {0};

void binarySearch(int* list, int low, int high, int target)
{
	if (low > high)
	{
		printf("-1\n");
		return;
	}

	int mid = (low + high) / 2;

	if (list[mid] < target)
	{
		binarySearch(list, mid + 1, high, target);
	}
	else if (list[mid] > target)
	{
		binarySearch(list, low, mid - 1, target);
	}
	else
	{
		printf("%d\n", mid);
	}
}

int main()
{
	int T;    // # of test case
	int M;    // # of element in array
	int N;    // # of numbers to search

	int targetValue;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		printf("#%d ", test_case);
		scanf("%d %d", &M, &N);

		for (int i = 0; i < M; i++)
		{
			scanf("%d", &list[i]);
		}

		for (int i = 0; i < N; i++)
		{
			scanf("%d", &targetValue);
			binarySearch(list, 0, M - 1, targetValue);
		}
		printf("\n");
	}
	return 0;
}