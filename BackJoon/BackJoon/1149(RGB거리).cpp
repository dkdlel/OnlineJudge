//
//  1149(RGB거리).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/29.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[1001][3], cache[1001][3];

int main(){
    
    int t; fcin >> t;
    for(int i = 0 ; i < t ; i++){
        for(int j = 0 ; j < 3 ; j++){
            int n; fcin >> n;
            arr[i][j] = n;
        }
    }
    cache[0][0] = arr[0][0]; cache[0][1] = arr[0][1]; cache[0][2] = arr[0][2];
    
    for(int i = 1 ; i < t ; i++){
        cache[i][0] = arr[i][0] + min(cache[i-1][1], cache[i-1][2]);
        cache[i][1] = arr[i][1] + min(cache[i-1][0], cache[i-1][2]);
        cache[i][2] = arr[i][2] + min(cache[i-1][0], cache[i-1][1]);
    }
    
    cout << min(cache[t-1][0], min(cache[t-1][1],cache[t-1][2])) << '\n';
    
    return 0;
}
