#include <stdio.h>

#define MAX_TO 2
#define MAX_DATA 101

struct tagGraph
{
	int from = 0;
	int to[MAX_TO] = {0};
};

int ntree;
tagGraph graph[MAX_DATA];

void insert(int parent, int child)
{
	graph[child].from = parent;

	int c = 0;
	for (; c < MAX_TO; ++c)
	{
		if (graph[parent].to[c] == 0)
			break;
	}

	graph[parent].to[c] = child;
}

int getRoot()
{
	int parent = 1;
	for (; parent <= ntree; ++parent)
	{
		if (graph[parent].from == 0)
			break;
	}

	return parent;
}

void dfs(int node)
{
	printf("%d ", node);

	for (int i = 0; i < MAX_TO; ++i)
	{
		if(graph[node].to[i])
			dfs(graph[node].to[i]);
	}
}

int main()
{
	return 0;
}