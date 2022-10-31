#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int map[8][8];
bool check[8][8];
int N, M;
int minnum = 64;

typedef struct {
    int x;
    int y;
}xy;

vector <xy> cctv;

int check_area(int dir, int x, int y) {
    while (1) {
        if (dir % 4 == 0) {
            y++;
        }
        else if (dir % 4 == 1) {
            x++;
        }
        else if (dir % 4== 2) {
            y--;
        }
        else{
            x--;
        }
        if (x < N && y < M && x >= 0 && y >= 0) {
            if (map[x][y] == 0)
                map[x][y] = 7;
            else if (map[x][y] == 6)
                break;
        }
        else if (x >= N || y >= M || x < 0 || y < 0) {
            break;
        }
    }
    return 0;
}

int dfs(int cnt) {
    int map_c[8][8];
    if (cnt == cctv.size()) {
        int noarea = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 0)
                    noarea++;
            }
        }
        if (minnum > noarea)
            minnum = noarea;
        return 0;
    }
    
    if (map[cctv[cnt].x][cctv[cnt].y] == 1) {
        for (int i = 0; i < 4; i++) {
            memcpy(map_c, map, sizeof(map));
            check_area(i, cctv[cnt].x, cctv[cnt].y);
            dfs(cnt + 1);
            memcpy(map, map_c, sizeof(map_c));
        }
    }
    else if (map[cctv[cnt].x][cctv[cnt].y] == 2) {
        for (int i = 0; i < 2; i++) {
            memcpy(map_c, map, sizeof(map));
            check_area(i, cctv[cnt].x, cctv[cnt].y);
            check_area(i + 2, cctv[cnt].x, cctv[cnt].y);
            dfs(cnt + 1);
            memcpy(map, map_c, sizeof(map_c));
            
        }

    }
    else if (map[cctv[cnt].x][cctv[cnt].y] == 3) {
        for (int i = 0; i < 4; i++) {
            memcpy(map_c, map, sizeof(map));
            check_area(i, cctv[cnt].x, cctv[cnt].y);
            check_area(i + 1, cctv[cnt].x, cctv[cnt].y);
            dfs(cnt + 1);
            memcpy(map, map_c, sizeof(map_c));
        }
    }
    else if (map[cctv[cnt].x][cctv[cnt].y] == 4) {
        for (int i = 0; i < 4; i++) {
            memcpy(map_c, map, sizeof(map));
            check_area(i, cctv[cnt].x, cctv[cnt].y);
            check_area(i + 1, cctv[cnt].x, cctv[cnt].y);
            check_area(i + 2, cctv[cnt].x, cctv[cnt].y);
            dfs(cnt + 1);
            memcpy(map, map_c, sizeof(map_c));
        }
    }
    else {
        for (int i = 0; i < 2; i++) {
            memcpy(map_c, map, sizeof(map));
            check_area(0, cctv[cnt].x, cctv[cnt].y);
            check_area(1, cctv[cnt].x, cctv[cnt].y);
            check_area(2, cctv[cnt].x, cctv[cnt].y);
            check_area(3, cctv[cnt].x, cctv[cnt].y);
            dfs(cnt + 1);
            memcpy(map, map_c, sizeof(map_c));
        }
    }

    return 0;
}


int main() {

    scanf("%d %d",&N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d",&map[i][j]);
            if (map[i][j] > 0 && map[i][j] < 6)
                cctv.push_back({ i,j });
        }
    }
    
    dfs(0);
    printf("%d",minnum);
    return 0;
}