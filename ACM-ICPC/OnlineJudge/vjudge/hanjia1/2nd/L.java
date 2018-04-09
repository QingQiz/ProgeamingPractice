import java.util.*;
import java.math.BigInteger;

public class L{
	public static BigInteger Fac(int n){
		BigInteger ans=BigInteger.ONE;
		for(int i=1;i<=n;++i){
			ans=ans.multiply(BigInteger.valueOf(i));
		}
		return ans;
	}
	
	public static BigInteger C(int m,int n){
		return Fac(n).divide(Fac(m).multiply(Fac(n-m)));
	}
	
	private static Scanner cin;

	public static void main(String [] args){
		cin = new Scanner(System.in);
		BigInteger ans;
		int n;
		while(cin.hasNextInt()){
			n=cin.nextInt();
			ans=C(n,2*n).subtract(C(n-1,2*n));
			System.out.println(ans);
		}
	}
}

//https://vjudge.net/contest/205706#problem/L
//卡特兰数，
//题目可以简化为在任意时刻进站的次数大于等于出站的次数，简单推导可以得到
//ans=C(n,2n)-C(n-1,2n).
//推到过程简述：
//假设不满足条件，则存在一点使得这一点左边的进站次数+1等于出站次数
//用1表示进站，0表示出站，将这一点右边的1变成0,0变成1,则一共有n-1个1,n+1个0
//所以每一个不满足条件的情况都可以转化成一个n-1个1,n+1个0的排列。
//而对于每一种n-1个1,n+1个0的排列在任意一点将其右边的1变成0,0变成1，都可以变成一个不满足条件的情况
//因此它们两个是一一对应的，排列的总个数相等。
//因此满足条件的排列数量=所有的排列(C(n,2n))-不满足条件的排列(C(n-1,2n)
