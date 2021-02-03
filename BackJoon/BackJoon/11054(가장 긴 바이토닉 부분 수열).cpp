//
//  11054(가장 긴 바이토닉 부분 수열).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/01.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[1001], front[1001], back[1001];

int main(){

    int t; fcin >> t;
    for(int i = 0 ; i < t ; i++) fcin >> arr[i];

    for(int i = 0 ; i < t ; i++){
        front[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i]) front[i] = max(front[i], front[j] + 1);
        }
    }

    for(int i = t-1 ; i >= 0 ; i--){
        back[i] = 1;
        for(int j = t-1 ; j >= i ; j--){
            if(arr[j] < arr[i]) back[i] = max(back[i], back[j] + 1);
        }
    }

    int ans = 0;
    for(int i = 0 ; i < t ; i++){
        ans = max(ans, front[i] + back[i]);
    }

    cout << ans - 1 << '\n';

    return 0;
}
