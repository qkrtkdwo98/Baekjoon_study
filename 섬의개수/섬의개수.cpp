#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[51][51];
int num[51][51];
bool check[51][51];

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1 };
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0 };
typedef struct {
	int x;
	int y;
}xy;

queue <xy> q;
queue <int> ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
		int w, h;
		cin >> w >> h;
		memset(map, NULL, sizeof(map));
		memset(check, false, sizeof(check));
		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[j][i];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				//cout << j << " " << i<<endl;
				//cout << "cnt"<<cnt<<endl;
				if (map[j][i] == 1 && check[j][i]==false) {
					q.push({ j,i });
					check[j][i] = true;
					cnt++;
				}
				while (!q.empty()) {
					int x = q.front().x;
					int y = q.front().y;
					q.pop();
					
					for (int k = 0; k < 8; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (map[nx][ny] == 1 && nx < w && nx >= 0 && ny < h && ny >= 0 && check[nx][ny] == false) {
							check[nx][ny] = true;
							q.push({ nx,ny });
						}
					}
				}
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