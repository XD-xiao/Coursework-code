package chapter;

/**
 * 4.编写方法 public static String reverse(String str,int start,int end)
 * 实现将字符串中指定部分start到end位置的字符进行反转。
 * 比如将str=“abcdefgho”作为参数调用reverse(str,2,5)，
 * 返回结果为”abfedcgho”。
 */
import java.util.Scanner;
public class text04 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Input a string:");
        String str = sc.next();

        String newStr = reverse( str,2,5);

        System.out.print("New string:" + newStr );
    }
    public static String reverse(String str,int start,int end){
        char[] sub = str.substring(start,end+1).toCharArray();
//        System.out.println(sub);
        for(int i=0 ; i<(end-start+1)/2 ; ++i){
            char t = sub[i];
            sub[i] = sub[end-start-i];
            sub[end-start-i] = t;
        }
        String substr = String.valueOf(sub);

//        System.out.println(str.substring(start,end+1));
//        System.out.println(substr);

        str = str.replace( str.substring(start,end+1) , substr );
        return str;
    }

}
