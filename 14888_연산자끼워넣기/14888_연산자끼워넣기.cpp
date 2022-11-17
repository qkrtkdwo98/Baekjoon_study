#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[12];
int oper[4];
int max_ = -1000000001;
int min_ = 1000000001;

vector<int> v;

int plus_(int a, int b) {
    return a+b;
}
int minus_(int a, int b) {
    return a-b;
}
int multi(int a, int b) {
    return a*b;
}
int divide(int a, int b) {
    return a/b;
}

int main() {
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &oper[i]);
        if (oper[i] > 0) {
            for (int j = 0; j < oper[i]; j++) {
                v.push_back(i);
            }
        }
    }
    int sum = 0;
    do {
        sum = A[1];
        for (int i = 2; i <= N; i++) {
            
            if (v[i - 2] == 0)
                sum = plus_(sum, A[i]);
            else if (v[i - 2] == 1)
                sum = minus_(sum, A[i]);
            else if (v[i - 2] == 2)
                sum = multi(sum, A[i]);
            else if (v[i - 2] == 3)
                sum = divide(sum, A[i]);
        }

        if (min_ > sum)
            min_ = sum;
        if (max_ < sum)
            max_ = sum;

    } while (next_permutation(v.begin(), v.end()));

    printf("%d\n%d", max_, min_);

    return 0;
}