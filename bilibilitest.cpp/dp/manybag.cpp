/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-10 20:54:31
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-10 21:22:29
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\dp\manybag.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>

using namespace std;

int pos;

int main(){

    int n,m;
    cin>> m>>n;
    
    vector<int> w(m+1),v(m+1);
    vector<int> dp(m+1);

    for(int i=1; i<= n; i++){
        int v1, w1, s;
        cin>>w1>> v1 >>s;
        int k =1;
        while( k<= s){
            v[++pos] = v1*k;
            w[pos] =w1*k;
            s -= k;
            k *=2;   
        }
        
        if(s){
            v[++pos] = v1 * s;
            w[pos] = w1 * s;
        }
    }

    for(int i=1 ; i<=pos; i++){
        cout<< w[i] <<" "<< v[i] <<"\n";
    }

    for(int i=1; i<=pos;i++){
        for(int j=m;j>=w[i];j--){
            dp[j]= max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    for(int i=0; i<=m;i++){
        cout<< dp[i]<<" ";
    }
    cout<<"\n";
    
    cout<< dp[m];
    return 0;
}