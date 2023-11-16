
import java.util.Scanner;

public class Demo02 {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int min ,max ;
        System.out.print("请输入一个最小数：");
        min = sc.nextInt();
        System.out.print("请输入一个最大数：");
        max = sc.nextInt();

        int i,count = 0 ;
        for( i=min ; i<=max ; ++i){
            if(printPrime(i)){
                System.out.print(i + "  ");
                ++count;
                if( count%5 == 0 )
                    System.out.println();
            }

        }
    }

    //65
    public static boolean printPrime(int num){

        int j;
        for( j=2 ; j<=Math.sqrt(num) ; ++j){
            if( num%j == 0 )
                break;
        }
        if( j>Math.sqrt(num) )
            return true;
        return false;

    }
}
