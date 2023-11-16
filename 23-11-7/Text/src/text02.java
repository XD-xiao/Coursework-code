/**
 * 2.编写程序读入10个整数，显示互不相同的数字的数目，并以输入的顺序显示这些数字，
 * 数字之间仅以一个空格分隔（即如果一个数出现多次，也仅显示一次）。
 * (提示：读入一个数，如果是一个新数，则将它存储到数组中，如果已经存在则忽略它）
 */
import java.util.Scanner;

public class text02 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[10];
        int len = 0 ;
        int num ;
        for(int i=0 ; i<10 ; ++i){
            System.out.print("请输入第" + (i+1) + "个数:");
            num = sc.nextInt();
            int j;
            for( j=0 ; j<len ; ++j)
                if( num == arr[j] )
                    break;
            if( j==len ){
                arr[len++] = num;
            }
        }

        for(int i=0 ; i<len ; ++i){
            System.out.print(arr[i] + " ");
        }
        sc.close();
    }
}
