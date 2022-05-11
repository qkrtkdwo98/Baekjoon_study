#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int check(vector<string> &a) {
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				if (a[i][j] == a[i][j + 1]) {
					cnt++;
				}
				else {
					cnt = 1;
				}
				if (ans < cnt) ans = cnt;
			}
		}
		cnt = 1;
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				if (a[j][i] == a[j + 1][i]) {
			
					cnt++;
				}
				else {
					cnt = 1;
				}
				if (ans < cnt) ans = cnt;
			}
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int ans = 0;
	cin >> n;

	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n) {
				if (a[i][j + 1] != a[i][j]) {
					swap(a[i][j], a[i][j + 1]);
					int temp = check(a);
					if (ans < temp) ans = temp;
					swap(a[i][j], a[i][j + 1]);
				}
				else;
			}
			if (i + 1 < n) {
				if (a[i + 1][j] != a[i][j]) {
					swap(a[i][j], a[i + 1][j]);
					int temp = check(a);
					if (ans < temp) ans = temp;
					swap(a[i][j], a[i + 1][j]);
				}
				else;
			}			
		}
	}
	cout << ans<<endl;
	return 0;
}