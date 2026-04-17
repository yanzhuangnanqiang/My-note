/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-03-30 16:57:33
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-03-30 17:01:20
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\1test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<set>
#include<map>
using namespace std;



void solve(){
    int n;
    cin>>n;
    set<int> s;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.insert(x);
        mp[x]++;
    }

    for(auto i:s){
        cout<<i<<" ";
        cout<<mp[i]<<"\n";
    }

}
int main(){
    solve();
 

    return 0;
}