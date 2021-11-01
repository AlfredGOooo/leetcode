#include <map>
#include <string>	
#include <vector>		
using namespace std;		

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int shorter, longer;
        vector<int> factors;
        string shortStr, longStr;
        
        shortStr = str1.length()>=str2.length() ? str2:str1;
        longStr = str1.length()>=str2.length() ? str1:str2;
        shorter = shortStr.length();
        longer = longStr.length();
        for (int i=shorter; i>0; i--) {if ((shorter%i==0) && (longer%i==0))  factors.push_back(i);}

        string target="";
        for (int i=0; i<factors.size(); i++)  {
            // detect the factor is also factor of longer string
            string sub = "";
            target = shortStr.substr(0,factors[i]);
            for (int j=0; j<shorter/factors[i]; j++) sub += target;
            if (sub == shortStr) {   // look for the 
                sub.clear();
                for (int k=0; k<longer/factors[i]; k++) sub += target;
                if (sub == longStr) break;
                else target = "";
            }else target = "";
        }
        return target;
    }
};


/**
 * Reveiw: 
 * 1. remember to use swap to deal with the swap string problem!
 * 2. Perhaps it is good to not use the stl library.
 * 3. You have to be really clear on what you are going to return!
 * 
 */

/* other people's solution  */
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length()<str2.length()){
            swap(str1, str2);
        }
        int i = str1.length();
        int j = str2.length();
        while(j>0){
            if(i%j==0 && str2.length()%j==0){
                string gcd = str2.substr(0,j);
                string tmp1="";
                for(int k=0;k<(i/j);k++){
                    tmp1+=gcd;
                }
                string tmp2="";
                for(int k=0;k<(str2.length()/j);k++){
                    tmp2+=gcd;
                }
                if(str1==tmp1 && str2==tmp2){
                    return gcd;
                }
            }
            j--;
        }
        return "";
    }
};