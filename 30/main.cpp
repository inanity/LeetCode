#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>


using namespace std;


//You are given a string, s, and a list of words, words, that are all of the same length.
//Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once
//and without any intervening characters.

//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]

//You should return the indices: [0,9].
//(order does not matter).


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;

        map<string,int> wordsNum;
        for(int i=0; i<words.size(); i++){
            map<string,int>::const_iterator iter = wordsNum.find(words[i]);
            if(iter == wordsNum.end()){
                wordsNum[words[i]]=1;
            }else{
                wordsNum[words[i]]++;
            }
        }

        vector<string> unique_words;
        vector<int> num_words;
        for(map<string,int>::const_iterator iter=wordsNum.begin();iter!=wordsNum.end();iter++){
            unique_words.push_back(iter->first);
            num_words.push_back(iter->second);
        }

//        for(int i=0;i<unique_words.size();i++){
//            cout<<unique_words[i]<<":"<<num_words[i]<<endl;
//        }

        vector<int> comp_s(s.size(),-1);
        char* index;
        char* word_char;
        bool flag;
        for(int i=0;i<unique_words.size();i++){
            index=&(s[0]);
            word_char=&(unique_words[i][0]);
            flag=false;
            while(1){
                index=strstr(index,word_char);
                if(nullptr == index){
                    if(!flag){
                        return vector<int>();
                    }
                    break;
                }
                else{
                    flag=true;
                    comp_s[index-&(s[0])]=i;
                    index++;
                }
            }
        }

//        for(int i=0;i<comp_s.size();i++)
//           cout<<comp_s[i]<<" ";
//        cout<<endl;


        int compSize=comp_s.size();
        int words_Num=words.size();
        int words_Len=words[0].size();
        vector<int> num_words_temp;
        for(int i=0;i< compSize - words_Num* words_Len +1; i++){
            if(-1==comp_s[i]){
                continue;
            }
            //cout<<i<<endl;
            num_words_temp=num_words;
            int j=i;
            for(;j< i+ words_Num* words_Len; j+=words_Len){
                if(-1==comp_s[j]){
                    break;
                }else{
                    if(0 < num_words_temp[comp_s[j]]){
                        num_words_temp[comp_s[j]]--;
                    }else{
                        break;
                    }
                }
            }
            if(j == i+ words_Num* words_Len){
                res.push_back(i);
            }
        }


        return res;
    }
};


int main()
{
    Solution sol;
    string s="wordgoodgoodgoodbestword";
    vector<string> words={"word","good","best","good"};
    vector<int> res=sol.findSubstring(s,words);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    return 0;
}
