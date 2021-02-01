//
//  11053(가장 긴 증가하는 부분 수열).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/01.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[1001], cache[1001];

int main(){
    
    int t; fcin >> t;
    for(int i = 0 ; i < t ; i++) fcin >> arr[i];
    
    int ans = 0;
    for(int i = 0 ; i < t ; i++){
        cache[i] = 1;
        for(int j = 0 ; j < i ; j++){
            if(arr[j] < arr[i]) cache[i] = max(cache[i], cache[j] + 1);
        }
        ans = max(cache[i],ans);
    }
    
    cout << ans << '\n';
    
    return 0;
}
