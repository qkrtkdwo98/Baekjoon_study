#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[51][51];
int num[51][51];
int fnum[51][51];
bool check[51][51];
int sum;
int ans;

typedef struct {
    int x;
    int y;
} xy;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue <xy> q;
queue <xy> pre;
vector <xy> ch;
vector <int> ord;
vector <xy> h;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                ch.push_back({ i,j });
                ord.push_back(cnt);
                cnt++;
            }
            else if (map[i][j] == 1)
                h.push_back({ i,j });
        }
    }
    vector<bool> temp(ord.size(), false);
    for (int i = 0; i < M; i++) // 앞부터 r개의 true가 채워진다. 나머지 뒤는 false.
        temp[i] = true;

    do {
        for (int k = 0; k < ord.size(); k++) {
            if (temp[k]) {
                pre.push({ ch[ord[k]].x,ch[ord[k]].y });
            }
        }
        memset(num, 0, sizeof(num));
        while (!pre.empty()) {
            memset(check, false, sizeof(check));
            memset(fnum, 0, sizeof(fnum));
            
            q.push({ pre.front().x,pre.front().y });
            check[pre.front().x][pre.front().y] = true;
            fnum[pre.front().x][pre.front().y] = 0;
            pre.pop();
            while (!q.empty()) {
                int x = q.front().x;
                int y = q.front().y;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx<=N && nx>0 && ny <= N && ny > 0 && check[nx][ny] == false) {
                        fnum[nx][ny] = fnum[x][y] + 1;
                        if (map[nx][ny] == 1 && (num[nx][ny] > fnum[nx][ny] || num[nx][ny] == 0))
                            num[nx][ny] = fnum[nx][ny];
                        q.push({ nx,ny });
                        check[nx][ny] = true;
                    }
                }
            }            
        }
        sum = 0;
        for (int a = 0; a < h.size(); a++) {
            sum += num[h[a].x][h[a].y];
        }
        if (ans > sum || ans == 0)
            ans = sum;
    } while (prev_permutation(temp.begin(), temp.end()));

    cout << ans;    

    return 0;
}