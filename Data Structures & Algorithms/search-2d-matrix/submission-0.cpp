class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size()-1;
        int col = matrix[0].size()-1;   

        int l = 0,r = row*(col+1) +col;
        while(l<=r){
            int m = l + (r -l)/2;
            
            int mR = m / (col+1);
            int mC = m % (col+1);

            if(matrix[mR][mC] ==target){
                return true;
            }
            else if(matrix[mR][mC] < target){
                l= m +1;
            }
            else{ 
                r= m-1;
            }

        }
        return false;
        
    }
};
