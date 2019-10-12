/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    public static BigInteger fact(int total,int r)
	{
		BigInteger A,B;
		A=BigInteger.ONE;
		B=BigInteger.ONE;
		total++;
		for(int i=r;i>=1;i--)
		{
			A=A.multiply(BigInteger.valueOf(total-i));
			B=B.multiply(BigInteger.valueOf(i));
		}
		A=A.divide(B);
		return A;
	}
	public static void interest(int a[],int k,int n)
	{
		int internal_count=0,external_count=0;
		int x=k-2;
		while(x>=0&&a[x]==a[x+1])
		{
			internal_count++;
			x--;
		}
		x=k;
		while(x<=n-1&&a[x]==a[x-1])
		{
			external_count++;
			x++;
		}
		if(external_count==0)
		{
			System.out.println(1);
			return;
		}
		internal_count++;
		int total=external_count+internal_count;
		System.out.println(fact(total,internal_count));
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner sc=new Scanner(System.in);
		int t=0;
		if(sc.hasNext())
		{
			t=sc.nextInt();
		}
		while(t-->0)
		{
			int n=0;
			if(sc.hasNext())
			{
				n=sc.nextInt();
			}
			int k=0;
			if(sc.hasNext())
			{
				k=sc.nextInt();
			}
			int ar[]=new int[n];
			for(int i=0;i<n;i++)
			{
				if(sc.hasNext())
				{
					ar[i]=sc.nextInt();
				}
			}
			Arrays.sort(ar);
			interest(ar,k,n);
		}
	}
}
