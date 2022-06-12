#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long E, S, M;
	long long ans = 0;
	cin >> E >> S >> M;

	while (1) {
		if (ans % 15 == E-1)
			if (ans % 28 == S-1) 
				if (ans % 19 == M-1) 
					break;

		ans++;
	}
	
	cout <<ans+1;
	
	return  0;
}