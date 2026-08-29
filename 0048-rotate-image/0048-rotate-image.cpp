class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        //transpose
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        //reverse
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(matrix[j][i],matrix[j][n-1-i]);
            }
        }
        
    }
};