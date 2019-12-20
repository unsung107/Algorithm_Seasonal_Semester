#include <stdio.h>

using namespace std;

struct Route {
    int x;
    int y;
    int cost;
    Route(): x(0), y(0), cost(0) {};
    Route(int tx, int ty, int tcost) {
        x = tx;
        y = ty;
        cost = tcost;
    };
} heap[200005];

int length = 0;
void heappush(Route route) {
    if (length == 0) {
        heap[++length] = route;
        return;
    };
    heap[++length] = route;
    int child = length;
    int parent = child / 2;
    while (parent > 0 && heap[parent].cost > heap[child].cost) {
        Route temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;
        child = parent;
        parent = child / 2;
    }
}
int find(int x, int arr[]) {
    if (x == arr[x]) return x;
    return arr[x] = find(arr[x], arr);
};
void unionDS(int x, int y, int arr[]) {
    arr[find(y, arr)] = find(x, arr);
}

int DS[50005];
Route heappop(Route arr[]) {
    Route result = arr[1];
    arr[1] = heap[length--];
    // heap[length + 1] = Route();
    int parent = 1;
    int child = parent * 2;
    if (child + 1 <= length){
        child = heap[child].cost <= heap[child + 1].cost ? child : child + 1;
    }
    while (child <= length && heap[child].cost < heap[parent].cost) {
        Route temp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = temp;
        parent = child;
        child = parent * 2;

        if (child + 1 <= length){
            child = heap[child].cost <= heap[child + 1].cost ? child : child + 1;
        }
    }
    return result;
}

int main() {

    int tc;
    scanf("%d", &tc);
    for (int ro = 1; ro <= tc; ro++) {
        for (int idx = 0; idx < 50005; idx++) DS[idx] = idx;
        int N, M, cnt = 2;
        long long result = 0;
        scanf("%d %d", &N, &M);
        length = 0;
        for (int m = 0; m < M; m++) {
            int x, y, cost;
            scanf("%d %d %d", &x, &y, &cost);
            Route route(x, y, cost);
            heappush(route);
        }
        Route start = heappop(heap);
        unionDS(start.x, start.y, DS);
        result += start.cost;

        while (cnt < N){
            Route now = heappop(heap);
            if (find(start.x, DS) != find(now.x, DS) || find(start.x, DS) != find(now.y, DS)) {
                if (find(start.x, DS) != find(now.x, DS)) cnt ++;
                if (find(start.x, DS) != find(now.y, DS)) cnt ++;
                unionDS(start.x, now.x, DS);
                unionDS(start.x, now.y, DS);
                result += now.cost;
            }
            // for (int idx = 1; idx < N; idx++) {
            //     printf("%d ", DS[idx]);
            // };
            // printf("\n");
        }
        printf("#%d %lld\n", ro, result);
    }

    return 0;
}