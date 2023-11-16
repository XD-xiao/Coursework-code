
//方法三
import java.util.*;

public class Demo03
{
	public static void main(String[] args)
	{
		//方法一
		long times = System.currentTimeMillis();
		int r1 = (int)(times%1000);
		System.out.println("r1 = " + r1);
		//方法二
		int r2 = (int)(Math.random()*100);
		System.out.println("r2 = " + r2);
		//方法三
		Random num = new Random();
		int r3 = num.nextInt(100);
		System.out.println("r3 = " + r3);
	}
}