/*

You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

*/


#include<bits/stdc++.h>
using namespace std;
 int findMaxValueOfEquation(vector<vector<int>>& arr, int k) {
     
        int i = 0, n=arr.size();
        int maxi = INT_MIN;
        priority_queue<pair<int, int>>pq;
        for(int i = 0  ; i < n; i++)
        {
            while(!pq.empty() && arr[i][0]-pq.top().second > k)
                pq.pop();
            if(!pq.empty() && arr[i][0]-pq.top().second<=k)
            {
                maxi = max(maxi, pq.top().first+arr[i][0]+arr[i][1]);
            }
            pq.push({arr[i][1]-arr[i][0],arr[i][0]});
        }
        return maxi;
}
int main()
{
    int n,p1,p2;
    cout<<"Enter number of pairs"<<endl;
    cin>>n;

    vector<vector<int>>vec;
    for(int i = 0 ; i<n;i++)
    {
        cin>>p1>>p2;
        vector<int>temp;
        temp.push_back(p1);
        temp.push_back(p2);
        vec.push_back(temp);


    }
    int k;
    cout<<"Enter value of k"<<endl;
    cin>>k;
    int maxi = findMaxValueOfEquation(vec,k);
    cout<<"Max Value of equation is: "<<maxi<<endl;
    return 0;    
}