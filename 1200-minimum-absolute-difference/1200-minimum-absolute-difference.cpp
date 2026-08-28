class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min=INT_MAX,start=0;
        vector<vector<int>>tot;
        for(int i=1;i<arr.size();i++){
            if((arr[i]-arr[start])<min){
                min=arr[i]-arr[start];
                if(tot.empty())
                    tot.push_back({arr[start],arr[i]});
                else{
                    tot.clear();
                    tot.push_back({arr[start],arr[i]});
                }
            }
            else if((arr[i]-arr[start]) == min)
                tot.push_back({arr[start],arr[i]});
             
            start=i;
        }
        return tot;
    }
};