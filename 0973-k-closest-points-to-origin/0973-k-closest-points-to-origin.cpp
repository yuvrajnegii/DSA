class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxheap;
        vector<vector<int>> ans;
        for(int i=0;i < points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int d = x*x + y*y;
            maxheap.push({d, points[i]});
            if(maxheap.size() > k) maxheap.pop();
        }
        while(!maxheap.empty()){
            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }
        return ans;    
    }
};