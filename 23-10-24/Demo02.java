import java.util.Scanner;


public class Demo02
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入一个数字1：");
		int num1 = sc.nextInt();
		int num2 = sc.nextInt();

		if(num1<num2)
			System.out.print( num2 + "大"  );
		else if(num1>num2)
			System.out.print( num1 + "大" );
		else
			System.out.print( "相等" );
		
		sc.close();
	}
}