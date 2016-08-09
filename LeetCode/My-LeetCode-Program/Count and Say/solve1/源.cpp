#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string get(int num){
    string s = "1";
    string result="";
    int count=1;
    if (num<1)  return "";
    for (int i = 0; s[i] != '\0'; i++){
        if (i > 0 && s[i] != '\0'){
            if (s[i] == s[i - 1]){
                count++;              
            }
            else
            {
                result += count + s[i];
            }
        }
    }
    return result;
}

//string countAndSay(int n){
//   
//}

int main(){
    cout << get(1)<<endl;



    system("pause");
    return 0;
}