#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//�ҳ������ַ��������ͬ�ַ���
string LongestCommonPrefix(vector<string> &strs){
    if (strs.size() == 0)  return "";
    size_t len = strs.size();   //�����ַ����ĸ���
    //�����Ȱ�С�����˳������
    sort(strs.begin(),strs.end(),[](const string &a,const string &b){return a.size()<b.size();});
    int max_common_len = strs[0].length();  //���ͬ�ַ����ĳ������ֵ
    string s = strs[0];
    for (int j = 0; j<max_common_len; j++){
        int i=1;  
        for (i = 1; i < len; i++){
            if (strs[i].find((s.substr(0, max_common_len - j))) !=0)
                     break;
        }
        if (i == len){
            return s.substr(0, max_common_len - j);
        }      
    }
    return "";
}
int main(){

    vector<string>  strs = { "shae", "shahh", "shadsf", "shassdf", "shasdffdg" };
    cout << LongestCommonPrefix(strs) << endl;



    system("pause");
    return 0;
}