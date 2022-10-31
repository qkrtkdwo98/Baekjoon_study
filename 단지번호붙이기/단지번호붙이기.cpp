#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int num[26][26];
int data[26][26];
int count[646];
int cnt;
bool check[26][26];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int N, x, y;

void bfs() {
	queue <pair<int,int>> q;
	vector <int> v;
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (check[a][b] == false && num[a][b] == 1) {
				q.push(make_pair(a, b));
				check[a][b] = true;
				cnt++;
				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (check[nx][ny] == false && num[nx][ny] == 1 && nx >=0 && ny>= 0 && nx<N && ny < N ) {
							check[nx][ny] = true;
							cnt++;
							q.push(make_pair(nx, ny));
						}
					}
					
				}
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	printf("%ld\n", v.size());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%ld\n", v[i]);
	}
}

int main() {
	scanf("%d",&N);
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d",&num[i][j]);
		}
	}
	bfs();
	return 0;
}