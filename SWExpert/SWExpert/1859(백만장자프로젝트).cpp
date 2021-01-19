//
//  1859(백만장자프로젝트).cpp
//  SWExpert
//
//  Created by  JeJn on 2021/01/18.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/SWExpert/input.txt");
ofstream fcout("/Users/jejn/Desktop/SWExpert/output.txt");

vector<int> vec;

void init(){
    vec.clear();
    int n; fcin >> n;
    for(int i = 0 ; i < n ; i++){
        int num; fcin >> num;
        vec.push_back(num);
    }
}

void Sol(int t){
    long long cur = vec[vec.size() - 1], ans = 0;
    for(int i = vec.size() - 2 ; i >=0 ; i--){
        if(vec[i] < cur){
            ans += cur - vec[i];
        }else {
            cur = vec[i];
        }
    }
    fcout << '#' << t << ' ' << ans << '\n';
}

int main(){
    
    int testcase; fcin >> testcase;
    
    for(int t = 0 ; t < testcase ; t++){
        init();
        Sol(t+1);
    }
    
    return 0;
}
