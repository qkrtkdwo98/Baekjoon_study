#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	cin >> n;

	long long p[101][10] = {0};
	long long a = 1000000000;
	for (int i = 1; i <= 9; i++)
		p[1][i] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 < 0)
				p[i][j] += p[i - 1][j + 1];
			else if (j + 1 > 9)
				p[i][j] += p[i - 1][j - 1];
			else
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j + 1];
			p[i][j] %= a;
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += p[n][i];
	ans %= a;
	cout << ans;
		
	return 0;
}