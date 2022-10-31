#include <iostream>
#include <queue>
#include <cstring>

#define MAX 30
using namespace std;


char map[MAX][MAX][MAX];
bool check[MAX][MAX][MAX];
int inf[MAX][MAX][MAX];

int dx[6] = { -1, 1, 0, 0, 0, 0};
int dy[6] = { 0, 0, -1, 1, 0, 0};
int dz[6] = { 0, 0, 0, 0, -1, 1};

int finish;

typedef struct {
	int x;
	int y;
	int z;
		
} xyz;

xyz config;
xyz escape;
queue <int> result;


int main() {

	while(1) {
		config = { 0,0,0 };
		escape = { 0,0,0 };
		memset(check, false, sizeof(check));
		memset(map, NULL, sizeof(map));
		memset(inf, 0, sizeof(inf));

		queue <xyz> q;
		int L, R, C = 0;
		finish = 0;
		scanf("%d %d %d", &L, &R, &C);

		if (L == 0 && R == 0 && C == 0)
			break;

		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					scanf(" %1c", &map[k][j][i]);
					if (map[k][j][i] == 'S') {
						q.push({ k,j,i });
						check[k][j][i] = true;
					}
					if (map[k][j][i] == 'E')
						escape = { k,j,i };
				}
			}
		}
		int cnt = 0;
		int min = 0;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			int z = q.front().z;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (nx < C && nx >= 0 && ny < R && ny >= 0 && nz < L && nz >= 0
					&& check[nx][ny][nz]==false && (map[nx][ny][nz] == '.' || map[nx][ny][nz] == 'E')) {
					check[nx][ny][nz] = true;
					if (map[nx][ny][nz] != 'E') {
						q.push({ nx,ny,nz });
					}
					inf[nx][ny][nz] = inf[x][y][z]+1;
					if (nx == escape.x && ny == escape.y && nz == escape.z) {
						finish = 1;
					}
				}
			}
		}

		if (finish == 1) {
			min = inf[escape.x][escape.y][escape.z];
			result.push(min);
		}
		else {
			result.push(0);
		}
	}

	while (!result.empty()) {
		if (result.front() != 0) {
			printf("Escaped in %d minute(s).", result.front());
			result.pop();
		}
		else {
			printf("Trapped!");
			result.pop();
		}
		printf("\n");
	}
	return 0;
}