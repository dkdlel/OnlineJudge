//
//  10844(쉬운 계단 수).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/01.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MOD 1000000000

//ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int main(){
    
    int arr[101][10] = {0};
    int ans = 0;
    
    int num; cin >> num;
    for(int i = 0 ; i < 10 ; i++) arr[1][i] = 1;
    for(int i = 2 ; i <= num ; i++){
        for(int j = 0 ; j < 10; j++){
            if(j == 0) arr[i][j] = arr[i-1][j+1] % MOD;
            else if(j == 9) arr[i][j] = arr[i-1][j-1] % MOD;
            else arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % MOD;
        }
    }
    for(int i = 1 ; i < 10 ; i++)  ans = (ans+arr[num][i]) % MOD;
    cout << ans << '\n';
    return 0;
}
