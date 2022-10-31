#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

#define MAX 8

int a[MAX][MAX];
int b[MAX][MAX];
bool check[MAX][MAX];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int m, n;

typedef struct {
	int x;
	int y;
} xy;

queue <xy> q;
vector <xy> vi;
vector <xy> wall;

bool cmp(int a, int b) {
	return a > b;
}

int bfs() {
	for (int j = 0; j < vi.size(); j++) {
		q.push({ vi[j].x, vi[j].y });
		check[vi[j].x][vi[j].y] = true;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < m && ny < n && ny >= 0 && nx >= 0 && check[nx][ny] == false && b[nx][ny] == 0 ) {
					check[nx][ny] = true;
					b[nx][ny] = 2;
					q.push({ nx,ny });
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (b[j][i] == 0)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[j][i];
			if (a[j][i] == 2)
				vi.push_back({ j,i });
			else if (a[j][i] == 0)
				wall.push_back({ j,i });
		}
	}

	vector<int> safe;
	for (int i = 0; i < wall.size(); i++) {
		for (int j = i+1; j < wall.size(); j++) {
			for (int k = j+1; k < wall.size(); k++) {
				copy(&a[0][0], &a[0][0] + MAX*MAX, &b[0][0]);
				b[wall[i].x][wall[i].y] = 1;
				b[wall[j].x][wall[j].y] = 1;
				b[wall[k].x][wall[k].y] = 1;

				safe.push_back(bfs());
				memset(b, 0, sizeof(b));
				memset(check, NULL, sizeof(check));
			}
		}
	}

	
	sort(safe.begin(), safe.end(),cmp);

	cout << safe[0];

	return 0;
}