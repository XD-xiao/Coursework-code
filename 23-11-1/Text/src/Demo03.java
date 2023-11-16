/**
 * 题目3
 * 需求：给你一个整数 x 。
 * 如果 x 是一个回文整数，打印 true ，否则，返回 false 。
 * 解释：回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 例如，121 是回文，而 123 不是。
 */
import java.util.Scanner;

public class Demo03 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        System.out.print("Please enter the first number:");
        int num = sc.nextInt();

        int rev = 0 ,x = num ;
        while( x !=0 ){
            rev = rev * 10 + x%10;
            x /= 10;
        }

        if( rev == num )
            System.out.println("True");
        else
            System.out.println("False");

        sc.close();
    }
}
