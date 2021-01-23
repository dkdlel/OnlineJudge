//
//  1436(영화감독 숌).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/22.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include<iostream>
#include<string>
using namespace std;

int main() {
    int n, cnt = 1;
    cin >> n;

    for(int i = 666; ;i++){
        string tmp = to_string(i);
        if (tmp.find("666") != string::npos) {
            if (cnt == n) {
                cout << tmp << "\n";
                break;
            }
            else cnt++;
        }
    }
    return 0;
}
