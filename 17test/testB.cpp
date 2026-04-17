/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-13 11:34:18
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-17 10:14:30
 * @FilePath: \languageFolder\c++test\17test\testB.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>

using namespace std;
#define ll long long

const ll N =1e6;
const ll ENF = -(1LL <<62);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<ll> a(n+1),S(n+1,0);

    for(int i=1;i<=n;i++){
        cin>> a[i];
        //前缀和
        S[i] = S[i-1]+a[i]; 
    }
    
    //dp1[t] : 1...t 只作为 1段的最大值 = abs(S[t-1]) 
    //dp2[t]: 1...t 切成 2 段的最大值 
    //dp[t]: 1...t 切成 3 段的最大值
  
    vector<ll> dp1(n+1,ENF),dp2(n+1,ENF),dp3(n+1,ENF);

    //四段非空 ； 1< j < k < n
    //所以 dp1 的切点 i 至少得给 后面留 3 个元素  => i<=n-3
    for(int i=1;i<= n-3 ;i++){
        dp1[i] = llabs(S[i]);  // n 个前缀和的绝对值
    }

    //核心逻辑 :一个函数 => 从 dpPrev 转移到 dpNext
    // dpNext[t] = max(dpPrev[p] - S[p]), bestPlus = max(dePrev[p] +S[p])

    auto buildNext =[&](const vector<ll> &dpPrev,  vector<ll> &dpNext, // C语言的 lmbda 表达式
                        int tl,int tr, int pl,int pr){
        ll bestMinus =ENF; // max(dpPrev[p] - S[p])
        ll bestPlus =ENF; // max(dpPrev[p] + S[p])

        int p=pl; //指针 ；随着 t 增大， 把合法的 p 逐个加入 best 
        for(int i=tl;i<= tr;i++){
            while( p<= pr && p<= i-1){
                if(dpPrev[p] != ENF){
                bestMinus =max(bestMinus, dpPrev[p] -S[p]);
                bestPlus= max(bestPlus ,dpPrev[p] +S[p]);
                }
                p++;
            }
            //如果 best 还没更新 ，说明没有合法 p ，则 doNext[t] 仍然不可达
            if(bestMinus ==ENF && bestPlus ==ENF ) continue;

            //两种情况最大：
            //dpPrev[p] + abs(S[i] -S[p])
            // = max(S[i] +dpPrev[p]-S[p],-S[i] +dpPrev[p] +S[p] )
            ll cand1 =(bestMinus ==ENF ?ENF :S[i]+bestMinus);
            ll cand2 =(bestPlus ==ENF? ENF:-S[i]+bestPlus);
            dpNext[i] =max(cand1,cand2);    
        }

    };

    
    // 计算 dp2 
    // dp2[t] 的 t 至少 是 2(两端都为 非空)
    // 还要给后面的 留两段 (k 和最后一段), 所以 t<= n-2
    // p= i 的范围 是 [1... n-3]
    buildNext(dp1,dp2,2,n-2,1,n-3);
    
    //计算 dp3:
    // t 至少是 3 （3 段都非空） ，且 要留最后一段 ，所以 ，t <= n-1;
    buildNext(dp2,dp3,3,n-1,2,n-2);
    
    ll ans = ENF;
    for(int k=3;k <= n-1;k++){
        if(dp3[k]==ENF) continue;
        ll score =dp3[k] + llabs(S[n] - S[k]);
        ans =max(ans, score);
    }
    cout<< ans <<"\n";
    return 0;
}