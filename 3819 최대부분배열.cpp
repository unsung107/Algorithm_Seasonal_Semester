#include <iostream>

using namespace std;

int main()
{   
    
    int tc;
    cin >> tc;
    for (int ro = 0; ro < tc; ro ++) {

        int N;
        cin >> N;

        int temp_sum = 0;
        int result = -1001;
        int min_sum = 0;

        for (int i = 0; i < N; i++) {
            int number;
            cin >> number;
            temp_sum += number;

            if (temp_sum - min_sum > result) {
                result = temp_sum - min_sum;
            };
            if (temp_sum < min_sum) {
                min_sum = temp_sum;
            };

        };
        if (result == -1001) {
            result = temp_sum;
        };
        cout << '#' << ro + 1 << ' ' << result << endl;
    }

    return 0;
}