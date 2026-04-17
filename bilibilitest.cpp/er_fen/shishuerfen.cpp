/*
 * @Author: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @Date: 2026-04-07 15:07:22
 * @LastEditors: Hidden Goose yanzhuangqiang@email.ncu.edu.cn
 * @LastEditTime: 2026-04-07 15:49:36
 * @FilePath: \languageFolder\c++test\bilibilitest.cpp\er_fen\shishuerfen.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<iostream>

using namespace std;
int main(){
    double l=0,r=10000.0;

    auto check =[&](double x)->bool
    {
          
    };

    //可以预见的误差
    while(r-l>1e-6 )
    {
        double mid =(l + r) / 2.0;
        if(check(mid)) r = mid;
        else l= mid;
    }

    //如果不放心,二分 100 次 足以达到小数点后 30 位
    for(int i=0 ;i<100;i++)
    {
        double mid = (l+r) /2;
        if(check(mid)) r =mid;
        else l = mid;
    }

    printf("%.4f\n",l);
    
    return 0;
}