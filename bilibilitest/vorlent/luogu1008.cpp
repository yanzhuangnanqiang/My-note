/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-03-31 15:49:28
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-03-31 16:20:26
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\vorlent\luogu1008.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

//  本题为提交答案题，您可以写程序或手算在本机上算出答案后，直接提交答案文本，也可提交答案生成程序。

// 题目描述
// 将 1,2,…,9 共 9 个数分成 3 组，分别组成 3 个三位数，且使这 3 个三位数构成 1:2:3 的比例，试求出所有满足条件的 3 个三位数。

// 输入格式
// 无

// 输出格式
// 若干行，每行 3 个数字。按照每行第 1 个数字升序排列

//如：192 384 576
#include<iostream>
#include<set>
using namespace std;

int check(int a,int b,int c){
    set<int> s;
    while(a){
        int x=a%10;
        a/=10;
        if(x==0)
           return 0;//这是会漏写的一步操作，九个数里不能为0
        if(s.count(x)){
            return 0;
        }
        s.insert(x);
    }
    while(b){
        int x=b%10;
        b/=10;
        if(x==0){
            return 0;
        }
        if(s.count(x)){
            return 0;
        }
        s.insert(x);
    }
    while(c){
        int x=c%10;
        c/=10;
        if(x==0)
         return 0;//
        if(s.count(x)){
            return 0;
        }
        s.insert(x);
    }
    return 1;
}
int main(){

    for(int i=123;i<=329;i++){//通过逻辑关系剪枝
        int b=2*i,c=3*i;
        if(b>1000||c>1000)//剪枝
           break;
        if(check(i,b,c))
          cout<<i<<" "<<b<<" "<<c<<"\n";
    }
    return 0;
}