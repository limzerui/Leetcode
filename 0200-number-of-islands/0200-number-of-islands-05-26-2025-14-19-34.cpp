class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        //1 is land, 
        //0 is water
        //grid is a array of array of char
        if(grid.empty()) return 0;
        //point to the same parent. 
        //for every 1, if there arround it is a 1, then union then together.
        //maybe have a very very long vector?
        //vector.size twice?
        int size = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> parent(m*n, -1);
        int count = 0;
        
        for(int i = 0; i< m; i++){
            for(int j = 0; j< n ; j++){
                if(grid[i][j] == '1'){
                    int idx = i*n+j;
                    parent[idx] = idx;
                    count++;
                }
            }
        }
        vector<int> dx = {0, 1, 0,-1};
        vector<int> dy = {1, 0, -1,0};

        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]=='1'){
                    int idx = i*n+j;
                    for(int d = 0; d<4; d++){
                        int ni = i+dx[d];
                        int nj = j+dy[d];
                        if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj] == '1'){
                        int nIdx = ni*n+nj;
                        if(unionNodes(idx, nIdx, parent)){
                            count--;
                        }
                    
                    }
}
                }
            }
        }
        return count;

    }

    int find(int x, vector<int>& parent){
        if(parent[x] != x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
        
    }

    bool unionNodes(int x, int y, vector<int>& parent){
        int rootX = find(x, parent);
        int rootY = find(y, parent);
        if(rootX != rootY){
            parent[rootY] = rootX;
            return true;
        }
        return false;
    }
};