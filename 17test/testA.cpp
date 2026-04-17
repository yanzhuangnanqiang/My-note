/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-13 11:08:42
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-16 09:15:36
 * @FilePath: \languageFolder\c++test\17test\testA.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 洛谷 p16229
 
#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const ll INF =(1LL<<62);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    ll x;
    cin>> n>> m >> x;

    vector<ll> A(m+1) , B(m+1);
    for(int i=1;i<=m;i++){
        cin>> A[i] >> B[i];
    }
    

    //C [L]  = 一批 L 单 时 ，选择最优车辆的 最小耗时
    vector<ll> c(n+1,INF);
    for(int L =1; L<=n;L++){
        for(int i=1; i<= m; i++){
            ll take =1LL  * L * A[i];
            ll pairs =1LL * L * (L-1) /2;
            ll sortt= pairs *B[i];
            c[L] = min(c[L],take +sortt);
        }
    }

    // dp[i] = 送完 前 i 单 的最短时间
     vector<ll> dp(n+1, INF);
     dp[0]=0;
     for(int i=1;i<= n; i++){
        // 枚举 最后一批长度 k （最后一批送 k 单）
         for( int k=1; k <= i; k++){
             ll cost =dp[i-k] +c[k];
             if(i-k > 0) cost += x; // 如果不是 第一批 ，才需要 折返 x
              dp[i] =min(dp[i], cost);
         }
     }

    cout<< dp[n] <<"\n";
     
    return 0;
}