#include <iostream>
#include <vector>

using namespace std;


//Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
//You are given a target value to search. If found in the array return its index, otherwise return -1.
//
//You may assume no duplicate exists in the array.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }

        int low=0;
        int high=nums.size()-1;
        int pivot =pivot_seek(nums);
        int mid,real_mid;
        while(low <= high){
            mid=(low+high)/2;
            real_mid=(mid + pivot)% nums.size();
            if(nums[real_mid] == target){
                return real_mid;
            }else if(nums[real_mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return -1;
    }

    int pivot_seek(vector<int>& nums){
        int low=0;
        int high=nums.size()-1;
        int mid;
        while(low < high){
            mid=(low+high)/2;
            if(nums[mid]>nums[high]){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        return low;
    }
};


int main()
{
    Solution sol;
    vector<int> nums={1};
    int target=1;
    cout<<sol.search(nums,target);
    return 0;
}
