//
//  1463(1로 만들기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/31.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAX 1000001

//ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int main(){
    
    int arr[MAX];
    int num; cin >> num;
    for(int i = 2 ; i <= num ; i++){
        arr[i] = arr[i-1] + 1;
        if(i%3 == 0) arr[i] = min(arr[i/3] + 1, arr[i]);
        if(i%2 == 0) arr[i] = min(arr[i/2] + 1, arr[i]);
    }
    cout << arr[num] << '\n';
    return 0;
}
