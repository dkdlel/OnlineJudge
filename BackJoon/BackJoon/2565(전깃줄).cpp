//
//  2565(전깃줄).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/02.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x,y;
};

bool operator <(position A, position B) {
   return A.x < B.x;
};

vector<position> vec;
int cache[101];


int main(){
    
    int t; fcin >> t;
    for(int i = 0 ; i < t ; i++) {
        int x,y; fcin >> x >> y;
        vec.push_back({x,y});
    }
    sort(vec.begin(), vec.end());
    
    int ans = 0;
    for(int i = 0 ; i < t ; i++){
        cache[i] = 1;
        for(int j = 0 ; j <= i ; j++){
            if(vec[i].y > vec[j].y) cache[i] = max(cache[i], cache[j] + 1);
        }
        ans = max(cache[i],ans);
    }
    
    cout << t - ans << '\n';
    
    return 0;
}
