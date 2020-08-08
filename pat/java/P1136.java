import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        String origin = Reader.next();
        int count = 0;
        while (count < 10 ) {
            if (isPalindromic(origin)) {
                System.out.printf("%s is a palindromic number.",origin);
                break;
            }
            String reverse = reverse(origin);
            origin = cal(origin, reverse);
            //System.out.println(isPalindromic(cal(origin,reverse)));
            count++;
        }

        if (count == 10) {
            System.out.println("Not found in 10 iterations.");
        }
    }

    //计算number的倒数
    //因为 number 可能会很大，所以需要使用String 存储
    public static String reverse(String number) {
        StringBuilder reverse= new StringBuilder();
        char c ;
        for (int i = number.length() - 1; i >= 0; i--) {
            c = number.charAt(i); // get the
            //reverse = reverse + c;
            reverse.append(c);
        }
        return  reverse.toString();
    }

    //计算两个整数的和
    public static String cal(String num1,String num2) {
        BigInteger bi_1 = new BigInteger(num1);
        BigInteger bi_2 = new BigInteger(num2);
        BigInteger sum = bi_1.add(bi_2);
        System.out.printf("%s + %s = %s",bi_1.toString(),bi_2.toString(),sum.toString());
        System.out.println();
        return sum.toString();
    }

    //对一个数进行回文判断
    public static boolean isPalindromic(String number) {
        final boolean FALSE = false;
        final boolean TURE = true;
        int k = number.length();
        int i =0;
        int mid = k/2;
        while (i < mid) {
            if(number.charAt(i) != number.charAt(k - 1 - i))
                break;
            i++;
        }
        if (i < mid) {
            return  FALSE;
        }
        return TURE;
    }
}

/*
97152

196

0
 */

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