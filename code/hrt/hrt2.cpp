
#include <iostream>
#include <string>
using namespace std;



/* bitset can be use only when the content to put in the bitset is known at compile time. */

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    int cnt = 0;
    if (S == "0") return 0;
    if (S.at(0)=='0') S.erase(0,1);
    while (S.length()>1){
        if (S.at(S.length()-1) == '1') cnt +=2;
        else cnt += 1;
        S.erase(S.length()-1, 1);
    }
    if (S == "1") cnt++;
    return cnt;
}


int main() {
    int result;
    string a = "101";
    result  = solution(a);
    cout << result << endl;
    return 0;
}

