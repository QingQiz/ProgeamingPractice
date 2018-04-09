/*Problem A: 村落中的长者
 *时间限制：1000MS 内存限制：65536KB
 *题意描述：
 *在一个村落里，有n个人，每个人的资历都互不相同，由一个非负整数表示，
 *越大表示这个人资历越高。现在，由于某些原因，村落中的人们组成了小团体，
 *小团体的人是村落中所有人的一个非空子集（易知共有个可能的非空子集）。
 *在某个确定的小团体中，资历最高的人称为“长者”，长者的资历值称为这个小团体的E值。
 *试问，所有可能的小团体的E值之和是多少？
 *
 *输入：
 *首先输入一个正整数T，表示测试数据的组数。接下来每组测试数据，第一行输入一个正整数n，表示村落中人的个数。第二行输入n个非负整数，表示这n个人的资历值。
 *
 *输出：
 *对于每组测试数据，输出一行“Case #x: answer”，其中x为测试数据的编号，answer为相应的答案。
 *
 *数据范围：
 *
 *
 *
 *
 *样例输入：
 *2
 *1
 *66
 *3
 *1 2 3
 *
 *样例输出：
 *Case #1: 66
 *Case #2: 17
 */
#include <iostream>
#include <algorithm>

int findsum(int[],int);
void display(int[],int);
int main(int argc, char const* argv[])
{
    int T,ANS[1000],cont=0,n;
    std::cin >> T;
    while(T-->0){
        std::cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            std::cin >> a[i];
        std::sort(a,a+n);
        ANS[cont++]+=findsum(a,n);
    }
    display(ANS,cont);
    return 0;
}

int findsum(int a[],int n){
    int sum=0,subset_num=1;
    for(int i=0;i<n;i++){
        sum+=a[i]*subset_num;
        subset_num<<=1;
    }
    return sum;
}

void display(int obj[],int num_of_obj){
    for(int i=0;i<num_of_obj;i++){
        std::cout << "case #" << i+1 
                  << ' '      << obj[i]
                  << std::endl;
    }
}


/*
 * 题解：
 * 1、可将题意简单地理解为求有限集A的所有非空子集的最大元素之和
 * 2、因此，可先将集合A变为有序集，设用A[[i]]表示集合A的第i个元素（i从0开始），则：
 * 3、以A[[i]]为最大元素的子集合共有2^i个，易得：
 * 4、answer=Sum[A[[i]]*2^i,{i,1,n}](*mathematica语言风格*)
 * 5、AC
 */
