/*
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class P1128 {
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int n = Reader.nextInt();
        int i = 0;
        int array[] = new int[1000];

        //System.out.println("n = "+ n+",skip = "+skip+", first = "+first);
        int num;
        for(i = 0;i < n;i++) {
            array[i]= Reader.nextInt();//放入数组中

        }
    }
}
*/
/*
1.在读入数据的时候，就对
 *//*


class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    */
/** call this method to initialize reader for InputStream *//*

    static void init(InputStream input) throws IOException {
        reader = new BufferedReader(new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
        //这里初始化tokenizer只是为了进入下面的while()循环，而不是别的原因。
        //那么还有优化的空间么？
    }

    */
/** get next word *//*

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
*/
