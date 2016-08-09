#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
vector<int> findSubstring(string s, vector<string>& dict) {
    //���ʵĳ��ȹ̶�λ3
    size_t wordLength =dict[0].size();

    //�ܵ��Ӵ��ĳ���Ϊ3*dict.size()
    size_t catLength = wordLength * dict.size();

    vector<int> result;
    if (s.length() < catLength) return result;

    map<string, int> wordCount;
    for (auto const& word : dict) ++wordCount[word];
    

    for (auto i = begin(s); i <= prev(end(s), 6); ++i) {
        map<string, int> unused(wordCount);
       // cout<<*i<<endl;
        for (auto j = i; j != i+6; j += 3) {
            cout << *i << " " << *j << endl; cout << distance(i, j) << endl;
            auto pos = unused.find(string(j, next(j, 3)));//����λ�õĵ�����
            if (pos == unused.end() || pos->second == 0) break;
            if (--pos->second == 0) unused.erase(pos);
            
         }
        cout << "unused.size():" << unused.size()<<endl;
        //distance������������������֮��ľ���
        if (unused.size() == 0) result.push_back(distance(begin(s), i));
    }
    return result;
}
int main()
{
    string s = "barfoobarfo";
    auto i = begin(s);
    
    auto j = next(i,3);
    auto k = prev(end(s),6);
    cout<<*k<<endl;

         

    vector<string>  words = { "foo", "bar"};
    vector<int> res=findSubstring(s, words);
    for (auto c:res)
        cout << c << " ";
    cout<<endl;




    system("pause");
    return 0;
}