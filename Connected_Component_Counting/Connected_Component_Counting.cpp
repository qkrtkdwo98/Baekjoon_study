#include <iostream>
#include <vector>


using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M,u,v;

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int components = 0;
	for (int i = 1; i <= N; i++) {
		if (check[i] == false) {
			dfs(i);
			components += 1;
		}
	}
	cout << components;
	return 0;
}