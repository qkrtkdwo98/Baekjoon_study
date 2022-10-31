#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num[101];
bool check[101];
int cnt;
int a, b;
int point = -1;

void dfs(int node) {
	check[node] = true;
	if (node == b) {
		cout << cnt;
		point = 1;
	}
	cnt++;
	for (int i = 0; i < num[node].size(); i++) {
		int next = num[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
	cnt--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	cin >> a >> b;
	int m = 0;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		num[u].push_back(v);
		num[v].push_back(u);
	}
	for (int i = 1; i <= m; i++) 
		sort(num[i].begin(), num[i].end());
	dfs(a);
	if (point == -1)
		cout << point;
	return 0;
}