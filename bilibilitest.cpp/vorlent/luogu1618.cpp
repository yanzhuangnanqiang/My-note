/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-03-31 16:26:34
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-03-31 17:02:39
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\vorlent\luogu1618.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>
#include<set>
using namespace std;

int check(int a,int b,int c){
    set<int> s;
    while(a){
        int x=a%10;
        a/=10;
        if(x==0)
           return 0;
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
         return 0;
        if(s.count(x)){
            return 0;
        }
        s.insert(x);
    }
    return 1;
}
int main(){
    int x,y,z;
    bool f=0;
    cin>>x>>y>>z;
    if(x==0){
         cout<<"No!!!"<<"\n";//注意输出的时候尽量粘贴题目中的要求
      return 0;
    }
     
    for(int i=123;i<=987;i++){
        if(i%x!=0)
           continue;
        int k=i/x;
        int b=k*y,c=k*z;
        if(b>1000||c>1000)
           break;
        if(check(i,b,c)){
            cout<<i<<" "<<b<<" "<<c<<"\n";
            f=1;  
        } 
     }  
     if(f==0)
     cout<<"No!!!"<<"\n";
    return 0;
}