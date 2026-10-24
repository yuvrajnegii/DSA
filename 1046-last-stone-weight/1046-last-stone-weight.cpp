class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>mxp;
        for(int i = 0;i < stones.size();i++){
            mxp.push(stones[i]);
        }
        while(!mxp.empty() && mxp.size() != 1){
            int x = mxp.top();mxp.pop();
            int y = mxp.top();mxp.pop();
            int dif=x-y;
            mxp.push(dif);
        }
        if(mxp.empty()) return 0;
        return mxp.top();
    }
};