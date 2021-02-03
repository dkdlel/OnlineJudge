//
//  9251(LCS).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/02.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[1001][1001];

int main(){
    
    string str1, str2; fcin >> str1 >> str2;
    
    for(int i = 0 ; i < str1.size() ; i++){
        for(int j = 0 ; j < str2.size() ; j++){
            if(str1[i] == str2[j]) arr[i+1][j+1] = arr[i][j] + 1;
            else arr[i+1][j+1] = max(arr[i][j+1], arr[i+1][j]);
        }
    }
    
    cout << arr[str1.size()][str2.size()] << '\n';
    
    return 0;
}
