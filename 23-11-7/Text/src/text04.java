/**
 * 4.编写程序实现从键盘输入10个正整型数据，判断其是否是回文数字，
 * 并返回所有的回文数字。如121 是回文 123不是回文，
 * 其中数据的反转方法签名为：public static int intreverse(int num);
 * 判断回文的方法签名为：public static boolean isPalindrom(int num);
 */
import java.util.Scanner;
public class text04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[10];
        for( int i=0 ; i<10 ; ++i){
            System.out.print("请输入第" + (i+1) + "个数:");
            arr[i] = sc.nextInt();
            if( isPalindrom(arr[i]) )
                System.out.println("是回文数字");
            else
                System.out.println("不是回文数字");
        }

    }
    public static int intreverse(int num){
        int rev = 0;
        while( num!=0 ){
            rev = rev*10 + num%10 ;
            num /= 10 ;
        }
        return rev;
    }
    public static boolean isPalindrom(int num){
        if( num == intreverse(num) )
            return true;
        else
            return false;
    }
}
