/**
 * 1.编写程序，生成[0,9]之间的100个随机整数，然后显示每个数出现的此数。（提示：使用一个包含10个整数的数组存放0-9这是个数据）
 */
import java.util.Random;
public class text01 {
    public static void main(String[] args){
        Random rand = new Random();
        int[] digit = new int[10];

        for( int i=0 ; i<100 ; ++i)
            ++digit[rand.nextInt(10)];

        for( int i=0 ; i<10 ; ++i){
            System.out.println( i + "有 " + digit[i] + " 个");
        }
    }
}
