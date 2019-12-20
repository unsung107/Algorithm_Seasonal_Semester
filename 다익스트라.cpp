#include <stdio.h>
#define NN 100005
#define NM 1000005

long long dist[NN];
bool visited[NN];

struct LIST {
    int v, dist;
    LIST* next;

    LIST() {v=dist=0; next = nullptr;};
    LIST(int v, int dist, LIST* next): v(v), dist(dist), next(next) {};
} con[NM];

LIST* mem[NN];

struct INFO {
    int v;
    long long dist;

    INFO() {};
    INFO(int v, long long dist): v(v), dist(dist) {};
};
INFO heap[NM];
int heapN;
void init() {
    heapN = 0;
}
void push(INFO n) {
    heap[++heapN] = n;

    int idx = heapN;

    while (idx / 2 > 0) {
        if (heap[idx].dist < heap[idx/2].dist) {
            INFO tmp = heap[idx];
            heap[idx] = heap[idx/2];
            heap[idx/2] = heap[idx];
            idx /= 2;
        }
        else break;
    }
}
INFO pop() {
    if (heapN == 0) {
        return INFO();
    }
    INFO result = heap[1];
    heap[1] = heap[heapN--];

    int idx = 1;
    while (idx * 2 <= heapN) {
        int left = idx * 2;
        int right = left + 1;
        int target;
        if (heap[left].dist < heap[right].dist || right > heapN)
            target = left;
        else 
            target = right;
        
        if (heap[target].dist < heap[idx].dist) {
            INFO tmp = heap[idx];
            heap[idx] = heap[target];
            heap[target] = tmp;
            idx = target;
        } else break;
    }
    return result;
}

void input(int N, int M) {
    for (int m=1; m < N; m++) mem[m] = nullptr;
    for (int m=1; m <= M; m++) {
        int s, e, c;
        scanf("%d %d %d", &s, &e, &c);
        con[m] = LIST(e, c, mem[s]);
        mem[s] = &con[m];
    }
}

void dijk(int N, int M) {
    init();

    for (int i=1; i <= N; i++) visited[i] = 0, dist[i] = 1e11;
    dist[1] = 0;
    push(INFO(1, 0));

    while (heapN) {
        INFO now = pop();
        if (visited[now.v]) continue;
        visited[now.v] = 1;

        for (LIST* edge = mem[now.v]; edge != nullptr; edge = edge -> next) {
            if (dist[edge->v] > dist[now.v] + edge->dist){
                dist[edge->v] = dist[now.v] + edge->dist;
                push(INFO(edge->v, dist[edge->v]));
            }
        }
    }

}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    input(N, M);
    dijk(N, M);

    printf("%lld", dist[N]);
    
    return 0;
}