class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>umap;
        vector<int>ans;
        for(auto x: nums){
            umap[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:umap){
            pq.push(make_pair(x.second,x.first));
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()){
            pair<int,int> temp=pq.top();
            pq.pop();
            ans.push_back(temp.second);
        }
        return ans;

    }
};