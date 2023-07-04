/*排列式

7254是一个不寻常的数，因为它可以表示为7254 = 39 x 186，这个式子中1~9每个数字正好出现一次
　　输出所有这样的不同的式子（乘数交换被认为是相同的式子）
　　结果小的先输出；结果相同的，乘数较小的先输出。 
输出：
4396 = 28 x 157
5346 = 18 x 297
5346 = 27 x 198
5796 = 12 x 483
5796 = 42 x 138
6952 = 4 x 1738
7254 = 39 x 186
7632 = 48 x 159
7852 = 4 x 1963 */
#include<iostream>
#include<algorithm>
using namespace std;

//判断情况是否成立，即因子相乘是否==预设乘积(res),符合即输出
void res_lr(int preres,int l,int r){
    if(preres == l * r){
        cout<<preres<<" = "<<l<<" x "<<r<<endl;
    }
}

void f1(int a[]){
    //乘积数
    int res;

    //l1 - 一位数因子 丨 r1 - 四位数因子
    int l1,r1;

    //l2 - 两位数因子 丨 r2 - 三位数因子
    int l2,r2;

    //循环不断做枚举即可，使用do-while不用担心会漏掉第一个顺序
    do{
        //4位数=1位数 x 4位数的情况
        res = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        l1 = a[4];
        r1 = a[5] * 1000 + a[6] * 100 + a[7] * 10 + a[8];
        res_lr(res,l1,r1);
        //4位数=2位数 x 3位数的情况
        res = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
        l2 = a[4]*10+a[5];
        r2 = a[6] * 100 + a[7] * 10 + a[8];
        res_lr(res,l2,r2);

    }while(next_permutation(a,a+9));
}

int main(){
    //定义从1到9的数组，使用next_permutation(a,a+9)做全排列
    int t[9] = {1,2,3,4,5,6,7,8,9};
    f1(t);
    return 0;
}

