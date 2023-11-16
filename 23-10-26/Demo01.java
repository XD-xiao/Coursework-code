import java.util.Scanner;

public class Demo01
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("请输入顾客类型(0 or 1):");
		byte type = sc.nextByte() ;

		System.out.print("购物金额:");
		int pri = sc.nextInt() ;

		double pay  = 0f;

		if( type == 0) //顾客
		{
			if( pri < 100)
				pay = pri ;
			else
				pay = pri * 0.9 ;
		}
		else if( type == 1 ) //会员
		{
			if( pri < 200)
				pay = pri * 0.8;
			else
				pay = pri * 0.75 ;
		}
		else
			System.out.println("type error ");

		System.out.println("应付金额:" + pay);

		sc.close();
	}
}