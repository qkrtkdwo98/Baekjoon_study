#include <cstdio>
#include <queue>

using namespace std;

int a[100][100];
bool check[100][100];
int dist[100][100];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int bfs(int n, int m) {
	queue<pair<int,int>> q;
	check[0][0] = true;
	dist[0][0] = 1;
	q.push(make_pair(0,0));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (check[nx][ny] == false && a[nx][ny] == 1) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}
	return dist[n-1][m-1];
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	printf("%d", bfs(n, m));
	return 0;
}