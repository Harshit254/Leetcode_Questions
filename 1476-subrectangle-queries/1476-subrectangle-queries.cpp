class SubrectangleQueries {
public:
      vector<vector<int>> ans;
        SubrectangleQueries(vector<vector<int>>&rectangle) { // since the matrix is passed as a parameter to the constructor
        ans= rectangle; // store it in ans vector(by this all class members can access the ans vector)
    }
    
        void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
           for(int i=row1;i<=row2;i++){
           for(int j=col1; j<=col2;j++){
              ans[i][j] = newValue; // Updating the values
           }
       }  
    }
        int getValue(int row, int col){
        return ans[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */