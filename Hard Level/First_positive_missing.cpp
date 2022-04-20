/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.
*/


#include<bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
    
        sort(nums.begin(),nums.end());
        int k=1;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]>0 && nums[i]==k)
                k++;
    
        }
        return k;
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i<n ; i++)
       cin>>arr[i];
   cout<<firstMissingPositive(arr);

}