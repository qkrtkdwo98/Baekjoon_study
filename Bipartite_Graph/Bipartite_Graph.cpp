#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[20001];
int side[20001];

void dfs(int node, int c) {
	side[node] = c;
	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (side[next] == 0) {
			dfs(next, 3-c);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	queue<bool> q;
	int T,V,E,u,v;
	cin >> T;
	while (T--) {
		cin >> V >> E;
		
		for (int i = 1; i <= V; i++) {
			a[i].clear();
			side[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);

		}
		for (int i = 1; i <= V; i++) {
			if(side[i]==0)
				dfs(i,1);
		}
		bool ok = true;
		for (int i = 1; i <= V; i++) {
			for (int k = 0; k < a[i].size(); k++) {
				int j = a[i][k];
				if (side[i] == side[j])
					ok = false;
			}
		}
		q.push(ok);


	}
	while (!q.empty()) {
		if (q.front() == true) {
			cout << "YES";
			q.pop();
		}
		else {
			cout << "NO";
			q.pop();
		}
		cout << "\n";
	}



	return 0;
}