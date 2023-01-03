#include <iostream>
#include <cstring>

using namespace std;
/*
시간초과에 유의
DFS, 종북유의
백트래킹 사용해야함.


*/
int N, M, H;
int Np, Hp;
int point[31][10];
int ans = 4;
int order = 0;

int check_ans() {
    int h = 1;
    int cnt = 0;
    int flag = 0;
    for (int i = 1; i <= N; i++) {
        int n = i;
        for (int j = 1; j <= Hp; j++) {
            if (n <= Np) {
                
                if (point[j][n] == 1) {
                    n++;
                }
                else if (n - 1 > 0) {
                    if (point[j][n - 1] == 1) {
                        n--;
                    }
                }
            }
            else if (n == N) {
                if (n - 1 > 0) {
                    if (point[j][n - 1] == 1) {
                        n--;
                    }
                }
            }
        }
        if (n == i) {
            cnt++;
        }
        else {
            break;
            flag = 1;
        }
    }
    
    if (cnt == N) {
        return 1;
    }
    else
        return 0;
}

int find_line(int a, int b) {
    
    if (order == 4) {
        return 0;
    }
    if (order >= ans) {
        return 0;
    }
    int point_ch[31][10];
    memcpy(point_ch,point,sizeof(point));
    int j = b;
    for (int i = a; i <= Np; i++) {
        for (; j <= Hp; j++) {
            int flag = 0;
            if (i - 1 > 0 && i + 1 <= Np) {
                if (point[j][i - 1] == 0 && point[j][i + 1] == 0 && point[j][i] == 0) {
                    point[j][i] = 1;
                    flag = 1;
                }
            }
            else if (i - 1 == 0) {
                if (point[j][i + 1] == 0 && point[j][i] == 0) {
                    point[j][i] = 1;
                    flag = 1;
                }
            }
            else if (i + 1 > Np) {
                if (point[j][i - 1] == 0 && point[j][i] == 0) {
                    point[j][i] = 1;
                    flag = 1;
                }
            }   
            if (flag == 1) {
                if (check_ans() == 1) {
                    if (ans > order) {
                        ans = order;
                        /*for (int k = 1; k <= Hp; k++) {
                            for (int l = 1; l <= Np; l++) {
                                printf("%2d ", point[k][l]);
                            }
                            printf("\n");
                        }*/
                    }
                    return 0;
                }
                else {
                    order++;
                    find_line(i,j);
                    order--;
                    memcpy(point, point_ch, sizeof(point_ch));
                }
                flag = 0;
            }
        }
        j = 1;
    }
    return 0;
}

int main() {
    scanf("%d %d %d", &N, &M, &H);
    Np = N - 1;
    Hp = H;
    int a = 0, b = 0;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        point[a][b] = 1;
    }
    if (check_ans() == 1) {
        ans = 0;
    }
    else {
        order++;
        find_line(1,1);
    }
    if (ans == 4) {
        printf("%d", -1);
    }
    else
        printf("%d", ans);

    return 0;
}