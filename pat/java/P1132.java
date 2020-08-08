import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int n = Reader.nextInt();
        int i = 0;
        int num;
        for (i = 0; i < n; i++) {
            num = Reader.nextInt();
            System.out.println(splitProduct(num));
        }
    }


    public static String splitProduct(int number) {
        int temp = number;
        final String No = "No";
        final String Yes = "Yes";
        int a=0,b=0;
        int array[] = new int[40];

        int i = 0;
        int index = 0;
        while (temp != 0) {
            array[index++] = temp % 10;
            temp = temp / 10;
        }

        int mid = index /2;// the mid of number
        i = index;
        while (i >= mid) {
            a = (a * 10) + array[i];
            i--;
        }

        while (i >= 0 ) {
            b = (b * 10) + array[i];
            i--;
        }
        if (a == 0 || b == 0) {
            return No;
        }
        else if (number % a == 0) {
            number /= a;
            if (number % b == 0) {
                return Yes;
            }
        }
        return No;
    }
}


class Reader {
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
    static void init(InputStream input) throws IOException {
        reader = new BufferedReader(new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
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