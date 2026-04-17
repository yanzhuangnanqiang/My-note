/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-06 17:05:32
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-06 17:26:59
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\er_fen\model.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
using namespace std;

template<class T>
bool check(T t){
    return true;
}
 
void solve(){

    vector<int> v;

    
    
}

int main(){
    //这是一个模板
    int n;
    cin>> n;
    
    int x;
    cin>>x;

    int ans;
    int l=1,r=n;
    while(l<=r){
        int mid=(l+r) /2;
        if(check (mid)){
            ans=mid;
            l= mid+1;
        }
        else
            r=mid-1;  
    }
    cout<< ans <<"\n";
    return 0;
}