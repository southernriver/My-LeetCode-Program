#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
void rotate(vector<vector<int>>  &matrix){
    size_t len = matrix.size();
    //1.�Խ��߷�ת
    for (int i = 0; i < len; i++){
        for (int j = 0; j <len-i; j++){
            swap(matrix[i][j],matrix[len-j-1][len-i-1]);
        }
    }

    //2.ˮƽ���߷�ת
    for (int i = 0; i < len / 2; i++){
        for (int j = 0; j<len; j++){
            swap(matrix[i][j],matrix[len-i-1][j]);
        }
    }

}
int main(){
    vector<vector<int>>   matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++){
        for (int j = 0; j <matrix.size(); j++){
            cout << matrix[i][j] << "\t";
        }
        cout<<endl;
    }


    system("pause");
    return 0;
}