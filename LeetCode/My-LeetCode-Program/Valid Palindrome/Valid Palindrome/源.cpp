#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
//�ж�һ���ַ�������������Ƿ��ǻ���
bool isPalindrome(string s){
    for (int i = 0,j=s.size()-1; i < s.size()&&j>=0; ){
        if (!isalpha(s[i])&&!isdigit(s[i])) {
            i++;continue;
        }if (!isalpha(s[j]) && !isdigit(s[j])){
            j--;
            continue;
        }
        if (toupper(s[i])!=toupper(s[j]))
           return false;
        else
        {
            i++;j--;
        }
    }
    return true;

}

int main(){
    string s = "a man,a plan,a canal:Panama";
    bool flag = isPalindrome(s);
    cout<<flag<<endl;



    system("pause");
    return 0;
}