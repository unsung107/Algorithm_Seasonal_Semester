#include <iostream>
#include <queue>

using namespace std;

struct rocation {
    int y;
    int x;
    int gar;
    int near_gar;
    rocation(int y, int x, int gar, int near_gar): x(x), y(y), gar(gar), near_gar(near_gar){
    };
};

struct check {
    bool operator()(rocation t, rocation u){
        if (t.gar == u.gar) {
            return t.near_gar > u.near_gar;
        };
        return t.gar > u.gar;
    };
};

int main() {
    priority_queue<rocation, vector<rocation>, check> pq;

    int dys[4] = {-1, 1, 0, 0};
    int dxs[4] = {0, 0, -1, 1};
    int H, W;
    cin >> H >> W;
    char board[H][W];
    int visited[H][W];
    bool already[H][W];
    for (int y = 0; y < H; y++){
        for (int x = 0; x < W; x ++){
            visited[y][x] = 0;
            already[y][x] = false;
        };
    };
    char letter;
    int start_y, start_x, cnt = 2;
    for (int h = 0; h < H; h ++) {
        for (int w = 0; w < W; w ++ ){
            cin >> letter;
            board[h][w] = letter;
            if (letter == 'g') {
                visited[h][w] = 1;
                for (int idx = 0; idx < 4; idx ++) {
                    int rh = h + dys[idx];
                    int rw = w + dxs[idx];
                    if (rh >= 0 && rh < H && rw >= 0 && rw < W && board[rh][rw] != 'g') {
                        visited[rh][rw] = cnt ++;
                    };
                };
            };
            if (letter == 'S') {
                start_y = h;
                start_x = w;
            };
        };
    };
    if (visited[start_y][start_x] >= 2) {
        pq.push(rocation(start_y, start_x, 0, 1));
    } else {
        pq.push(rocation(start_y, start_x, 0, 0));
    };
    already[start_y][start_x] = true;
    int result_gar, result_near_gar;
    bool gar_visited[cnt] = {false, };
    while (pq.size()) {
        rocation now = pq.top();
        pq.pop();
        if (board[now.y][now.x] == 'F') {
            result_gar = now.gar;
            if (visited[now.y][now.x] == 2) {
                result_near_gar = now.near_gar - 1;
            } else {
                result_near_gar = now.near_gar;
            };
            break;
        };
        
        for (int idx = 0; idx < 4; idx ++) {
            int ry = now.y + dys[idx];
            int rx = now.x + dxs[idx];
            if (ry >= 0 && ry < H && rx >= 0 && rx < W && !already[ry][rx]) {
                already[ry][rx] = true;
                if (visited[ry][rx] == 1) {
                    pq.push(rocation(ry, rx, now.gar + 1, now.near_gar));
                } else if (visited[ry][rx] >= 2 && !gar_visited[visited[ry][rx]])
                {   
                    gar_visited[visited[ry][rx]] = true;
                    pq.push(rocation(ry, rx, now.gar, now.near_gar + 1));
                } else
                {
                    pq.push(rocation(ry, rx, now.gar, now.near_gar));
                };
            };
        };
    };
    for (int c = 0; c < cnt; c ++) {
        cout << gar_visited[c];
    };
    cout << result_gar << ' ' << result_near_gar << endl;

    return 0;
}