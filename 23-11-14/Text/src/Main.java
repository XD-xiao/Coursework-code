public class Main {
    public static void main(String[] args) {

        System.out.println(getMax(2,3));
        System.out.println(getMax(2.5,2.6));
        System.out.println(getMax(2,3,1));
        System.out.println(getMax("123","45"));
        System.out.println(getMax("abc","ab","abcd","a"));


    }
    public static String getMax(String...array){

        String max = array[0];
        for(String str:array){
            if( max.length() < str.length())
                max = str;
        }
        return max;
    }


    public static int getMax(int a,int b){
        if( a>b )
            return a;
        else
            return b;
    }
    public static double getMax(double a,double b){
        if( a>b )
            return a;
        else
            return b;
    }
    public static int getMax(int a,int b,int c){
        if( a>b )
            if( a>c )
                return a;
            else
                return c;
        else{
            if(b>c)
                return b;
            else
                return c;
        }

    }
    public static String getMax(String a,String b){
        if( a.length() > b.length())
            return a;
        else
            return b;
    }


}