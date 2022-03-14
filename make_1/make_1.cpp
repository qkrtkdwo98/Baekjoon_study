#include <iostream>
#include <vector>
using namespace std;

vector<int> d(1000001);
//int d[1000001];
int cal(int X) {
	if (X == 1)
		return 0;
	if (d[X] > 0)
		return d[X];
	d[X] = cal(X - 1) + 1;
	if (X % 2 == 0) {
		int temp = cal(X / 2)+1;
		if (d[X] > temp)
			d[X] = temp;
	}
	if (X % 3 == 0) {
		int temp = cal(X / 3) + 1;
		if (d[X] > temp)
			d[X] = temp;
	}
	return d[X];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int X = 0;
	cin >> X;
	cout << cal(X)<<'\n';

	return 0;
}