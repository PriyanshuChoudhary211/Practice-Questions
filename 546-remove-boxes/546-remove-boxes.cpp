class Solution {
public:
  
int dp[100][100][100];

int removeBoxes(vector<int>& boxes) {
   
    //Initialize all dp elements with zero using memset
    
    memset(dp,0,sizeof(dp));
    
    int n=boxes.size();
    
    //Call our helper function named helper....
    
    return helper(boxes,0,n-1,0);
}

int helper(vector<int>&boxes,int i,int j,int k){
    
    /* Here [i,j] describes the closed interval inside which we will make operations i.e finding some consecutive boxes of same colour and k is that count of same coloured consecutive boxes on the left side of boxes[i]
    
    [1,3,2,2,2,3,4,3,1]  from here lets assume [2,2,2] consecutive sequence of count=3 i.e between index [2,4] value of k is 3 so we got (3*3)=9 points at max*/
    
   //If it goes out of the range return simply zero.
    
    if(i>j){
        return 0;
    }
    
    //If for some values of i,j,k answer already be calculated then simply return it from the dp table.
    
    
    if(dp[i][j][k]!=0){
        return dp[i][j][k];
    }
    
    //Here k is the number of adjacent same coloured boxes on the left of boxes[i].
    
   /* e.g         [5 5 5 3 5 5]
      index:-     [0 1 2 3 4 5]
      now k value in closed interval [2,5] is 2 because boxes[0]==boxes[1]==boxes[2] and there is atmost two boxes on the left side of boxes[2].*/
        
        
    
    //Now we first start with boxes[i] and in the interval[i+1,j] to find consecutive same coloured boxes.
    
    int res=(k+1)*(k+1)+helper(boxes,i+1,j,0);
    
    for(int range=i+1;range<=j;range++){
        
        // if boxes[i]==boxes[range], we can thus eliminate interval [i+1, range-1]
        
        //e.g [6 6 6 6 1 2 6] we should delete index of interval[4,5] to get higher score .
        
        // to make boxes[i] and boxes[range] adjacent to have a higher score.
        
  
        if(boxes[i]==boxes[range]){
            
            //If somehow boxes[i] and boxes[range] are of same colour then there will be k+1 boxes (k boxes given as argument and +1 for boxes[i]) on the left side of boxes[range]
            res=max(res,helper(boxes,i+1,range-1,0)+helper(boxes,range,j,k+1));
            
        }
        
    }
    
   
    return dp[i][j][k]=res;
}
};