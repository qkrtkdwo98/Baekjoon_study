#include <iostream>
#include <vector>
using namespace std;

int N, S;
int ans;
vector <int> v;

void func(int cnt, int sum) {
	if (cnt == N) {
		if (sum == S) ans++;
		return;
	}
	func(cnt + 1, sum);
	func(cnt + 1, sum + v[cnt]);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int arr = 0;
		cin >> arr;
		v.push_back(arr);
	}
	func(0,0);
	if (S == 0) ans--;
	cout << ans;

	return 0;
}