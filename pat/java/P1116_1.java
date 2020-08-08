import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class P1116 {
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int n = Reader.nextInt();
        int id ;//表示获奖id，从1 开始
        HashMap<Integer, String> map = new HashMap<>();
        id = Reader.nextInt();
        map.put(id, "Mystery Award");

        if (n > 1) {
            for (int i = 2; i <= n; i++) {
                id = Reader.nextInt();
                //如果说明是一个素数
                if (isPrime(i)) {
                    map.put(id, "Minion");
                } else {
                    map.put(id, "Chocolate");
                }
            }
        }

        //query
        int k = Reader.nextInt();
        for(int i = 0;i < k ;i++) {
            id = Reader.nextInt();
            //System.out.println("query id = "+id);
            if (map.get(id) != null) {
                System.out.printf("%04d: %s\n",id , map.get(id));
                map.put(id, "Checked");
            } else {
                System.out.printf("%04d: Are you kidding?\n",id );
            }
        }
    }

    //表示该数是否是一个素数
    public static boolean isPrime(int number) {
        for (int i = 2;i< Math.sqrt(number);i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return  true;
    }

    static void init() {
        int i = 0,j = 0;
        int primeArray[] = new int[100];
        for (i = 0;i < 10000;i++ ) {
            primeArray[i] = i;
        }
        for(j = 2;j<= 10000;j++) { //因为1 不是素数
            if (primeArray[j] != 0) {
                System.out.println(primeArray[j]);
            }
            for(i = 2;i <= 10000;i++) {
                if (i % j == 0) {
                    primeArray[i] = 0;
                }
            }
        }
    }

    public static boolean isPrimeFast(int number) {
        int i = 0,j = 0;
        int primeArray[] = new int[100];
        return true;

    }
}

/*
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222


6
1111
6666
8888
1234
5555
0001
5
8888
0001
1111
2222
8888

1
1111
5
8888
0001
1111
2222
8888


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