import java.util.Scanner;

public class Demo02
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);

		System.out.print("请输入第一个整数:");
		int num1 = sc.nextInt() ;

		System.out.print("请输入第二个整数:");
		int num2 = sc.nextInt() ;


		System.out.print("请输入您要进行的运算(1:表示加法,2:表示减法,3:表示乘法,4:表示除法):");
		byte type  = sc.nextByte() ;

		double res  = 0f;

		switch( type )
		{
			case 1: res = num1 + num2 ;break;
			case 2: res = num1 - num2 ;break;
			case 3: res = num1 * num2 ;break;
			case 4: res = (double)num1 / num2 ;break;
			default:System.out.println("type error ");
		}

		System.out.println("计算结果:" + res);

		sc.close();
	}
}