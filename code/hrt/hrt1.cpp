#include <set>
#include <iostream>
#include <vector>
using namespace std;

// Remember to compile with C++11!   g++ -std=c++11 hrt1.cpp -o hrt1

int solution(vector<int> &X, vector<int> &Y) {
    // write your code in C++14 (g++ 6.2.0)
    int dis = 0;
    int first, second;
    std::set<int> occur;
    for (int i=0; i< (signed) X.size(); i++) {
        occur.insert(X[i]);
    }


    if (occur.size()==0) return 0;
    first = *(occur.begin());
    for (std::set<int>::iterator it=(occur.begin()++); it != occur.end(); it++) {
        cout << *it << endl;
        second = *it;
        if (dis==0) dis = second-first;
        else {
            if (dis<(second-first)) dis = second - first;
        }
        first = second;
    }
    return dis;
}


int main(){
    vector<int> X = {1, 8, 7, 3, 4, 1, 8};
    vector<int> Y = {1, 8, 7, 3, 4, 1, 8};
    int result = solution(X, Y);
    cout << result << endl;
    return 0;
}


/**
 * 
 * submission:
 * int solution(vector<int> &X, vector<int> &Y) {
    // write your code in C++14 (g++ 6.2.0)
    int dis = 0;
    int first, second;
    std::set<int> occur;
    for (int i=0; i< (signed) X.size(); i++) {
        occur.insert(X[i]);
    }
    if (occur.size()==0) return 0;
    first = *(occur.begin());
    for (std::set<int>::iterator it=(occur.begin()++); it != occur.end(); ++it) {
        second = *it;
        if (dis==0) dis = second-first;
        else {
            if (dis<(second-first)) dis = second - first;
        }
        first = second;
    }
    return dis;
}
*/