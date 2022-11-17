#include <iostream>
#include <queue>
using namespace std;

int map[101][101];

typedef struct {
    int x;
    int y;
}xy;

queue <xy> handle;
queue <xy> snake;

int main() {
    int N = 0, K = 0;
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        int a = 0, b = 0;
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    int L = 0;
    scanf("%d", &L);
    
    for (int i = 0; i < L; i++) {
        int X = 0;
        char C;
        scanf("%d %c", &X, &C);
        if (C == 'L')
            handle.push({ X+1, 1 });
        else if (C == 'D')
            handle.push({ X+1, 2 });
    }
    int x = 1, y = 1;
    snake.push({ x, y });
    int count = 0;
    int head = 1; // 0 : 위/ 1 : 오른쪽/ 2 : 아래쪽/3 : 왼쪽
    int time = 0, order = 0;
    while (1) {
        count += 1;
        if (!handle.empty()) {
            time = handle.front().x;
            order = handle.front().y;
        }
        if (time == count) {
            if (order == 1) {
                if (head == 0) {
                    head = 3;
                    y -= 1;
                }
                else if (head == 1) {
                    head = 0;
                    x -= 1;
                }
                else if (head == 2) {
                    head = 1;
                    y += 1;
                }
                else if (head == 3) {
                    head = 2;
                    x += 1;
                }
            }
            else if (order == 2) {
                if (head == 0) {
                    head = 1;
                    y += 1;
                }
                else if (head == 1) {
                    head = 2;
                    x += 1;
                }
                else if (head == 2) {
                    head = 3;
                    y -= 1;
                }
                else if (head == 3) {
                    head = 0;
                    x -= 1;
                }
            }
            handle.pop();
        }
        else {
            if (head == 0)
                x -= 1;
            else if (head == 1)
                y += 1;
            else if (head == 2)
                x += 1;
            else if (head == 3)
                y -= 1;
        }
        if (x <= 0 || y <= 0 || x > N || y > N )
            break;

        if (map[x][y] == 2)
            break;

        snake.push({x,y});
        if (map[x][y] == 0) {
            map[snake.front().x][snake.front().y] = 0;
            snake.pop();
        }
        map[x][y] = 2;
    }
    printf("%d", count);
    return 0;
}