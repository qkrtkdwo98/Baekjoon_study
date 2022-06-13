#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;
	bool check[10];
	for (int i = 0; i < 10; i++) {
		check[i]=true;
	}
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		check[num] = false;
	}

	int ans = N - 100;
	if (ans < 0) {
		ans = -ans;
	}

	for (int i = 0; i <= 1000000; i++) {
		int C = i;
		int click = 0;
		if (C == 0) {
			if (!check[0])
				click = 0;
			else
				click = 1;
		}
		else {
			while (C > 0) {
				if (!check[C % 10]) {
					click = 0;
					break;
				}
				click++;
				C /= 10;
			}
		}
		if (click > 0) {
			int press = i - N;
			if (press < 0) {
				press = -press;
			}
			if (ans > click + press) {
				ans = click + press;
			}
		}
	}
	cout << ans <<endl;
	return 0;
}