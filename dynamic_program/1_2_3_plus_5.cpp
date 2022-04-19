/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<vector<long long>> p(100001,vector<long long>(4,0)); //자료형별 크기 체크 필요
	
	p[1][1] = 1;
	p[2][2] = 1;
	p[3][1] = 1;
	p[3][2] = 1;
	p[3][3] = 1;
	p[4][1] = 2;
	p[4][2] = 0;
	p[4][3] = 1;
	for (int i = 5; i <= 100000; i++) {
		p[i][1] = (p[i - 1][2] + p[i - 1][3])%1000000009;
		p[i][2] = (p[i - 2][1] + p[i - 2][3])%1000000009;
		p[i][3] = (p[i - 3][1] + p[i - 3][2])%1000000009;
	}
	int t;
	cin >> t;
	int n;
	queue<int> q;
	while (t--) {
		cin >> n;
		q.push((p[n][1] + p[n][2] + p[n][3])%1000000009);
	}

	while(!q.empty()) {
		cout<<q.front()<<"\n";
		q.pop();
	}
	return 0;
}
*/