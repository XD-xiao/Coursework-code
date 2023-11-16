package chapter;

/**
 * 编写方法实现获取两个字符串中最大相同子串，
 * public static String findMaxSubString(String str1,String str2) 。
 * 比如：str1 = "abcwerthelloyuiodef";str2 = "cvhellobnm"的最大相同子串是"hello"。
 * 并在main方法中验证器正确性。
 * 提示：将短的那个串进行长度依次递减的子串与较长的串比较
 */

public class text11 {
    public static void main(String[] args) {
        String str1 = "abcwerthelloyuiodef";
        String str2 = "cvhellobnm";

        if( str1.length() < str2.length() ){
            String t = str1;
            str1 = str2;
            str2 = t;
        }
        String maxSub = "";
        for(int start=0 ; start<str2.length() ; ++start )
            for( int end=str2.length() ; end>start ; --end ){
                String sub = str2.substring(start,end);
                if( str1.indexOf(sub) != -1 && sub.length()>maxSub.length() )
                    maxSub = sub;
        }
        System.out.println(maxSub);

    }
}
