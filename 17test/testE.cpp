/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-14 11:33:23
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-14 15:06:34
 * @FilePath: \languageFolder\c++test\17test\testE.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ll long long 
const ll N= 100000;

ll a[N],n,c,w;
int T;
ll sum[N];

void init(){
    for(int i=1;i<=N;i++){ 
        sum[i]=sum[i-1]+i;
    }
} 


int main(){
    ios::sync_with_stdio(0);
    
    init();
    cin>> T;
    while(T--){

        cin>> n >>c >> w;
        
        
        if(w%c !=0){
           cout<< -1<<endl;
           continue;
        }
        else if(w==0){
            cout<< 0<< "\n";
            continue;
        }

        w/=c;
        ll sum_n =n *(n+1) /2;
        if(sum_n<w)
        { 
          cout<< -1<< "\n";
          continue;  
        } 

        bool flag =false;
        for(ll i=0;i<=n;i++){
            ll idx= upper_bound(sum, sum +n+1,w+ sum[i])-sum -1;
            if(w == sum[idx]- sum[i])
            {  
               flag = 1;
               break;
            }
        }

        if(flag){
            cout<< 1<< "\n";
        }else 
            cout<< 2<< "\n";
    
   }

    return 0;
}