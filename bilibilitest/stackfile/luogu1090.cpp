/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-03-30 20:18:02
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-03-30 20:54:07
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\stackfile\luogu1090.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
using namespace std;
#include<queue>
int main(){
    priority_queue<int,vector<int>,greater<int>> q;//更小的数优先（小顶堆）
    // priority_queue<int> q;
    // // 等价于
    // priority_queue<int, vector<int>, less<int>> q; //大顶堆
    int n;
    cin>>n;
    int ans;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        q.push(m);
    }
    while(q.size()>=2){
        int s=q.top();
        q.pop();
        int l=q.top();
        q.pop();
        ans+=(l+s);
        q.push(l+s);  
    }
    
    cout<<ans<<"\n";
    return 0;
}