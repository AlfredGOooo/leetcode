#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * This is the sliding window coding prob.
 * Complete the 'getMaxColors' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY prices
 *  2. INTEGER money
 */

// link: https://medium.com/@ayushsingh1315/sliding-window-maximum-leetcode-hard-2f204e417cbd

int getMaxColors(vector<int> prices, int money) {
    if ((prices.size()==0)||(money==0))  return 0;
    int window = prices.size();
    int start, sum;
    while (window>0) {
        start = 0; 
        while (start+window<=prices.size()) {   // if not the end
            if (start==0) {     // if this is the first time
                sum = 0;
                for (int i=0;i<window;i++){
                    sum+=prices[start+i];
                }
                if (sum<=money) return window;
            }
            else {
                sum -= prices[start-1];
                sum += prices[start+window-1];
                if (sum<=money) return window;
            }
            start ++;
        }
        window--;
    }
    return 0;
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string prices_count_temp;
    getline(cin, prices_count_temp);

    int prices_count = stoi(ltrim(rtrim(prices_count_temp)));

    vector<int> prices(prices_count);

    for (int i = 0; i < prices_count; i++) {
        string prices_item_temp;
        getline(cin, prices_item_temp);

        int prices_item = stoi(ltrim(rtrim(prices_item_temp)));

        prices[i] = prices_item;
    }

    string money_temp;
    getline(cin, money_temp);

    int money = stoi(ltrim(rtrim(money_temp)));

    int result = getMaxColors(prices, money);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
