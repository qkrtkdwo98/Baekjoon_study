#include <iostream>

using namespace std;

int A[1000001];

int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    int B = 0, C = 0;
    scanf("%d %d", &B, &C);

    long int ans = 0;

    ans += N;
    for (int i = 1; i <= N; i++) {
        if (A[i] - B <= 0)
            ans += 0;
        else if (((A[i] - B) % C )== 0)
            ans += ((A[i] - B) / C);
        else if(((A[i] - B) % C) != 0)
            ans += (((A[i] - B) / C) + 1);
    }
    printf("%ld", ans);

    return 0;
}