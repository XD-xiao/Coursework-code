package chapter;

public class Demo01 {

    public static void main(String[] args) {

        String fileName = ".abc.abc.aba.doc.txt.java";
        int index = -1 ,count = 0 ;
        while(true){
            index = fileName.indexOf(".",index+1);
            if( index != -1)
                ++count;
            else
                break;
        }

        System.out.println(count);

    }

}
