/*
비활성 바이러스가 활성이 되는 것 유의하기
시간의 최대값 지정에 주의 벽으로 인해 생각보다 긴 시간이 나올 수 있음

조합을 통해 바이러스중 활성화 할 바이러스를 선택
bfs를 통해 탐색을 하면서 시간을 구한다.
바이러스나 벽을 저장할때 시간 증가와 헷갈릴 수 있으므로 주의
기존에 맵을 저장해 두고 카피해서 쓴다.
*/

#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
using namespace std;

typedef struct {
	int x;
	int y;
}xy;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int N;
int M;
int map[51][51];      // 기본 저장할 맵 파일
int map_f[51][51];    // 카피해서 bfs를 돌릴 맵
bool check[51][51];
int ans;
int max_time = 3000;  //최대값 주의
vector<xy> v;         // 바이러스 저장


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int temp = 0;
			cin >> temp;
			if (temp == 2) {
				v.push_back({i,j});
				map[j][i] = 222;
			}
			else if (temp == 0) {
				map[j][i] = 0;
				ans++;
			}
			else if (temp == 1) {
				map[j][i] = 111;
			}
		}
	}

	vector<bool> temp(v.size(),false);
	for (int i = 0; i < M; i++) {
		temp[i] = true;
	}
	do {
		memset(check, false, sizeof(check));
		memcpy(map_f, map, sizeof(map));
		queue<xy> q;
		for (int l = 0; l < temp.size(); l++) {
			if (temp[l]) {
				map_f[v[l].y][v[l].x] = 0;
				q.push({ v[l].x, v[l].y });
				check[v[l].y][v[l].x] = true;

			}
		}
		
		int time = 0;
		int cnt = ans;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx > 0 && nx <= N && ny > 0 && ny <= N 
					&& (map_f[ny][nx] == 0 || map_f[ny][nx] == 222) && check[ny][nx] == false) {
					if (map_f[ny][nx] == 0) {
						cnt--;
						map_f[ny][nx] = map_f[y][x] + 1;
						if (time < map_f[ny][nx]) {
							time = map_f[ny][nx];
						}
						q.push({nx,ny});
						check[ny][nx] = true;
					}
					else if (map_f[ny][nx] == 222) {
						map_f[ny][nx] = map_f[y][x] + 1;
						q.push({ nx,ny });
						check[ny][nx] = true;
					}
				}
				if (cnt == 0) {
					if (max_time > time) {
						max_time = time;
					}
					else if (max_time == -1) {
						max_time = time;
					}
					break;
				}
			}
			if (cnt == 0) {
				break;
			}
		}
		if (cnt != 0 && (max_time == 3000 || max_time == -1)) {
			max_time = -1;
		}
	} while (prev_permutation(temp.begin(), temp.end()));

	cout << max_time;

	return 0;
}