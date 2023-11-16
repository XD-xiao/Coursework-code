import java.util.Arrays;

public class Demo01 {
    public static void main(String[] args) {
        int[] obj = new int[]{1,2,3,4};
        int[] res = new int[3];

        System.out.println("Main "+obj);
        System.out.println("Main "+res);

        arrayAdd(res,obj);

        System.out.println("Main obj "+Arrays.toString(obj));
        System.out.println("Main res "+Arrays.toString(res));


    }

    public static void arrayAdd(int[] res,int[] obj){
        System.out.println("method "+obj);
        System.out.println("method "+res);

      //  res = Arrays.copyOf(obj, obj.length);
        res[0] = obj[0];

        System.out.println("Method "+Arrays.toString(res));

    }
}
