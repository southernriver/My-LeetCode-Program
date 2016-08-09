#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    size_t row = matrix.size();
    size_t col = matrix[0].size();
    vector<int>   res = {};
    int i=0;
    int j=0;
    for (i=0; i < row; i++){
       for (j=0; j < col; j++){
            if (matrix[i][j] == 0){
                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    if (res.empty())  return ;
    int m=0;int n=0;
    for (m=0,n=1; m<res.size(); m+=2,n+=2){
        for (int k=0;k<row;k++) //所在的行清零
            if (res[n]<col)
            matrix[k][res[n]]=0;
        for (int k=0;k<col;k++) //所在的列清0
            if (res[m]<row)
            matrix[res[m]][k]=0;
    }
}
int main(){
    vector<vector<int>>  matrix = {{0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
    setZeroes(matrix);
    for (auto i : matrix){
        for (auto j:i)
            cout << j << " ";
        cout<<endl;
    }


    system("pause");
    return 0;
}