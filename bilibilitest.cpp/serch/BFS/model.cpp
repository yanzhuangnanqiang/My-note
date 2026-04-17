/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-09 20:52:32
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-09 21:30:59
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\serch\BFS\model.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>

using namespace std;
const int N= 1004;
int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
int grid[N][N];
bool vis[N][N];
int dist[N][N];
int n,m;

struct point{
    int x,y;
    int step;
};

void bfs(){ // 无参数， 但需要队列
    queue<point> q;
    q.push({1,1,0});
   
    //接下来对队列里的元素 进行操作
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        int x=tmp.x, y=tmp.y, step = tmp.step;
        dist[x][y]=step;
        vis[x][y]= true;
        for(int i=0;i<4;i++){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx>=1 && nx<=n && ny>= 0 && ny <=m &&
             grid[nx][ny]==0 && !vis[nx][ny]){
                q.push({nx,ny,step+1});
            }
        }
    }
    
}

int main(){
    cin>>n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            cin>>grid[i][j];
        }
    }
    bfs();
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<< dist[i][j]<<" ";
        }
        cout<< "\n";
    }
    return 0;
}