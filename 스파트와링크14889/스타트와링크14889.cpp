#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int map[21][21];
vector<int> v1;
vector<int> v2;
int ans = 1000;
int sum1 = 0, sum2 = 0;
int main() {
	int N = 0;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d",&map[i][j]);
		}
	}
	
	vector<bool> temp(N, false);
	for (int i = 0; i < (N / 2); i++)
		temp[i] = true;
	do {
		v1.clear();
		v2.clear();
		for (int j = 0; j < N; j++) {
			if (temp[j]) {
				v1.push_back(j+1);
			}
			else {
				v2.push_back(j+1);
			}
		}
		sum1 = 0;
		sum2 = 0;
		for (int l = 0; l < (N / 2); l++) {
			for (int m = 0; m < N / 2; m++) {
				if (l != m) {
					sum1 += map[v1[l]][v1[m]];
					sum2 += map[v2[l]][v2[m]];
				}
			}
		}
		if (ans > abs(sum1 - sum2)) {
			ans = abs(sum1 - sum2);
		}
	} while (prev_permutation(temp.begin(), temp.end()));
	printf("%d", ans);

	return 0;
}