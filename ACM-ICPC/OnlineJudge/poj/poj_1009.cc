#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=1000;//最多有1000对
int width;//图像的宽度
int tot;//像素点的总数

typedef class ImgInf{
public:
    int pos;//该像素点是第几个点，即编号
    int code;//该像素点的编码
    bool operator<(const ImgInf L)const{
        return L.pos>pos;
    }
}Img;

int InImgInf[maxn][2];//记录没对pair的像素和数量
Img OuImfInf[8*maxn];//每个像素点的编码都依赖于其周围的8个点

int getCod(int pos);//获取第pos个点的像素值
int getPix(int pos);//获取第pos个点的编码

int main(int argc, char const* argv[])
{
    int k;
    while (cin >> width && width) {
        tot=0;k=0;//k记录该图像实际由几个pair
        int pix,pair;
        while (cin >> pix >> pair && pair) {
            InImgInf[k][0]=pix;
            InImgInf[k++][1]=pair;
            tot+=pair;
        }
        int pairnum=k,pos=1/*当前处理的点的序号*/;k=0;//OuImfInf指针
        for(int p=0;p<=pairnum;p++){
            int row=(pos-1)/width;//该点的二维坐标
            int col=(pos-1)%width;
            for(int i=row-1;i<=row+1;i++){
                for(int j=col-1;j<=col+1;j++){
                    int nowpos=i*width+j+1;//该坐标的点的编号
                    if(i<0 || j<0 || j>=width || nowpos >tot)
                        continue;
                    OuImfInf[k].pos=nowpos;
                    OuImfInf[k++].code=getCod(nowpos);
                }
            }//枚举像素改变的点周围的9个点
            pos+=InImgInf[p][1];//下一个像素发生改变的点
        }
        sort(OuImfInf,OuImfInf+k);//快排，依赖于重载的<
//Display....
        cout << width << endl;
        Img mid=OuImfInf[0];
        for(int i=0;i<k;i++){
            if(mid.code==OuImfInf[i].code)
                continue;
            cout << mid.code << ' ' << OuImfInf[i].pos-mid.pos << endl;
            mid=OuImfInf[i];
        }
        cout << mid.code << ' ' << tot-mid.pos+1 << endl;
        cout << "0 0" << endl;
    }
    cout << '0' << endl;
//Display....
    return 0;
}


int getPix(int pos){
    int k=0,p=0;
    while (p<pos) {
        p+=InImgInf[k++][1];
    }
    return InImgInf[k-1][0];
}

int getCod(int pos){
    int row=(pos-1)/width;
    int col=(pos-1)%width;
    int pixnow=getPix(pos);
    int maxdiff=0;
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            int nowpos=i*width+j+1;
            if(i<0 || j<0 || j>=width || nowpos>tot || nowpos==pos)
                //nowpos==pos 是跳过中心点本身
                continue;
            int pix=getPix(nowpos);
            if(maxdiff<abs(pixnow-pix))//绝对值....
                maxdiff=abs(pixnow-pix);
        }
    }
    return maxdiff;
}


//-------------------------------------------------------
//https://vjudge.net/contest/205705#problem/T           |
//-------------------------------------------------------
//给了一个图像求编码后的图像。                          |
//-------------------------------------------------------
//如果对每个点进行编码无疑会超时，因此需要进行跳跃式编码|
//即只对像素发生变化的点进行编码，而像素没有改变的点的编|
//码与左边的保持一致，数据最多由1000个变化的点，因此此方|
//法可解。                                              |
//-------------------------------------------------------
//主体的思路是只对像素变化的点的周围8个点进行编码，最后 |
//左对齐(值)输出                                        |
//-------------------------------------------------------
