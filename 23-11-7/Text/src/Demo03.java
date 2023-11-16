import java.util.Scanner;

public class Demo03 {
    public static void main(String[] args)
    {
        System.out.print("请输入一个月份:");
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int res = switch( (num)/4 )
        {
            case 0->0;
            case 1->1;
            case 2->2;
            case 3->3;
            default -> {System.out.print("ERROR");
                yield 12;
            }
        };

        System.out.print("res = " + res);

        sc.close();
    }
}
