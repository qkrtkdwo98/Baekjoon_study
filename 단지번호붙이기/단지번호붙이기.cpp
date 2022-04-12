#include <cstdio>
#include <string>
#include <vector>
#include <queue>

using namespace std;
int num[26][26];
int check[26][26];
int x;
int y;
void bfs(int a,int b,int N) {
	queue<int> dx;
	queue<int> dy;
	check[a][b] = 1;
	dx.push(a);
	dy.push(b);
	while (!dx.empty() && !dy.empty()) {
		x = dx.front();
		dx.pop();
		y = dy.front();
		dy.pop();
		if (num[x][y] == 0) {
			if (x + 1 >= N) {
				dx.push(0);
			}
			if()
		}

	}
	num[a][b];

}

int main() {
	int N;
	scanf("%d",&N);
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d",&num[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bfs(i,j,N);

		}
		
	}
	for (int i =0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", num[i][j]);
		}
		printf("\n");
	}


	return 0;
}