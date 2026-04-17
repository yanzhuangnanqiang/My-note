/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-10 13:25:48
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-10 17:38:05
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\dp\01bag.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>

using namespace std;
int v[301],w[301],dp[301][301];

// dp 数组可用 vector 数组 动态调节  vector<int>

//  二维就用 vector< vector<long long> > dp(n+1 ,vector <long long >(m+1,0))

//dp 数组在主函数外定义 ，里面元素自动 归 0
// 注意 处理边界

// 二维
// int main(){
//     int n,m;
//     cin>> n >> m;
//     for(int i=1; i<=n; i++){
//         cin>> w[i] >> v[i];
//     } 
    
//     for(int i=1;i <= n;i++)
//     {
//         for(int j=1; j< m; j++){
//       
//            dp[i][j] =dp[i-1][j]; //默认继承上一层 状态
//            if(j>=w[i])
//             dp[i][j] =max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
//         }
//     }
//     cout<< dp[n][m] << "\n";
//     return 0;
// }

// vector<int> dp_;// vector作为全局变量时， 通常先全局申明， 随后在 main 里 assign 
// 一维
int main(){
    
    int n,m;
    cin>> m >> n;
    vector<int> dp_(m+1, 0);
    for(int i=1; i<=n; i++){
        cin>> w[i] >> v[i];
    } 
    
    for(int i=1;i <= n;i++)
    {
        for(int j=m; j>=w[i]; j--){

            dp_[j] =max(dp_[j],dp_[j-w[i]]+v[i]);

        }
    }

    cout<< dp_[m] << "\n";
    return 0;
}