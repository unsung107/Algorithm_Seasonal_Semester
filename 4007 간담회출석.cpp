#include <stdio.h>

struct Route {
    int end;
    Route* nxt;
    int cost;

    Route() {
        end = 0;
        nxt = nullptr;
        cost = 0;
    };
    Route(int end, Route* nxt, int cost): end(end), nxt(nxt), cost(cost) {};
} con[500005];


int length = 0;
Route* mem[50005];
Route heap[500005];
void heappush(Route x) {
    if (length++ == 0) {
        heap[1] = x;
        return;
    };
    heap[++length] = x;
    int child = length;
    int parent = child / 2;

    while (parent > 0&& heap[parent].cost > heap[child].cost) {
        Route tmp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = tmp;

        child = parent;
        parent = child / 2;
    }
    return ;
}

Route heappop() {
    if (length == 0) {
        return Route();
    };
    Route result = heap[1];
    heap[1] = heap[length--];

    int parent = 1;
    int child = 2 * parent;

    if (child + 1 <= length) child = heap[child].cost < heap[child + 1].cost ? child : child + 1;

    while (child <= length && heap[child].cost < heap[parent].cost) {
        Route tmp = heap[child];
        heap[child] = heap[parent];
        heap[parent] = tmp;

        parent = child;
        child = parent * 2;

        if (child + 1 <= length) child = heap[child].cost < heap[child + 1].cost ? child : child + 1;
    }
    return result;
}
bool visited[50005];
int main() {

    int tc, result = 0;
    scanf("%d", &tc);
    for (int ro = 1; ro <= tc; ro++) {
        int N, M, X;
        scanf("%d %d %d", &N, &M, &X);
        length = 0;
        for (int m = 0; m <= M; m++) mem[m] = nullptr, visited[m] = false;
        for (int m = 0; m < M; m++) {
            int s, e, c;
            scanf("%d %d %d", &s, &e, &c);
            heappush(Route(s, mem[e], c));
            con[m] = Route(e, mem[s], c);
            mem[s] = &con[m];
        }
        int start = X;
        for (Route* edge = mem[start]; edge != nullptr; edge = edge -> nxt) {
            if (visited[edge -> end]) continue;
            // printf("%d", edge -> end);
            visited[edge -> end] = true;
            heappush(Route(edge -> end, mem[edge -> end], edge -> cost));
            // printf("%d", edge -> nxt -> end);
        }
        // printf("lkjljlk");
        while (length > 0) {
            Route now = heappop();
            for (Route* edge = now.nxt; edge != nullptr; edge = edge -> nxt) {
                // printf("%d 1 ", edge -> end);
                if (visited[edge -> end]) continue;
                visited[edge -> end] = true;
                if (edge -> end == start) {
                    if (result < edge -> cost) {
                        result = edge -> cost;
                    }
                    continue;
                } 
                heappush(Route(edge -> end, edge -> nxt, edge->cost + now.cost));
            }
            // printf("%d", length);
        }
        printf("#%d %d", ro, result);

    }

    return 0;
}