/*
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	long long d[91][2] = { 0 };

	d[1][0] = 0;
	d[1][1] = 1;
	d[2][0] = 1;
	d[2][1] = 0;
	for (int i = 3; i <= n; i++) {
		d[i][0] = d[i - 1][1] + d[i - 1][0];
		d[i][1] = d[i - 1][0];
	}
	cout << d[n][0] + d[n][1]<<"\n";

	return 0;
}
*/