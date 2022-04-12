/*
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,t;
	int cnt[11];
	cin >> t;
	queue <int> q;
	while (t--) {
		cin >> n;
		cnt[1] = 1;
		cnt[2] = 2;
		cnt[3] = 4;
		if(n>3)
			for (int i = 4; i <= n; i++) {
				cnt[i] = cnt[i - 1] + cnt[i - 2] + cnt[i - 3];
			}

		q.push(cnt[n]);
	}
	while (!q.empty()) {
		cout << q.front()<<"\n";
		q.pop();
	}

	return 0;
}
*/