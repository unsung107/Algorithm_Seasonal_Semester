#include <iostream>

using namespace std;

void test_funt(int idx, int arr[]) {
    arr[idx] = 5;
}

int main() {
    int test[50];
    for (int i = 0; i < 50; i++) {
        cout << test[i] << ' ';
    }

    for (int i = 0; i < 50; i++) {
        test_funt(i, test);
    }

    for (int i = 0; i < 50; i++) {
        cout << test[i] << ' ';
    }

    return 0;
}