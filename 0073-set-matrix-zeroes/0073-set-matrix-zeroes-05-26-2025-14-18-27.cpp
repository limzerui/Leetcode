class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // have a storage of some sort of row and clumn
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        //check if first row and col should be zero
        bool first_row = check(matrix[0], col_num);
        vector<int> col_arr;
        for(int i = 0; i < row_num; i++){
            col_arr.push_back(matrix[i][0]);
        }
        bool first_col = check(col_arr, row_num);

        for(int i = 0; i< row_num; i++){
            for(int j = 0; j<col_num; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i<row_num; i++){
            for(int j = 1; j<col_num; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(first_row){
            for(int j = 0; j<col_num; j++){
                matrix[0][j] = 0;
            }
        }
        if(first_col){
            for(int i = 0; i<row_num; i++){
                matrix[i][0] = 0;
            }
        }
        
    }
    
    bool check(vector<int>& matrix, int size){
        for(int i = 0; i< size; i++){
            if(matrix[i] == 0){
                return true;
            }
        }
        return false;
    }
};