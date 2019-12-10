#include <iostream>
#include <queue>

using namespace std;

int main() {

    int tc;
    cin >> tc;

    for (int ro = 1; ro <= tc; ro++) {
        int N, K;
        cin >> N >> K;

        if (N > 50000) {
            cout << '#' << ro << ' ' << 1 << endl;
            continue;
        };

        int flash[N];
        priority_queue<int> pq;
        int max_wear_level;



        for (int n = 0; n < N; n++) {
            int temp;
            cin >> temp;
            flash[n] = temp;
        };

        for (int k = 0; k < K; k++) {
            int temp_k;
            cin >> temp_k;
            pq.push(temp_k);
        };

        int result = 0;
        int visited[200001] = {0};
        visited[0] = 0;
        while (pq.size()) {
            int now_size = pq.top();
            pq.pop();

            int min_idx;
            max_wear_level = 200001;
            for (int idx = 0; idx + now_size <= N; idx++) {
                if (visited[idx]) continue;
                int temp_max = 0;
                for (int di = 0; di < now_size; di++) {
                    if (temp_max < flash[idx + di]) {
                        temp_max = flash[idx + di];
                    };
                };
                if (temp_max < max_wear_level) {
                    min_idx = idx;
                    max_wear_level = temp_max;
                };
            };
            for (int di = 0; di < now_size; di++) {
                visited[min_idx + di] = true;
            };
            if (result < max_wear_level) result = max_wear_level;
        };
        // for (int k = 0; k < N; k++) {
        //     cout << visited[k];
        // };
        cout << '#' << ro << ' ' << result << endl;
    };

    return 0;
}