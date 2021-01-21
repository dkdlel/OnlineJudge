//
//  2798(블랙잭).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/21.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N, M, result = 0, sum;
    vector<int> arr;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        arr.push_back(n);
    }

    for (int i = 0; i < N; i++) {
        sum = arr[i];
        for (int j = i + 1; j < N; j++) {
            sum += arr[j];
            for (int k = j + 1; k < N; k++) {
                if (sum + arr[k] <= M) {
                    if (sum + arr[k] > result) result = sum + arr[k];
                }
            }
            sum -= arr[j];
        }
    }

    cout << result << '\n';
    return 0;
}
