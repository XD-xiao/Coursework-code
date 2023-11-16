public class ChangeDemo
{
	public static void main(String[] args)
	{
		int a = 2 , b = 3 ;

		System.out.println("方法一");
		System.out.println("a = " + a + "  b = " + b );
		a = a + b ;
		b = a - b ;
		a = a - b ;
		System.out.println("a = " + a + "  b = " + b );

		System.out.println("方法二");
		System.out.println("a = " + a + "  b = " + b );
		int temp ; 
		temp = a ;
		a = b ;
		b = temp ;
		System.out.println("a = " + a + "  b = " + b );

		System.out.println("方法三");
		System.out.println("a = " + a + "  b = " + b );
		a = a ^ b ;
		b = a ^ b ;
		a = a ^ b ;
		System.out.println("a = " + a + "  b = " + b );

	}
}