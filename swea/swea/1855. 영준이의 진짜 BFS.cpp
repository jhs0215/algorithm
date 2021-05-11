#include <stdio.h>
#include <vector>
#include <deque>
#include <algorithm>

#define MAX_DATA 100001
#define MAX_DEPTH 20

int ndata = 0;
int parent[MAX_DATA] = {0};

std::vector<int> graph[MAX_DATA];

int anc[MAX_DATA][MAX_DEPTH] = {0};
int depth[MAX_DATA] = {0};
int maxDepth = 0;
int ret = 0;

void init()
{
	ret = 0;
	maxDepth = 0;

	for (int i = 0; i < MAX_DATA; ++i)
	{
		graph[i].clear();
		depth[i] = 0;

		for (int j = 0; j < MAX_DEPTH; ++j)
		{
			anc[i][j] = 0;
		}
	}
}

void set_lca()
{
	depth[1] = 1;

	for (int i = 2; i <= ndata; ++i)
	{
		graph[parent[i]].push_back(i);
		graph[i].push_back(parent[i]);

		anc[i][0] = parent[i];
		depth[i] = depth[parent[i]] + 1;
		maxDepth = std::max(maxDepth, depth[i]);
	}

	int lv = int(log2(maxDepth));
	for (int j = 1; j <= lv; ++j)
	{
		for (int i = 1; i <= ndata; ++i)
		{
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
		}
	}
}

void swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

int lca(int n1, int n2)
{
	if (depth[n1] > depth[n2])
		swap(&n1, &n2);

	for (int i = maxDepth; i >= 0; --i)
	{
		if (depth[n2] - depth[n1] >= 1 << i)
			n2 = anc[n2][i];
	}

	if (n1 == n2)
		return n1;

	for (int i = maxDepth; i >= 0; --i)
	{
		if (anc[n1][i] != anc[n2][i])
		{
			n1 = anc[n1][i];
			n2 = anc[n2][i];
		}
	}

	return anc[n1][0];
}

void bfs(int node)
{
	int visited[MAX_DATA] = {0};

	std::deque<int> q;
	q.push_back(node);

	int prev = node;
	int curr = node;

	while (!q.empty())
	{
		int n = q.front();
		q.pop_front();

		visited[n] = 1;

		for (int i = 0; i < graph[n].size(); ++i)
		{
			if (visited[graph[n][i]])
				continue;
			
			curr = graph[n][i];

			ret += depth[prev] + depth[curr] - depth[lca(prev, curr)];

			prev = curr;
			q.push_back(curr);
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; 
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; ++test_case)
	{
		init();

		scanf("%d", &ndata);

		for (int i = 2; i <= ndata; ++i)
		{
			int p = 0;
			scanf("%d", &parent[i]);
		}

		set_lca();

		bfs(1);

		printf("#%d %d\n", test_case, ret);
	}

	return 0;
}