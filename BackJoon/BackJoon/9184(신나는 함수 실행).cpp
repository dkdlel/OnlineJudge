//
//  9184(신나는 함수 실행).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/29.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int cache[21][21][21];

int w(int a, int b, int c){
    
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20,20,20);
    
    int& ret = cache[a][b][c];
    if(ret) return ret; // 계산된 값이 있음
    
    if(a < b && b < c) return ret =  w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main(){
    
    while(1){
        int a, b, c; fcin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
    return 0;
}
