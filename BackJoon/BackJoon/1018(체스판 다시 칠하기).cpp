//
//  1018(체스판 다시 칠하기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/22.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include<iostream>
#include<vector>
#include <string>
using namespace std;

string input[50], start_W[8], start_B[8];
int n1, n2, mini = 9999999;

int cal_W(int i, int j) {
    int cnt = 0;
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            if (start_W[a][b] != input[a + i][b + j]) cnt++;
        }
    }
    return cnt;
}
int cal_B(int i, int j) {
    int cnt = 0;
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 8; b++) {
            if (start_B[a][b] != input[a + i][b + j]) cnt++;
        }
    }
    return cnt;
}
int main() {

    for (int i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            start_W[i] = "WBWBWBWB";
            start_B[i] = "BWBWBWBW";
        }
        else {
            start_W[i] = "BWBWBWBW";
            start_B[i] = "WBWBWBWB";
        }
    }

    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++) cin >> input[i];

    for (int i = 0; i + 8 <= n1; i++) {
        for (int j = 0; j + 8 <= n2; j++) {
            int W_cnt = cal_W(i, j);
            int B_cnt = cal_B(i, j);
            int WB_min = W_cnt > B_cnt ? B_cnt : W_cnt;
            mini = mini > WB_min ? WB_min : mini;
        }
    }
    cout << mini << '\n';
    return 0;
}

