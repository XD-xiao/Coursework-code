package chapter;

/**
 * 2.请编写程序，由键盘录入一个字符串，
 * 统计字符串中英文字母和数字分别有多少个。
 * 比如：Hello12345World中字母：10个，数字：5个。
 */
import java.util.Scanner;

public class text02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Input a string:");
        String str = sc.next();
        int alpCount = 0 , digCount = 0 ;

        for(int i=0 ; i<str.length() ; ++i){
            if( 'A'<str.charAt(i) && str.charAt(i)<'Z' )
                ++alpCount;
            else if( 'a'<str.charAt(i) && str.charAt(i)<'z' )
                ++alpCount;
            else if( '0'<str.charAt(i) && str.charAt(i)<'9' )
                ++digCount;

        }
        System.out.println("字母个数: " + alpCount );
        System.out.println("数字个数: " + digCount );
    }
}
