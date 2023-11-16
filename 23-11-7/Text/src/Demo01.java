public class Demo01 {
    public static void main(String[] args) {
        System.out.println("Hello world!");

        System.out.println("1.");
        for(int i=0 ; i<6 ; ++i){
            for(int j=0 ; j<5 ; ++j){
                System.out.print("*");
            }
            System.out.print("\n");
        }

        System.out.println("\n\n2.");

        for(int i=0 ; i<=5 ; ++i){
            for(int j=0 ; j<6-i ; ++j)
                System.out.print(" ");
            for(int j=0 ; j<i*2-1 ; ++j)
                System.out.print("*");
            System.out.print("\n");
        }



    }
}
