#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>  plusOne(vector<int>  &digits){

    //1.如果给定的数据是全为9的，最高位必须补充一位0
    int i=0;
    for (; i<digits.size(); i++){
        if (digits[i]!=9)
                    break;
    }
    if (i==digits.size()){
       digits.resize(digits.size()+1);
       for (int i = digits.size() - 2; i >= 0; i--){
           digits[i + 1] = digits[i];
        }
       digits[0]=0;
    }

    for (auto it = prev(digits.end());it>=digits.begin();it--)
    {
        int num=*it+1;
        if (num % 10 == 0){
                *it=0;
        }
        else
        {
            (*it)++;break;
        }
    }        
    return digits;
}
int main(){
    vector<int>   digits = {9,9,8,9};
    vector<int>    res = plusOne(digits);
    for (auto c:res)
        cout << c ;
    cout<<endl;

    system("pause");
    return 0;
}