#include <string>
#include <map>
#include <set>

using namespace std;

int solution(string s) {
    map<string, int> occurence;
    set<string> unique;

    for (int i=0; i<s.length(); i++) {
        string str = s.substr(i, 1);
        if (occurence.find(str)==occurence.cend()) {
            occurence.insert(make_pair(str,1));
        }else (occurence[str] = occurence[str]+1);
    }

    for (int i=0; i<s.length(); i++) {
        if (occurence.count(s.substr(i, 1)) == 1) return i+1;
    }
    return -1;
}

