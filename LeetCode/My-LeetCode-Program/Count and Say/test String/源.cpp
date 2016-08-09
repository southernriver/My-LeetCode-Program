#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s1 = "hello world";
    string s2 = " ";
    string s3 = "good noon";
    cout << s1 << " " << s2 << " "<<s3<<endl;
    s1=s2;
    
    cout << s1 << " " << s2 << " " << s3 << endl;

    string s4 = "1 ";
    s4[0] = 'a';
    s4[1] = 'b';
    
    cout<<s4<<endl;



    system("pause");
    return 0;
}