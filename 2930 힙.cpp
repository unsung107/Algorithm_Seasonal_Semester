#include <iostream>
#include <stdio.h>
int length = 0;
using namespace std;
int heappop(int arr[]) {
    if (::length == 0) {
        return -1;
    };

    int result = arr[1];
    arr[1] = arr[::length--];
    int now_idx = 1;
    int nxt_idx = 2 * now_idx;
    if (nxt_idx + 1 <= length) {
        nxt_idx = arr[nxt_idx] >= arr[nxt_idx + 1] ? nxt_idx : nxt_idx + 1;
    }

    while (nxt_idx <= length && arr[now_idx] < arr[nxt_idx]) {
        int temp = arr[now_idx];
        arr[now_idx] = arr[nxt_idx];
        arr[nxt_idx] = temp;
        
        now_idx = nxt_idx;
        nxt_idx = 2 * now_idx;
        if (nxt_idx + 1 <= length) {
            nxt_idx = arr[nxt_idx] >= arr[nxt_idx + 1] ? nxt_idx : nxt_idx + 1;
        }        
    }
    return result;
};

int heappush(int n, int arr[]) {
    int last = ::length + 1;
    arr[last] = n;

    while (last / 2 > 0 && arr[last] > arr[last / 2]) {
        int temp = arr[last];

        arr[last] = arr[last / 2];
        arr[last / 2] = temp;
        last /= 2;
    };
    ::length++;
};

int main() {

    int tc;
    // cin >> tc;
    scanf("%d", &tc);

    for (int ro = 1; ro <= tc; ro++ ){
        int N;
        length = 0;
        cin >> N;
        cout << '#' << ro << ' '; 
        int heap[100001];
        
        for (int i = 0; i < N; i++) {
            int k;
            scanf("%d", &k);
            if (k == 1) {
                int n;
                scanf("%d", &n);
                heappush(n, heap);
            } else {
                printf("%d ", heappop(heap));
            };
        }
        printf("\n");
    }
    return 0;
}