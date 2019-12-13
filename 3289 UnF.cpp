#include <iostream>
#include <stdio.h>

using namespace std;
int find(int x, int arr[]) {
    if (x == arr[x]) return x;
    return arr[x] = find(arr[x], arr);
};

void addunion(int x, int y, int arr[]) {
    if (find(x, arr) != find(y, arr)) {
        arr[find(x, arr)] = find(y, arr);
    }
};

int checkunion(int x, int y, int arr[]) {
    if (find(x, arr) == find(y, arr)) return 1;
    return 0;
};
int unions[1000005];
int main() {
    
    int tc;
    cin >> tc;

    for (int ro = 1; ro <= tc; ro++) {

        int N, M;
        cin >> N >> M;
        cout << '#' << ro << ' ';
        for (int idx=0; idx <= N; idx++) {
            unions[idx] = idx;
        }

        for (int ca=0; ca < M; ca++) {
            int c, x, y;
            scanf("%d %d %d", &c, &x, &y);
            if (c == 1) {
                printf("%d", checkunion(x, y, unions));
            } else {
                addunion(x, y, unions);
            }
        };
        cout << endl;

    };

    
    return 0;
}