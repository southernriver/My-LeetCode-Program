#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void add(vector<int> &digits, int digit){
    int c=digit;         //carryÊÇ½øÎ»
    for (auto it = digits.rbegin(); it != digits.rend(); ++it){
        *it+=c;
        c=*it/10;
        *it%=10;
    }
    if (c>0) digits.insert(digits.begin(),1);
}
vector<int>  plusOne(vector<int>  &digits){
    add(digits,1);
    return digits;
}

int main(){
    vector<int>   digits = { 9, 9, 8,1 };
    vector<int>    res = plusOne(digits);
    for (auto c : res)
        cout << c;
    cout << endl;

    system("pause");
    return 0;
}