#include <stdio.h>

using namespace std;

void push(int idx, long long arr[]) {
    int parent;
    if (idx % 2 && idx / 2 > 0) {
        parent = idx/2;
        arr[parent] = arr[idx - 1] + arr[idx];
        push(parent, arr);
    }
    //if (parent % 2 && parent / 2 > 0 ) push(parent, arr);
}

void update(int idx, long long val, long long arr[]) {
    arr[idx] = val;
    if (idx / 2 > 0) {
        if (idx % 2) {
            update(idx / 2, arr[idx - 1] + arr[idx], arr);
        } else {
            update(idx / 2, arr[idx] + arr[idx + 1], arr);
        }
    }
}

long long sum(int l, int r, long long arr[]) {
    // if (l > r) return 0;
    long long result = 0;
    if (l % 2) {
        result += arr[l++];
    }
    if (!(r % 2)) {
        result += arr[r--];
    }
    if (l > r) return result;
    result += sum(l / 2, r / 2, arr);
    return result;
}

long long indexed_tree[400005], n;
int main() {
    int tc;
    scanf("%d", &tc);

    for (int ro = 1; ro <= tc; ro++) {
        int N, M;
        scanf("%d %d",&N, &M);
        printf("#%d ", ro);
        int degree, idx;
        for (degree = 1; degree < 2 * N; degree *= 2 );

        for (idx = 0; idx < N; idx++) {
            scanf("%lld ", &n);
            indexed_tree[degree / 2 + idx] = n;
            if ((degree / 2 + idx) % 2) push(degree / 2 + idx, indexed_tree);
        }
        for (idx = N; idx < degree / 2; idx++) {
            indexed_tree[degree / 2 + idx] = 0;
            if ((degree / 2 + idx) % 2) push(degree / 2 + idx, indexed_tree);
        }

        for (int ca = 0; ca < M; ca++) {
            int c;
            scanf("%d", &c);
            if (c == 1) {
                int x;
                long long y;
                scanf("%d %lld", &x, &y);
                update(degree / 2 + x - 1, indexed_tree[degree / 2 + x - 1] + y, indexed_tree);
            } else {
                int l, r;
                scanf("%d %d", &l, &r);
                printf("%lld ", sum(degree / 2 + l - 1, degree / 2 + r - 1, indexed_tree));
            }
        }
        printf("\n");
        // for (idx = 0; idx < degree; idx ++) printf("%lld ", indexed_tree[idx]);
    }
    return 0;
}