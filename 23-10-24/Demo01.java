import java.util.Scanner;


public class Demo01
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入一个数字：");

		int num = sc.nextInt();

		int sum = 0 ;

		for(; num!=0 ; num/=10)
			sum = sum + num%10;

		System.out.print("sum = " + sum );
		sc.close();
	}
}