#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int bunmo(int under) { //nCr������ �и�
    if (under == 1) return 1;
    while (under > 1) {
    under *= bunmo(under - 1);
    return under;
 }
}

int bunja(int rvalue, int nrgap) { //nCr������ ����
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

    cout << "���� ���� �� : ";
    cin >> n;

    if (n % 2 == 0) {
        for (int r = 1; r < n / 2; r++ ) {
            way += bunja(r, n - r)/bunmo(r);
        }
        way += 2; // ¦��(�� ������ ���� ��, �� ������ ���� ��)
    }
    else {
        for (int r = 1; r - 1 < n / 2; r++) {
            way += bunja(r, n - r) / bunmo(r);
        }
        way += 1; // Ȧ��(�� �������� ������ ��� ����)
    }

    cout << "������ ��� �� : " << way;

    return 0;
}