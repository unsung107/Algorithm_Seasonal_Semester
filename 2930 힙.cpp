#include <iostream>
#include <stdio.h>
int length = 0;
using namespace std;
// int heapsize(int arr[]) {
//     int length = 0;

//     for (int idx = 1; idx < 100001; idx++) {
//         if (arr[idx] == 0 || length == 100000) {
//             return length;
//         };
//         length++;
//     };
// };
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
    // while (2 * now_idx <= ::length) {
    //     int nxt_idx;
    //     if (::length >= 2 * now_idx + 1) {
    //         nxt_idx = arr[2 * now_idx] > arr[2 * now_idx + 1] ? 2 * now_idx : 2 * now_idx + 1;
    //     } else {
    //         nxt_idx = 2 * now_idx;
    //     };
    //     arr[now_idx] = arr[nxt_idx];
    //     arr[nxt_idx] = 0;
    //     if (nxt_idx == now_idx * 2 && nxt_idx + 1 == length) {
    //         arr[nxt_idx] = arr[nxt_idx + 1];
    //         arr[nxt_idx + 1] = 0;
    //     };
    //     now_idx = nxt_idx;
    // };
    // ::length--;
    return result;
};

int heappush(int n, int arr[]) {
    // int last = heapsize(arr) + 1;
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
            // cin >> k;
            scanf("%d", &k);
            if (k == 1) {
                int n;
                scanf("%d", &n);
                // cin >> n;
                heappush(n, heap);
            } else {
                // cout << heappop(heap) << ' ';
                printf("%d ", heappop(heap));
            };
        }
        // cout << endl;
        printf("\n");
    }
    return 0;
}