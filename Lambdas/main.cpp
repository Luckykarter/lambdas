//
//  main.cpp
//  Lambdas
//
//  Created by Egor Wexler on 02/06/2020.
//  Copyright © 2020 Egor Wexler. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
void printV(vector<T>& v) {
    for (T t: v) cout << t << " ";
    cout << endl;
}
auto tr = [](int initial, int addBy) {
    auto total = initial;
    return [total, addBy]() mutable {
        total += addBy;
        return total;};
};

struct IncGenerator {
    int current_;
    int inc_;
    IncGenerator (int start, int inc) {
        current_ = start;
        inc_ = inc;
    }
    int operator() () { return current_+=inc_; }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> v1(30, 0);
    //fill(v1.begin(), v1.end(), 0);
    
    printV(v1);
    
    auto test = tr(10, 5);
    
    cout << test() << endl;
    cout << test() << endl;
    cout << test() << endl;

    
    IncGenerator a(0, 10);
    
    generate(v1.begin(), v1.end(), a);
    
    printV(v1);
    
}
