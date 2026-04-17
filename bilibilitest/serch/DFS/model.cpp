/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-09 08:34:51
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-09 16:42:09
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\serch\DFS\model.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<bits/stdc++.h>
using namespace std;
const int  N=1e5;
bool visited[N];
bool condition = false; //某种条件

int all_possble_next_steps[N];
int a[N];
int n,target;
vector<int> path;
 //模版:

// bool is_invalid(int x){
//     if(condition) 
//        return false;
//     return true;
// }

// template<class T>
// void dfs(int u,T t)//  这个 t 不单 指向一个参数
// {
//     vector<int>  path;
//     //递归终止条件（必须有！）
//     if(condition)
//     {
//         //记录某种答案/返回
//         return ;
//     }
     
//     // 遍历所有可能的 “下一步” 选择、
//     for(int v:all_possble_next_steps){
//         // a、 剪枝，如果这个选择不合法，直接跳过
//         if(is_invalid(v) || visited[v]) continue;
           
//         // b、 做出选择 & 保护现场
//         visited[v] =true;
//         path.push_back(v);

//         // c、 进入下一层递归
//         dfs(v,t); // 这里的 t 不也单指一个参数

//         // d、 撤销选择 & 恢复现场 （回溯 、DFS 的灵魂）
//         path.pop_back();
//         visited[v] = false;
//     }
// }

void dfs(int depth ,int current_sum)
{
    // 剪枝 ，如果当前和已经超过目标。 后面的数都是正常的， 不可能再等于 target 
    if(current_sum > target)  return;

    // 递归终止条件 ，所有数字都已经考虑完了
    if(depth ==n){
        if(current_sum == target){
        for(int x: path ) cout<< x <<" ";
         cout<<"\n";
        }
        return;
    }

    //选择 1： 选第 depth 个数
    path.push_back(a[depth]);
    dfs(depth+1, current_sum + a[depth]);
    path.pop_back(); // 回溯 ，撤销选择

    //  选择 2；不选 第 depth 个数
    dfs(depth +1 , current_sum);
    
}

int main(){
    cin>> n>>target;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    dfs(0,0);
    return 0;
}