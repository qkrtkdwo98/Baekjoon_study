#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[101][101];
int num[101][101] = {1,};
bool check[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1, 1, 0, 0 };

typedef struct {
	int x;
	int y;
}xy;

queue <xy> q;
vector <int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N, K;
	cin >> M >> N >> K;
	
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a+1; j <= c; j++) {
			for (int k = b+1; k <= d; k++) {
				map[j][k] = 1;
				check[j][k] = true;
			}
		}

	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[j][i] == false) {
				q.push({ j,i });
				check[j][i] = true;
			}
			int cnt = 0;
			int point = 0;
			while (!q.empty()) {
				int x = q.front().x;
				int y = q.front().y;
				point = 1;
				q.pop();
				cnt++;
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx <= N && nx > 0 && ny <= M && ny > 0 && check[nx][ny] == false) {
						check[nx][ny] = true;
						q.push({ nx, ny });
						num[nx][ny] = num[x][y] + 1;
					}
				}
			}
			if (point == 1)
				ans.push_back(cnt);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size();i++){
		cout << ans[i];
		cout << ' ';
	}
	return 0;
}