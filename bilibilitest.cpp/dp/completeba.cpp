/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-10 17:42:11
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-10 18:26:22
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\dp\completeba.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>

using namespace std;
  
//这是二维状态下的 完全背包问题
// 只有一点和 01背包不同 ，它的递加是 在 本行进行
// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n,m;
//     cin>> m>> n;
//     vector<int> w(m+1),v(m+1);
//     for(int i=1;i<=n ;i++){
//         cin>>w[i]>>v[i];
//     }

//     vector<vector<int>> dp_(n+1 , vector<int>(m+1,0));
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=m;j++){
//             dp_[i][j] =dp_[i-1][j];
//             if(j>=w[i]){
//                 dp_[i][j]=max(dp_[i][j],dp_[i][j-w[i]]+v[i]);  
//             }
//         }
//     }
    
//     for(int i=0;i<=n;i++)
//     {
//         for(int j=0;j<=m;j++){
//           cout<< dp_[i][j]<<" ";
//         }
//         cout<<"\n"; 
//     }
//     cout<< dp_[n][m]<<"\n";
//     return 0;
// }

// 这是一维下的完全背包

int main(){

    int n,m;
    cin>> m>> n;
    
    vector<int> w(m+1),v(m+1);
    for(int i=1;i<=n;i++){
        cin>> w[i]>>v[i];
    }

    vector<int> dp(m+1);
    for(int i=1;i<=m;i++){
        for(int j=w[i];j<=m;j++){
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }


    for(int i=0;i<=m;i++)
    {
       cout<< dp[i]<<" ";
    }

    cout<<"\n";
    cout<< dp[m]<<"\n";
    return 0;
}