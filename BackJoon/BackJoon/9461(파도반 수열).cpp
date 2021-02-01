//
//  9461(파도반 수열).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/29.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define ll long long
//ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

ll arr[101] = {1,1,1,2,2};

int main(){
    
    for(int i = 5 ; i < 101 ; i++) arr[i] = arr[i-1] + arr[i-5];
    int testcase; cin >> testcase;
    while(testcase--){
        int n; cin >> n;
        cout << arr[n-1] << '\n';
    }
    return 0;
}
