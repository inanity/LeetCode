#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 ¡ú 1,3,2
//3,2,1 ¡ú 1,2,3
//1,1,5 ¡ú 1,5,1

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //next_permutation(nums.begin(),nums.end());
        if(nums.size()<2)
            return ;

        vector<int>::iterator i=nums.end();
        --i;
        while(1){
            vector<int>::iterator ii=i;
            --i;
            if(*i<*ii){
                vector<int>::iterator j=nums.end();
                while(!(*i<*--j));
                iter_swap(i,j);
                reverse(ii,nums.end());
                return ;
            }
            if(i==nums.begin()){
                reverse(nums.begin(),nums.end());
                return ;
            }
        }
    }
};



int main()
{
    Solution sol;
    vector<int> nums={3,2,1};
    sol.nextPermutation(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
