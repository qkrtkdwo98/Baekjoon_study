#include <iostream>
#include <queue>
using namespace std;

int m, n, h;
int box[100][100][100];
int dx[] = { 1, -1, 0, 0, 0 ,0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	queue <pair <int, pair<int, int>>> q;
	int cnt1 = 0;
	int cnt2 = 0;
	int day = 0;
	int tomato = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					q.push(make_pair(i, make_pair(j, k)));
					cnt1++;
				}
				if (box[i][j][k] == 0) {
					tomato++;
				}
			}
		}
	}
	
	while (!q.empty()) {
		int cnt = q.size();

		for (int j = 0; j < cnt; j++) {
			int z = q.front().first;
			int y = q.front().second.first;
			int x = q.front().second.second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nz = z + dz[i];
				if (nx >= 0 && nx < m && ny >= 0 && ny < n && nz >= 0 && nz < h && box[nz][ny][nx] == 0) {
					box[nz][ny][nx] = 1;
					tomato--;
					q.push(make_pair(nz, make_pair(ny, nx)));
				}
			}
			
		}
		day++;
	}

	if (tomato >= 1)
		cout << "-1";
	else 
		cout << day-1;

	return 0;
}