#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
long long int ret;
int visited[100001];
int parent[100001][20];
int depth[100001];
vector<int> tree[100001];
int MAXDEPTH = 0;

int lca(int u, int v)
{
	if (depth[u] > depth[v]) swap(u, v);
	for (int i = MAXDEPTH; i >= 0; i--)
		if (depth[v] - depth[u] >= (1 << i)) v = parent[v][i];
	if (u == v) return u;
	for (int i = MAXDEPTH; i >= 0; i--)
	{
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}
	}
	return parent[u][0];
}

void bfs(int s)
{
	deque<int> Q;
	Q.push_back(s);
	visited[s] = 1;
	int b = 1;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop_front();
		for (int i = 0; i < tree[u].size(); i++)
		{
			int v = tree[u][i];
			if (!visited[v])
			{
				ret += depth[b] + depth[v] - 2 * depth[lca(b, v)];
				visited[v] = 1;
				Q.push_back(v);
				b = v;
			}
		}
	}
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	int p;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		
		for (int i = 1; i <= N; i++) {
			tree[i].clear();
			depth[i] = -1; visited[i] = 0;
			
			for (int j = 0; j < 20; j++) 
				parent[i][j] = 0;
		}

		int d;
		for (int i = 2; i <= N; i++) {
			cin >> p;
			tree[p].push_back(i);
			tree[i].push_back(p);
			d = depth[p] + 1;
			MAXDEPTH = max(MAXDEPTH, d);
			depth[i] = d;
			parent[i][0] = p;
		}

		MAXDEPTH = log2(MAXDEPTH);
		for (int j = 1; j <= MAXDEPTH; j++)
		{
			for (int i = 1; i <= N; i++)
			{
				parent[i][j] = parent[parent[i][j - 1]][j - 1];
			}
		}

		ret = 0;
		bfs(1);
		cout << "#" << test_case << " " << ret << endl;
	}
	return 0;
}