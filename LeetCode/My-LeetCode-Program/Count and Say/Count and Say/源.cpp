#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string countAndSay(int  n) {
    int num=1;
    string str("1");
    string ss("1                   ");
    int temp=0;
    for (int l = 1; l <n; l++){

        int k = 0; int j = 0;
      for (;str[j]!='\0'; j++){
        if (j==str.length()-1||str[j] != str[j + 1])
        {
            ss[k++]=1+'0';
            ss[k++] = str[j]; 
            ss[k] = '\0';
        }   
        else
        {
            int count=1;
            int m=j;
            while (m<str.length()&&str[m] == str[m + 1])
            {
                        m++;
                        count++;
            }
            ss[k++]=count+'0';
            ss[k++] = str[j];  ss[k] = '\0';
            j=m;
        }
     }
      str = ss;
      temp=j;
  
   }
    string sss = ss.substr(0,temp+1);
    return sss;
}
int main(){
    
    string res = countAndSay(3);
        cout<<res<<"hh"<<endl;

    system("pause");
    return 0;
}