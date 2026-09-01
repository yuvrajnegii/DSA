class Solution { 
public: 
    int minimumDeletions(vector<int>& nums) { 
        int n = nums.size(); 
 
        int minf = nums[0], maxf = nums[0]; 
        int mindex = 0, maxdex = 0; 
 
        for(int i = 1; i < n; i++){ 
            if(minf > nums[i]){ 
                minf = nums[i]; 
                mindex = i; 
            } 
 
            if(maxf < nums[i]){ 
                maxf = nums[i]; 
                maxdex = i; 
            } 
        } 

        // Remove both elements by deleting only from the front
        int front = max(mindex, maxdex) + 1; 

        // Remove both elements by deleting only from the back
        int back = n - min(mindex, maxdex); 

        // Remove one element from the front and the other from the back
        int both = min(mindex, maxdex) + 1 
                 + n - max(mindex, maxdex); 
 
        return min(front, min(back, both)); 
    } 
};

