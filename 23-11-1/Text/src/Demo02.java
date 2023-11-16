import java.util.Scanner;

/**
 * 题目2
 *
 * 需求：键盘录入两个数字，表示一个范围。
 * 统计这个范围中。既能被3整除，又能被5整除数字有多少个？
 */
import java.util.Scanner;

public class Demo02 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the first number:");
        int min = sc.nextInt();
        System.out.print("Please enter the second number:");
        int max = sc.nextInt();

        if( min > max ){
            min = min ^ max;
            max = min ^ max;
            min = min ^ max;
        }

        int count = 0 , i ;
        for( i =min ; i<=max ; i++){
            if( i%3 == 0 && i%5 == 0 )
                ++count;
        }

        System.out.println("共有" + count + "个");

        sc.close();

    }
}
