//
//  2007(패턴마다의길이).cpp
//  SWExpert
//
//  Created by  JeJn on 2021/01/19.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/SWExpert/input.txt");
ofstream fcout("/Users/jejn/Desktop/SWExpert/output.txt");


int main() {
    
    int testcase = 0; fcin >> testcase;
    
    for(int t = 1; t <= testcase ; t++){
        string str = ""; fcin >> str;
        int j = 0;
        for (int i = 1; i < str.size(); i++) {
            if(str[i] == str[j]){
                j++;
            }else {
                j=0;
            }
        }
        cout << '#' << t << ' ' << str.size() - j << '\n';
    }
    return 0;
}
