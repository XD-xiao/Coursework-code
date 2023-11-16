/**
 * 3.编写程序实现指定范围内的素数的打印，要求打印的素数每5个一行。
 * 素数的判断要求使用方法实现，方法签名为：public static boolean isPrime(int n);
 */
import java.util.Scanner;

public class text03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int min,max;
        System.out.print("请输入一个最小数:");
        min = sc.nextInt();
        System.out.print("请输入一个最大数:");
        max = sc.nextInt();
        int count = 0 ;
        for( int i = min ; i<=max ; ++i){
            if( isPrime(i) ){
                System.out.print( i + "  ");
                ++count;
                if(count%5==0)
                    System.out.println();
            }
        }


    }
    public static boolean isPrime(int n){
        int j;
        for( j=2 ; j<=n/2 ; ++j)
            if( n%j==0)
                break;
        if( j>n/2 )
            return true;
        return false;
    }
}
