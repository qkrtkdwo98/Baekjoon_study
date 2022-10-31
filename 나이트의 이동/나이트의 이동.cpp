#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2 };
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int map[301][301];
int num[301][301];
bool check[301][301];
typedef struct {
	int x;
	int y;
}xy;

queue <xy> q;
queue <int> ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	while (n--) {
		memset(check, false, sizeof(check));
		memset(num, NULL, sizeof(num));
		int i = 0;
		cin >> i;
		int a, b, c, d = 0;
		cin >> a >> b >> c >> d;
		q.push({a, b});
		check[a][b] = true;
		int nx, ny = 0;
		int cnt = 0;
		while (!q.empty()) {
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for (int j = 0; j < 8; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (check[nx][ny] == false && nx < i && nx >= 0 && ny < i && ny >= 0) {
					check[nx][ny] = true;
					num[nx][ny] = num[x][y]+1;
					q.push({ nx, ny });
				}
			}
		}
		ans.push(num[c][d]);		
	}
	while (!ans.empty()) {
		cout << ans.front() << endl;
		ans.pop();
	}
	return 0;
}