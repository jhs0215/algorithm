#include <stdio.h>

#define MAX_TO 10
#define MAX_DATA 100001
#define MAX_LEVEL 20

struct tagGraph
{
	int from = 0;
	int to[MAX_TO] = {0};
};
	
int nedge = 0;
int nquery = 0;

tagGraph graph[MAX_DATA];
int depth[MAX_DATA] = {-1};
int ac[MAX_DATA][MAX_LEVEL] = {0}; // depth 에 따른 조상

void insert(int from, int to)
{
	int t = 0;

	for (; t < MAX_TO; ++t)
	{
		if (graph[from].to[t] == 0)
			break;
	}

	graph[from].to[t] = to;
	graph[to].from = from;
}

void set_nca(int from, int parent)
{
	depth[from] = depth[parent] + 1;

	ac[from][0] = parent;
	for (int i = 1; i < MAX_LEVEL; ++i)
	{
		int tmp = ac[from][i - 1]; 
		ac[from][i] = ac[tmp][i - 1];

		if (ac[from][i] == 0)
			break;
	}

	for (int i = 0; i < MAX_TO; ++i)
	{
		if (graph[from].to[i] == 0)
			break;

		if (graph[from].to[i] != parent)
			set_nca(graph[from].to[i], from);
	}
}

int solution(int n1, int n2)
{
	if (depth[n1] != depth[n2])
	{
		if (depth[n1] > depth[n2])
		{
			int tmp = n1;
			n1 = n2;
			n2 = tmp;
		}

		for (int i = MAX_LEVEL - 1; i >= 0; --i)
		{
			if (ac[n2][i] == 0)
				continue;

			if (depth[n1] <= depth[ac[n2][i]])
				n2 = ac[n2][i];
		}
	}
	
	int lca = n1;
	
	if (n1 != n2)
	{
		for (int i = MAX_LEVEL - 1; i >= 0; --i)
		{
			if (ac[n1][i] == 0)
				continue;

			if (ac[n1][i] != ac[n2][i])
			{
				n1 = ac[n1][i];
				n2 = ac[n2][i];
			}

			lca = ac[n1][i];
		}
	}
	   
	return lca;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T = 0;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &nedge, &nquery);

		for (int i = 0; i < nedge; ++i)
		{
			int parent, child;
			scanf("%d %d", &parent, &child);

			insert(parent, child);
		}

		set_nca(1, 0);
		
		printf("#%d", test_case);

		for (int i = 0; i < nquery; ++i)
		{
			int n1, n2;
			scanf("%d %d", &n1, &n2);

			int res = solution(n1, n2);
			printf(" %d", res);
		}

		printf("\n");
	}

	return 0;
}
/*
// input
1
14 3
1 3
1 5
3 12
12 2
12 14
2 9
2 11
2 13
13 6
5 8
8 4
8 15
15 7
15 10
13 6
9 13
14 7
// output
#1 13 2 1
*/