package chapter;

/**
 * 3.借助于String类中的indexOf()和substring()方法
 * 实现以下文本
 * “Java语言是面向对象的，Java语言是健壮的，Java语言是安全的，Java是高性能的，Java语言是跨平台的"中”Java“
 * 一词出现的次数。
 */


public class text03 {
    public static void main(String[] args) {

        String text = "Java语言是面向对象的，Java语言是健壮的，Java语言是安全的，Java是高性能的，Java语言是跨平台的";
        String sub = "Java";

        int index = -1 ,count = 0 ;
        while(true){
            index = text.indexOf(sub,index+1);
            if( index != -1)
                ++count;
            else
                break;
        }

        System.out.println(count);

    }
}
