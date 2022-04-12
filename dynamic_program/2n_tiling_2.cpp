/*
#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int cnt[1001];
	cin >> n;

	cnt[1] = 1;
	cnt[2] = 3;
	cnt[3] = 5;
	if(n>3)
		for (int i = 4; i <= n; i++) {
			cnt[i] = cnt[i - 1] + cnt[i - 2]*2;
			cnt[i] = cnt[i] % 10007;
		}
	cout << cnt[n];

	return 0; 
}
*/