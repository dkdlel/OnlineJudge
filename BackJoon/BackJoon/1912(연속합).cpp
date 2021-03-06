//
//  1912(연속합).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/02.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 100001

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[MAX], cache[MAX];

int findMax(int t, int ans){
    if(!ans){
        ans = -987654321;
        for(int i = 0 ; i < t ; i++)
            if(ans < arr[i])
                ans = arr[i];
    }
    return ans;
}

int main(){
    
//// sol2
    int t; fcin >> t;
    for(int i = 0 ; i < t ; i++) fcin >> arr[i];
    
    int sum = 0, ans = 0;
    for(int i = 0 ; i < t ; i++){
        sum += arr[i];
        if(sum <= 0) cache[i] = sum = 0;
        else cache[i] = sum;
        if(ans < cache[i]) ans = cache[i];
    }
    
    cout << findMax(t, ans) << '\n';
    
    //// sol1
    //    int t; fcin >> t;
    //    for(int i = 0 ; i < t ; i++) fcin >> arr[i];
    //
    //    cache[0] = arr[0];
    //    int ans = arr[0];
    //
    //    for(int i = 1 ; i < t ; i++){
    //        cache[i] = cache[i-1] + arr[i] > arr[i] ? cache[i-1] + arr[i] : arr[i];
    //        ans = ans > cache[i] ? ans : cache[i];
    //    }
    
//// overtime
//    for(int i = 0 ; i < t ; i++){
//            int max_sum = -987654321, sum = 0;
//            for(int j = i ; j < t ; j++){
//                sum += vec[j];
//                max_sum = max(max_sum, sum);
//            }
//            ans = max(ans, max_sum);
//        }
    
//    cout << ans << '\n';
    
    return 0;
}
