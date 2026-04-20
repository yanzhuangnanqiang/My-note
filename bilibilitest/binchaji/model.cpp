/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-08 19:25:09
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-19 09:48:57
 * @FilePath: \languageFolder\c++test\bilibilitest\binchaji\model.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-08 19:25:09
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-09 08:17:03
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\binchaji\model.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//给定一个包含 n 个点（编号为 1 ~ n）的无向图，初始的图中没有边。

// 现在要进行 m 个操作，操作共有三种：

// C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
// Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
// Q2 a，询问点 a 所在连通块中点的数量；
// 输出格式

// 对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。
// 对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量。
// 每个结果占一行。

// 一个最典型的样例（输入 / 输出）
// 输入：
        // 5 9
        // Q2 1
        // Q1 1 2
        // C 1 2
        // Q1 1 2
        // C 3 4
        // Q2 3
        // Q1 2 3
        // C 2 3
        // Q2 4
        // 输出

//输出：
        // 1
        // No
        // Yes
        // 2
        // No
        // 4

#include<iostream>
 
using namespace std;
const int  N=1e5;
int fa[N];
//例题解释：
// //1、初始化（必须在执行任何操作前调用）
// void init(int n){
//     for(int i=1;i<=n;i++){
//        fa[i]=i;           
//     }
// }

// //2、查找与路径压缩（核心代码 ， 背诵级别）
// int find(int x){
//     if(fa[x]==x) return x;//找到根节点
     
//     //递归查找根节点，并直接将当前节点挂在根节点下（路径压缩）

//     return fa[x] =find(x);
// }

// //3、合并 
// void merge(int x, int y){
//     int rootX =find (x);
//     int rootY =find (y);

//     if(rootX!=rootY)
//       fa[rootX] = rootY;// 把 x 的根节点 让 y 的根节点作为老大
// }


 //-----------------------进阶----------------------------

int sz[N];//新增，用来 记忆 联通内点的数量

int a,b,ra,rb;
void init(int n){
    for(int i=1;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
    }
}
    
int Find(int x){
    if(fa[x]!= x) 
      return Find(fa[x]);
    
    return x;
}

//压缩路径
void merge(int x,int y){
     fa[x]=y;
     sz[y]+=sz[x];
}


int main(){ 
    int n,k;
    cin>>n>>k;
    
    init(n);

    while(k--)
    {
        string s;
        cin>>s;

        if(s=="C")
        {
            cin>>a>>b;
            ra=Find(a),rb=Find(b);
            if(ra!=rb)
            {
                merge(ra,rb);
            }
        }

        if(s=="Q1")
        {
            cin>>a>>b;
            ra=Find(a),rb=Find(b);
            if(ra!=rb)
            {
                cout<<"No"<<"\n";
            }
            else
                cout<<"Yes"<<"\n";
        }

        if(s=="Q2")
        {
            cin>>a;
            int ra=Find(a);
            cout<<sz[ra]<<"\n";
        }
    }
    return 0;
}