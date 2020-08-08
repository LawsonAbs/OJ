import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class P1124 {
    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int n = Reader.nextInt();
        int skip = Reader.nextInt();
        if (skip == 0) {
            skip = 1001;
        }
        int first = Reader.nextInt();
        int i = 0;
        List<String> name = new LinkedList<>();
        String str;
        //System.out.println("n = "+ n+",skip = "+skip+", first = "+first);
        //String winner[] = new String[N];
        Set<String> winner = new LinkedHashSet<>();
        for(i = 0;i < n;i++) {
            str = Reader.next();
            name.add(str);
        }

        int count = 1;// 用于计数是否skip 了
        if (first > n) {
            System.out.println("Keep going...");
            System.exit(0);
        }
        winner.add(name.get(first - 1));//首先将第一个获奖的人添加进去
        for(i = first;i < name.size();i++) {
            //如果轮到了，但是之前没有数据
            if (count%skip == 0 && (!winner.contains(name.get(i)))) {
                winner.add(name.get(i));
                count = 0;//reset 0
            }
            //如果轮到了，但是之前有数据
            else if (count%skip == 0 && (winner.contains(name.get(i)))) {
                String temp = name.get(i);//表示该name已经获奖
                while (name.get(i).equals(temp) && i < name.size() - 1) {//重复找到下一个没有获奖的人
                    i++;
                }
                winner.add(name.get(i));//添加下一个名单
                count = 0;//reset 0
            }
            count++;
        }
        for (String s : winner) {
            System.out.println(s);
        }
    }
}


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
