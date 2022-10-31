#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[50][50];
int check[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

typedef struct {
	int x;
	int y;
} xy;

queue <xy> q;
queue <xy> st;
queue <int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 0;
	
	cin >> T;

	while (T--) {
		int M, N, K = 0;
		int m, n, cnt = 0;
		memset(check, false, sizeof(check));
		memset(map, NULL, sizeof(map));
		cin >> M >> N >> K;
		for (int i = 0; i < K; i++) {
			cin >> m >> n;
			map[m][n] = 1;
			st.push({ m,n });
		}

		while (!st.empty()) {
			int ch_x = st.front().x;
			int ch_y = st.front().y;
			st.pop();
			if (check[ch_x][ch_y] == false) {
				q.push({ ch_x,ch_y });
				while (!q.empty()) {
					int x = q.front().x;
					int y = q.front().y;
					q.pop();
					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];
						if (check[nx][ny] == false && nx < M && nx >= 0 && ny < N && ny >= 0 && map[nx][ny] == 1) {
							check[nx][ny] = true;
							q.push({ nx,ny });

						}
					}
				}
				cnt++;
			}

		}
		ans.push(cnt);
	}
	while (!ans.empty()) {
		cout << ans.front()<<endl;
		ans.pop();
	}

	return 0;
}