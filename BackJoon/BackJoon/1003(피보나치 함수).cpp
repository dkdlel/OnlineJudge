//
//  1003(피보나치 함수).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/29.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[41] = {0, 1, 1};

int main(){
    
    for(int i = 3 ; i < 42 ; i++) arr[i] = arr[i-2] + arr[i-1];
    int testcase; fcin >> testcase;
    while(testcase--){
        int num; fcin >> num;
        if (num == 0) cout << "1 0\n";
        else if (num == 1) cout << "0 1\n";
        else cout << arr[num-1] << ' ' << arr[num] << '\n';
    }
    return 0;
}
