//
//  1206(View).cpp
//  SWExpert
//
//  Created by  JeJn on 2021/01/20.
//


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/SWExpert/input.txt");
ofstream fcout("/Users/jejn/Desktop/OnlineJudge/SWExpert/output.txt");

vector<int> vec;

void Init(){
    vec.clear();
    int size; fcin >> size;
    for(int i = 0 ; i < size ; i++){
        int n; fcin >> n;
        vec.push_back(n);
    }
}

bool Left(int idx){
    if(vec[idx-2] < vec[idx] && vec[idx-1] < vec[idx]) return true;
    return false;
}

bool Right(int idx){
    if(vec[idx+2] < vec[idx] && vec[idx+1] < vec[idx]) return true;
    return false;
}

int FindMax(int idx){
    int num = 0;
    if(vec[idx - 2] > num) num = vec[idx - 2];
    if(vec[idx - 1] > num) num = vec[idx - 1];
    if(vec[idx + 1] > num) num = vec[idx + 1];
    if(vec[idx + 2] > num) num = vec[idx + 2];
    
    return num;
}

void Sol(int t){
    int res = 0;
    for(int i = 2 ; i < vec.size() -2 ; i++){
        if(Left(i) && Right(i)){
            int max_num = FindMax(i);
            res += vec[i] - max_num;
        }
    }
    fcout << '#' << t << ' ' << res << '\n';
}

int main(){
    
    for(int t = 1 ; t <= 10 ; t++){
        Init();
        Sol(t);
    }
    
    return 0;
}
