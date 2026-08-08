class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k=piles.size();
        int  n=*max_element(piles.begin(),piles.end());
        int low=1,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hr=0;
            for(int i=0;i<k;i++){
                hr += ((long long)piles[i] + mid-1)/mid;
            }
            if(hr<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }     
        }
        return low;
    }
};