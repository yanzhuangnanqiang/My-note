/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-06 11:58:04
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-08 17:55:24
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\window\luogu1886.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<deque>
#include<vector>
using namespace std;
const int N=1e6;
int b[2005];
int a[N],s,ans = 0;
int  main(){
    
    int n,k;
    cin>>n>>k;
    
    deque<int> q;
    vector<int> min_v,max_v;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.front()<i-k+1){
            q.pop_front();
        }

        while(!q.empty()&& a[q.back()]>=a[i]){
            q.pop_back();
        }

        q.push_back(i);

        if(i-k+1>0){
            min_v.push_back(a[q.front()]);
        }
    }

    q.clear();
    
    for(int i=1;i<=n;i++){
        while(!q.empty()&&q.front()<i-k+1){
            q.pop_front();
        }

        while(!q.empty()&& a[q.back()]<=a[i]){
            q.pop_back();
        }

        q.push_back(i);

        if(i-k+1>0){
            max_v.push_back(a[q.front()]);
        }
        
    }

    for (int x : min_v) cout << x << " ";
    cout << endl;
    // 输出最大值
    for (int x : max_v) cout << x << " ";
    cout << endl;


    return 0;
}