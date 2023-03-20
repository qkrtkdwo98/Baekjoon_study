/*
����� ���Ƽ� Ǯ������ ���������� Ǯ��
���� ��ư� �Ϸ��ٰ� �̻������� ��Ų��.
��, ����, ����, ���� �� ť�� ���� ��ǥ�� �����Ͽ��� �迭�� vector�� �����Ͽ� �ڿ� ��������� �ְ� �Ͽ���.
vector erase�� �Ҷ��� ���� ������ �����ϰ� �ִ밪�� ���簪�� �ϳ��� ���̴� �������� ū �������� ó���� �����ϴ�.
*/

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
    int x;
    int y;
}xy;
typedef struct {
    int a;
    int b;
    int c;
}abc;
vector<int> map[11][11];
int food[11][11] = {5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5,
                    5,5,5,5,5,5,5,5,5,5,5 };
int a[11][11];
bool check[11][11];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int N, M, K;
queue <xy> sp;
queue <xy> spn;
queue <abc> su;
queue <abc> at;

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        int xf = 0;
        int yf = 0;
        int agef = 0;
        scanf("%d %d %d", &xf, &yf, &agef);
        if (map[xf][yf].size() == 0)
            sp.push({ xf,yf });
        map[xf][yf].push_back(agef);
    }

    while (K--) {
        memset(check, false, sizeof(check));
        while (!sp.empty()) {
            int x = sp.front().x;
            int y = sp.front().y;
            sp.pop();
            sort(map[x][y].begin(),map[x][y].end());
            int cnt = map[x][y].size();
            for (int i = 0; i < cnt; i++) {
                if (food[x][y] >= map[x][y][i]) {
                    food[x][y] -= map[x][y][i];
                    map[x][y][i]++;
                    if (map[x][y][i] % 5 == 0) {
                        at.push({ x,y,map[x][y][i]});
                        if (check[x][y] == false) {
                            check[x][y] = true;
                            spn.push({ x,y });
                        }
                    }
                    else if (check[x][y] == false) {
                        spn.push({ x,y });
                        check[x][y] = true;
                    }
                }
                else {
                    su.push({ x,y,map[x][y][i] });
                    map[x][y].erase(map[x][y].begin() + i);
                    cnt--;
                    i--;
                }
            }
        }

        while (!su.empty()) {
            int x = su.front().a;
            int y = su.front().b;
            int z = su.front().c;
            food[x][y] += z / 2;
            su.pop();
        }

        while (!at.empty()) {
            int x = at.front().a;
            int y = at.front().b;
            int z = at.front().c;
            at.pop();
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > 0 && nx <= N && ny > 0 && ny <= N) {
                    map[nx][ny].push_back(1);
                    if (check[nx][ny] == false) {
                        sp.push({ nx,ny });
                        check[nx][ny] = true;
                    }
                }
            }
        }

        while (!spn.empty()) {
            sp.push({ spn.front().x,spn.front().y });
            spn.pop();
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                food[i][j] += a[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += map[i][j].size();
        }
    }
    printf("%d", ans);
    
    return 0;
}