/*
Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.

Return True if the array is good otherwise return False.
*/
#include<bits/stdc++.h>
using namespace std;

 bool isGoodArray(vector<int>& nums) {
    int gcd=nums[0];
    int n = nums.size();
for(int i=0;i<nums.size();i++){
   gcd=__gcd(gcd,nums[i]);
     if(gcd!=1 && i==n-1){
         return false;
    } 

return true;
}
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0 ; i<n ; i++)
       cin>>arr[i];
   cout<<isGoodArray(arr);

}