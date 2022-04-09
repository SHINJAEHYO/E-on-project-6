#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int bunmo(int under) { //nCr에서의 분모
    if (under == 1) return 1;
    while (under > 1) {
    under *= bunmo(under - 1);
    return under;
 }
}

int bunja(int rvalue, int nrgap) { //nCr에서의 분자
    int up = nrgap;
    for (int i = 1; i < rvalue; i++) {
        up = up * (nrgap - 1);
        nrgap--;
    }
    return up;
}

int main() {
    int n;
    int way = 0;

    cout << "피자 조각 수 : ";
    cin >> n;

    if (n % 2 == 0) {
        for (int r = 1; r < n / 2; r++ ) {
            way += bunja(r, n - r)/bunmo(r);
        }
        way += 2; // 짝수(한 조각씩 나눌 때, 두 조각씩 나눌 때)
    }
    else {
        for (int r = 1; r - 1 < n / 2; r++) {
            way += bunja(r, n - r) / bunmo(r);
        }
        way += 1; // 홀수(두 조각씩만 나누는 경우 없음)
    }

    cout << "나누는 방법 수 : " << way;

    return 0;
}