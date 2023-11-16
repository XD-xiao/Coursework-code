package chapter;

/**
 * 1.从键盘输入任意字符串，编程实现打乱里面的内容。
 * 提示：字符串是不可变的，如要变化可变换为字符数组，
 * 然后利用Random类实现数组内容的打乱，打乱后再将字符数组变回字符串。
 */
import java.util.Random;
import java.util.Scanner;
import java.util.Arrays;

public class text01 {
    public static void main(String[] args) {

        Random rand = new Random();
        Scanner sc = new Scanner(System.in);

        System.out.print("Input a string:");
        String text = sc.next();

        int [] secKey = new int[text.length()];

        for (int i = 0; i < text.length() ; ++i ){
            secKey[ i ] = rand.nextInt(text.length()) ;
            for(int j = 0 ; j<i ; ++ j )
                if( secKey[i] == secKey[j] )
                    --i;
        }
        System.out.println("密钥：" + Arrays.toString(secKey));

        //加密
        char[] ch = text.toCharArray()  ;
        for(int i=0 ; i<text.length() ; ++i){
            char t = ch[i] ;
            ch[i] = ch[ secKey[i] ] ;
            ch[ secKey[i] ] = t ;
        }
        text = String.valueOf(ch);
        //显示密文
        System.out.println("密文:" + text);
        //解密
        ch = text.toCharArray()  ;
        for(int i=text.length()-1 ; i>=0 ; --i){
            char t = ch[i] ;
            ch[i] = ch[ secKey[i] ] ;
            ch[ secKey[i] ] = t ;
        }
        text = String.valueOf(ch);
        //显示密文
        System.out.println("明文:" + text);

    }
}
