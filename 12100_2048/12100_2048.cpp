/*
백준 12100번 2048(easy)

구현을 하는데 있어서는 항상 정확하게 하자.
사소한것 하나 신중하게 고려하자.
전체 범위를 잘 생각하다

기본적으로 DFS를 이용해 중복 순열을 만들어 5회의 움직임을 만들었다.
매 움직임 마다 항상 최대값을 확인하고 비교하도록 한다.

백트래킹을 사용해 현재 최대값이 전체 최대값과 비교에서 남은 횟수 동안 넘을 수 있는지 판단한다.

나머지는 단순 구현이다.

하나씩 건너가면서 움직이도록 구현.

구역이 한개 일때는 움직이지 않으므로 최대값도 0이 되는 현상이 발생 따라서 따로 에러 처리가 필요함.

*/


#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int cnt = 1;
int map[21][21];
int map_n[21][21];
bool check[21][21];
//           위,왼,아래,오
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
int N;
int max_f;
int ans_max;
vector <int> v;

int move(int m) {
	memset(check, false, sizeof(check));
	
	if (m == 2) { // 위쪽 이동
		for (int i = 1; i <= N; i++) {
			int x = i;
			int y = 1;
			int j = 1;
			while(1){
				int nx = x;
				int ny = y + j * dy[m];
				if (ny > N)
					break;
				if (map[y][x] == 0) {
					if (map[ny][nx] == 0) {
						j++;
					}
					else if (map[ny][nx] != 0) {
						map[y][x] = map[ny][nx];
						map[ny][nx] = 0;
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
				}
				else if (map[y][x] != 0) {
					if (map[ny][nx] == 0) {
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
					else if (map[ny][nx] != 0) {
						if (map[y][x] == map[ny][nx] && check[y][x] == false) {
							map[y][x] += map[ny][nx];
							map[ny][nx] = 0;
							check[y][x] = true;
							
						}
						else if (map[y][x] != map[ny][nx]) {
							j = 1;
						}
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						y++;
					}
				}
			}
		}
	}
	else if (m == 0) {
		for (int i = N; i > 0; i--) {
			int x = i;
			int y = N;
			int j = 1;
			while (1) {
				int nx = x ;
				int ny = y + j * dy[m];
				if (ny <= 0)
					break;
				if (map[y][x] == 0) {
					if (map[ny][nx] == 0) {
						j++;
					}
					else if (map[ny][nx] != 0) {
						map[y][x] = map[ny][nx];
						map[ny][nx] = 0;
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
				}
				else if (map[y][x] != 0) {
					if (map[ny][nx] == 0) {
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
					else if (map[ny][nx] != 0) {
						if (map[y][x] == map[ny][nx] && check[y][x] == false) {
							map[y][x] += map[ny][nx];
							map[ny][nx] = 0;
							check[y][x] = true;
							
						}
						else if (map[y][x] != map[ny][nx]) {
							j = 1;
						}
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						y--;
					}
				}
			}
		}
	}
	else if (m == 1) {
		for (int i = N; i > 0; i--) {
			int x = N;
			int y = i;
			int j = 1;
			while (1) {
				int nx = x + j * dx[m];
				int ny = y;
				if (nx <= 0)
					break;
				if (map[y][x] == 0) {
					if (map[ny][nx] == 0) {
						j++;
					}
					else if (map[ny][nx] != 0) {
						map[y][x] = map[ny][nx];
						map[ny][nx] = 0;
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
				}
				else if (map[y][x] != 0) {
					if (map[ny][nx] == 0) {
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
					else if (map[ny][nx] != 0) {
						if (map[y][x] == map[ny][nx] && check[y][x] == false) {
							map[y][x] += map[ny][nx];
							map[ny][nx] = 0;
							check[y][x] = true;
							
						}
						else if (map[y][x] != map[ny][nx]) {
							j = 1;
						}
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						x--;
					}
				}
			}

		}
	}
	else if (m == 3) {
		for (int i = 1; i <= N; i++) {
			int x = 1;
			int y = i;
			int j = 1;
			while (1) {
				int nx = x + j * dx[m];
				int ny = y;
				if (nx > N)
					break;
				if (map[y][x] == 0) {
					if (map[ny][nx] == 0) {
						j++;
					}
					else if (map[ny][nx] != 0) {
						map[y][x] = map[ny][nx];
						map[ny][nx] = 0;
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
				}
				else if (map[y][x] != 0) {
					if (map[ny][nx] == 0) {
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						j++;
					}
					else if (map[ny][nx] != 0) {
						if (map[y][x] == map[ny][nx] && check[y][x] == false) {
							map[y][x] += map[ny][nx];
							map[ny][nx] = 0;
							check[y][x] = true;
							
						}
						else if (map[y][x] != map[ny][nx]) {
							j = 1;
						}
						if (map[y][x] > max_f) {
							max_f = map[y][x];
						}
						x++;
					}
				}
			}
		}
	}
	return 0;
}

int play() {
	max_f = 0;
	memcpy(map, map_n, sizeof(map_n));
	for (int i = 0; i < v.size(); i++) {
		move(v[i]);
		/*cout << "--------------------" << endl;
		cout << v[i] << endl;
		for (int a = 1; a <= N; a++) {
			for (int b = 1; b <= N; b++) {
				printf("%3d",map[a][b]);
			}
			printf("\n");
		}
		printf("\n");*/
		if (max_f != 0) {
			int ch = 4 - i;
			int check_max = ans_max / (2 * max_f);
			if (ch < check_max) {
				break;
			}
		}
	}
	if (max_f >= ans_max) {
		ans_max = max_f;
	}
	return 0;
}

int dfs() {
	
	if (cnt > 5) {
		
		return play();
	}
	
	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		cnt++;
		dfs();
		v.pop_back();
		cnt--;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map_n[i][j];
		}
	}
	dfs();
	if (N == 1) {
		ans_max = map_n[1][1];
	}
	cout << ans_max;

	return 0;
}