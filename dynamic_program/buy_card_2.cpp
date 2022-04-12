/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> p(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = 1000 * 10000;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i], d[i -j ] + p[j]);
		}
	}
	
	cout << d[n];

	return 0;
}
*/