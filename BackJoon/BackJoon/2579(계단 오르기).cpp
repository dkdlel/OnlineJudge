//
//  2579(계단오르기).cpp
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

int arr[301], cache[301];

int main() {
    
    int t; fcin >> t;
    for(int i = 0 ; i < t ; i++) fcin >> arr[i];
    
    cache[0] = arr[0];
    cache[1] = max(arr[1], arr[0] + arr[1]);
    cache[2] = max(arr[2] + arr[1], arr[2] + arr[0]);
    
    for(int i = 3 ; i < t ; i++) cache[i] = max(cache[i-2] + arr[i], cache[i-3] + arr[i-1] + arr[i]);
    
    cout << cache[t-1] << '\n';

    return 0;
}
