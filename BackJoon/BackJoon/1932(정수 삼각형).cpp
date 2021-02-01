//
//  1932(정수 삼각형).cpp
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

int arr[502][502], cache[502][502];

int main(){
    
    int t; fcin >> t;
    
    for(int i = 1 ; i <= t ; i++){
        for(int j = 1 ; j <= i ; j++){
            int n; fcin >> n;
            arr[i][j] = n;
        }
    }
    cache[1][1] = arr[1][1];
    
    for(int i = 2 ; i <= t ; i++){
        for(int j = 1 ; j <= i ; j++){
            cache[i][j] = arr[i][j] + max(cache[i-1][j-1], cache[i-1][j]);
        }
    }
    
    int ans = 0;
    for(int i = 1 ; i <= t ; i++){
        ans = max(ans, cache[t][i]);
    }
    
    cout << ans << '\n';

    return 0;
}
