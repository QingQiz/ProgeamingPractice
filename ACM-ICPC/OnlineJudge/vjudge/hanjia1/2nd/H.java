import java.util.*;
import java.math.BigInteger;
public class H{
	private static Scanner cin;

	public static void main(String [] args){
		//prime list.
		int maxn=1000010;
		int primelist[]=new int[1000010];
		int cnt=0;
		boolean primeq[]=new boolean[1000010];
		for (int m = 0; m < primeq.length; m++) {
			primeq[m]=true;
		}
		primeq[0]=primeq[1]=false;
		for(int i=2;i<maxn;i++){
			if(primeq[i]){
				primelist[cnt++]=i;
				if(i>=maxn/i)continue;
				for(int j=i*i;j<maxn;j+=i)
					primeq[j]=false;
			}
		}
		
		cin = new Scanner(System.in);
		int l;
		BigInteger k;
		while(true){
			boolean flg=true;
			k=cin.nextBigInteger();
			l=cin.nextInt();
			if(k.equals(BigInteger.ZERO)&&l==0)break;
			for(int i=0;primelist[i]<l&&i<cnt;i++){
				if((k.mod(BigInteger.valueOf(primelist[i]))).equals(BigInteger.ZERO)){
					System.out.println("BAD "+ primelist[i]);
					flg=false;
					break;
				}
			}
			if(flg)System.out.println("GOOD");
		}
	}
}

//https://vjudge.net/contest/205706#status
//人生第一个java程序，原因是懒得写大数除法
//题目算是很简单的了。
//建立一个素数表，从小到大取模数，如果在小于l的情况下模数为0,则BAD，否则GOOD
//注意因数必须小于l才输出BAD，等于时输出GOOD
