import java.util.Scanner;

public class ScanDemo
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("请输入一个数字：");

		int num = sc.nextInt();

		if( num%2 == 0 )
			System.out.println( num + "是偶数" );
		else
			System.out.println( num + "是奇数" );

		sc.close();
	}
}