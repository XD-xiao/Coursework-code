/**
 * 题目1
 * 键盘录入两个数字number1和number2表示一个范围，求这个范围之内的数字和。
 */

import java.util.Scanner;

public class Demo01 {
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

        int sum = 0 , i ;
        for( i =min ; i<=max ; i++)
            sum = sum + i ;

        System.out.print("在" + min + "~" + max + "范围内");
        System.out.print("数字和为 " + sum);

        sc.close();
    }
}
