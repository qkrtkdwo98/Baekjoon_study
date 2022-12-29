#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int map[101][101];
bool check[101][101];
bool ans = false;
int count_road = 0;

int main() {
    int N = 0, L = 0;
    scanf("%d %d", &N, &L);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        ans = false;
        for (int j = 1; j <= N-1; j++) {
            if (map[i][j] == map[i][j + 1]) {
                ans = true;
            }
            else if (map[i][j] != map[i][j + 1]) {
                if (map[i][j] - map[i][j + 1] == -1) {
                    int cnt = 0;
                    for (int a = 0; a < L; a++) {
                        if (j - a > 0 && check[i][j-a] == false) {
                            if (map[i][j] == map[i][j - a]) {
                                cnt++;
                                check[i][j - a] = true;
                            }
                        }
                        else
                            break;
                    }
                    if (cnt == L) {
                        ans = true;
                    }
                    else
                        ans = false;
                }
                else if (map[i][j] - map[i][j + 1] == 1) {
                    int cnt = 0;
                    for (int a = 1; a <= L; a++) {
                        if (j + a <= N && check[i][j + a] == false) {
                            if (map[i][j] - map[i][j + a] == 1) {
                                cnt++;
                                check[i][j + a] = true;
                            }
                        }
                        else
                            break;
                    }
                    if (cnt == L) {
                        ans = true;
                    }
                    else
                        ans = false;
                }
                else {
                    ans = false;
                }
            }
            if (ans == true) {

            }
            else {
                break;
            }
        }
        if (ans == true) {
            //printf("%d\n", i);
            count_road++;
        }
    }

    memset(check, false, sizeof(check));

    for (int j = 1; j <= N; j++) {
        ans = false;
        for (int i = 1; i <= N - 1; i++) {
            if (map[i][j] == map[i+1][j]) {
                ans = true;
            }
            else if (map[i][j] != map[i+1][j]) {
                if (map[i][j] - map[i+1][j] == -1) {
                    int cnt = 0;
                    for (int a = 0; a < L; a++) {
                        if (i - a > 0 && check[i-a][j] == false) {
                            if (map[i][j] == map[i-a][j]) {
                                cnt++;
                                check[i-a][j] = true;
                            }
                        }
                        else
                            break;
                    }
                    if (cnt == L) {
                        ans = true;
                    }
                    else
                        ans = false;
                }
                else if (map[i][j] - map[i+1][j] == 1) {
                    int cnt = 0;
                    for (int a = 1; a <= L; a++) {
                        if (i + a <= N && check[i+a][j] == false) {
                            if (map[i][j] - map[i+a][j] == 1) {
                                cnt++;
                                check[i+a][j] = true;
                            }
                        }
                        else
                            break;
                    }
                    if (cnt == L) {
                        ans = true;
                    }
                    else
                        ans = false;
                }
                else {
                    ans = false;
                }
            }
            if (ans == true) {

            }
            else {
                break;
            }
        }
        if (ans == true) {
            //printf("%d\n", j);
            count_road++;
        }
    }
    printf("%d", count_road);
    return 0;
}