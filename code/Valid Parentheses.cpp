#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '[' || s[i] == '(' || s[i] == '{')
                ss.push(s[i]);
            else if(s[i] == ']') {
                if(!ss.empty()) {
                    char tmp = ss.top();
                    if(tmp != '[')
                        return 0;
                    else 
                        ss.pop(); 
                } else 
                    return 0;
            }  
            else if(s[i] == ')') {
                if(!ss.empty()) {
                    char tmp = ss.top();
                    if(tmp != '(')
                        return 0;
                    else
                        ss.pop();
                } else
                    return 0; 
            }    
            else if(s[i] == '}') {
                if(!ss.empty()) {
                    char tmp = ss.top();
                    if(tmp != '{')
                        return 0;
                    else
                        ss.pop();
                } else 
                    return 0; 
            } 
        }

        if(ss.empty())
            return 1;
        else
            return 0;
    }
};

int main() {
    string ss = ")]";
    Solution s;
    cout << s.isValid(ss) << endl;


    return 0;
}