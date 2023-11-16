/**
 * （1）创建一个生成指定长度为n的一个一维数组，初始值为100之内的随机数，方法签名为public static int[] initArray(int n)
 * （2）创建一个数组的遍历方法（即将数组数据整体输出，每个元素之间用空格或\t分隔），方法签名为public static void print(int[] array)
 * （3）创建一个数组的逆置，方法签名为public static void reverse(int[] array)，如原来为：1 2 3 4 5 逆置后为5 4 3 2 1
 * （4）创建一个方法，获取数组元素的平均值，方法签名为public static double getAvg(int[] array)
 * （5）创建一个方法，查找指定元素是否在其中，如果在返回在数组中的下标，不存在返回-1，方法签名public static int searchNum(int[] array,int m)
 * （6）创建数组的排序方法（自由选择一种排序规则） 在main方法中调用验证以上个方法，上传代码截图以及运行结果图。
 */
import java.util.Scanner;

public class text11 {
    public static void main(String[] args) {
        int len = 9;


        int[] arr ;
        arr = initArray( len ) ;
        print(arr);
        reverse(arr);
        print(arr);
        System.out.println("Avg = " + getAvg(arr) );
        sort(arr);
        print(arr);

        int index = searchNum(arr,66);
        if( index!=-1)
            System.out.println("66在数组中下标为" + index );
        else
            System.out.println("66在数组中不存在");


    }
    public static int[] initArray(int n){
        int[] arr = new int[10];
        for( int i=0 ; i<n ; i++)
            arr[i] = (int) (Math.random() * 100 );
        return arr;
    }
    public static void print(int[] array){

        for(int i=0 ; i<array.length ; ++i)
            System.out.print(array[i] + "  ");
        System.out.println();
    }
    public static void reverse(int[] array){
        for(int i=0 ; i<array.length/2 ; ++i){
            array[i] = array[i] ^ array[array.length-i-1];
            array[array.length-i-1] = array[i] ^ array[array.length-i-1];
            array[i] = array[i] ^ array[array.length-i-1];
        }
    }
    public static double getAvg(int[] array){
        long sum = 0;
        for(int i=0 ; i<array.length ; ++i)
            sum += array[i];
        return (double)sum/array.length;
    }
    public static int searchNum(int[] array,int m){
        int left = 0 , right = array.length-1 ,mid ;
        while( left<=right ){
            mid = left + (right-left)/2;
            if( m < array[mid] )
                right = mid - 1;
            else if( m > array[mid] )
                left = mid +1;
            else
                return mid;
        }
        return -1;
    }
    public static void sort(int[] array){

        for( int i=0 ; i<array.length-1 ; ++i)
            for( int j=i ; j<array.length ; ++j)
                if( array[i] > array[j] ){
                    array[i] = array[i] ^ array[j];
                    array[j] = array[i] ^ array[j];
                    array[i] = array[i] ^ array[j];
                }
    }
}
