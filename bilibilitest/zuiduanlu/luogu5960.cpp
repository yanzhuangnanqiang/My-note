/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-03 20:41:18
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-04 11:39:14
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\chafen\luogu5960
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>

using namespace std;
#define int long long
const int N =1003;
int d[N][N];
void insert(int x1,int y1,int x2,int y2,int c){
    d[x1][y1]+=c;
    d[x2+1][y1]-=c;
    d[x1][y2]-=c;
    d[x2+1][y2+1]+=c;
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
     int x1,x2,y1,y2,c;
     cin>>x1>>x2>>y1 >>y2>>c;
    return 0;
}