#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct Node{
    int m;
    int c;
    Node(int cur, int move) {
        c = cur;
        m = move;
    };
};

int main() {

    int sumin, bro, bro_step = 0;
    cin >> sumin;
    cin >> bro;
    
    int visited[2][500001];
    fill_n(visited[0], 500001, -1);
    fill_n(visited[1], 500001, -1);

    queue<Node> q;
    q.push(Node(sumin, 0));
    int length, mod2;
    bool flag = false;
    int result = -1;

    while (q.size()) {
        if (bro > 500000) break;

        length = q.size();
        // cout << length << endl;
        for (int i = 0; i < length; i ++) {
            Node node = q.front();
            q.pop();
            mod2 = node.m % 2;
            // cout << node.c << node.m << visited[node.c] << endl;
            if (node.c < 0 || node.c > 500000) continue;
            if (visited[mod2][node.c] != -1) continue;

            visited[mod2][node.c] = node.m;

            q.push(Node(node.c + 1, node.m + 1));
            q.push(Node(node.c - 1, node.m + 1));
            q.push(Node(2 * node.c, node.m + 1));
            // cout << node.c << node.m << bro << bro_step << endl;
        }; 
    };
    int sum = 0;
    while (1) {
        sum = bro + (bro_step * (bro_step + 1) / 2);
        mod2 = bro_step % 2;
        if (sum > 500000) {
            break;
        }
        if (visited[mod2][sum] != -1 && visited[mod2][sum] <= bro_step) {
            result = bro_step;
            break;
        };
        bro_step++;
    };
    cout << result;
    return 0;
};
