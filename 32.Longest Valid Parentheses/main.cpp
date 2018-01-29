#include <iostream>
#include <string>
#include <vector>

#include <string.h>
using namespace std;

//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


class Solution {
public:
    const char LEFT='(';
    const char RIGHT=')';
    int longestValidParentheses(string s) {
        int res_max=0;
        if(s.empty()){
            return res_max;
        }
        vector<int> temp;
        temp.push_back(-1);
        int i=0;
        int num_temp=0;
        for(;i<s.size();i++){
            if(LEFT==s[i]){
                temp.push_back(i);
            }else{
                temp.pop_back();

                if(0==temp.size()){
                    temp.push_back(i);
                }else{
                    num_temp=temp.back();
                    //temp.pop_back();
                    if(i-num_temp>res_max)
                        res_max=i-num_temp;
                }
            }
        }
        return res_max;
    }

};


int main()
{
    Solution sol;
    string s="()()";
    int res=sol.longestValidParentheses(s);
    cout<<res<<endl;
    return 0;
}
