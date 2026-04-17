/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-04 14:29:01
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-04 16:31:31
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\zuiduanlu\modelFloyd.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<vector>
using namespace std;
static const long long  inf=(1LL<<60);

int main(){
    int n=4;//点数  1..n
    //dist[i][j]；i到 j的最短距离
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,inf));

    //nxt[i][j]:从 i 去 j的最短路径上， i 的 下一跳是谁（用于还原路径）
    vector<vector<int>> nxt(n+1,vector<int>(n+1,-1));
    
    //初始化；自己到自己为 0
    for(int i=1;i<=n;i++)
    {
        dist[i][i] =0;
        nxt[i][i] =i;
    }

    auto add_edge=[&](int u,int v,long long w){
        //如果有重边，保留更短的那条
        if(w<dist[u][v]){
            dist[u][v]=w;
            nxt[u][v]=v;
        }
    };
    // int x,y,z;
    // for(int i=0;i<4;i++ ){
    //    cin>>x>>y>>z;
    //    add_edge(x,y,z);
    // }

    // 加边（有向）
    add_edge(1, 2, 3);
    add_edge(1, 3, 10);
    add_edge(2, 3, 1);
    add_edge(2, 4, 2);
    add_edge(3, 4, 4);
    add_edge(4, 1, 7);

    //Folyd 核心算法
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dist[i][k]==inf) continue;
             for(int j=1;j<=n;j++){
                if(dist[k][j]==inf) continue;
                long long nd =dist[i][k] +dist[k][j];
                if(nd < dist[i][j]){
                    dist[i][j]=nd;
                    nxt[i][j] =nxt[i][k]; //i->j的第一步 = i->k 的第一步
                }
             }
        }
    }

    //输出 dist 矩阵
    cout<<"All-pairs shortest distance (INF means unreachable):\n";
    for(int i=1 ;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dist[i][j]>=inf/2) cout<<"inf ";
            else cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
   
    // 路径还原函数 : 返回 i->j 的最短节点序列
    auto get_path =[&](int i,int j)
    {
        vector<int> path;
        if(nxt[i][j]==-1) return path;//不可达
        int cur =i;
        path.push_back(cur);
        while(cur!=j){
            cur =nxt[cur][j];
            if(cur ==-1){
              path.clear();
              return path;
            }
            path.push_back(cur);
        }
        return path;
    };
    
    int s=1,t=4;
    auto path =get_path(s,t);
    cout<<"\n Example: shortest path "<<s<<" -> "<< t<<"\n";
    if(path.empty())
    {
        cout<<" unreachable\n";
    }else{
        cout<<" distance =" <<dist[s][t]<<"\n";
        cout<<" path :";
        for(int idx =0;idx<(int)path.size();idx++){
            cout<< path[idx] <<(idx + 1 == (int) path.size()?"\n":"->");
        }
    }
    return 0;
}