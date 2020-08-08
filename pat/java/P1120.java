import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class P1120 {
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int n = Reader.nextInt();
        int i = 0;
        int num ;
        int sum ;
        int count = 0; //表示和数目
        //9999 => 36
        int array[] = new int[50];
        for(i = 0;i < n;i++) {
            num = Reader.nextInt();
            sum = calSum(num);
            if (array[sum] != 1) {
                count++;
                array[sum] = 1;
            }
            //System.out.println("num = "+num+", sum = "+sum);
        }

        System.out.println(count);
        for(i = 0;i< 50;i++) {
            if (array[i] != 0) {
                if (count > 1) {
                    System.out.print(i+" ");
                    count--;
                }
                else
                    System.out.print(i);
            }
        }
    }


    //计算每个数字的 各个位数的和
    static int calSum(int number) {
        int sum = 0 ;
        int temp ;
        while (number != 0) {
            temp = number%10;
            number = number / 10;
            sum += temp;
        }
        return sum;
    }
}

/*

 */

class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) throws IOException {
        reader = new BufferedReader(new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
        //这里初始化tokenizer只是为了进入下面的while()循环，而不是别的原因。
        //那么还有优化的空间么？
    }

    /** get next word */
    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {//如果后面还有数据，则直接返回
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(reader.readLine() );//否则，读取下一行
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt( next() );
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble( next() );
    }

    //获取字符 => 因为 next()方法返回的是一个String
    static char nextChar() throws IOException {
        return next().charAt(0);
    }
}