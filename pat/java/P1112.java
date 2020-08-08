import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class P1112 {
    //System.out.println((int)'a' - 87); // 将a 设置为10 下标为10

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int k = Reader.nextInt();
        String str = Reader.next();
        // System.out.println("k = "+k+",str = "+str);


        int[] badKey = new int[50];
        for(int i = 0;i<50;i++) {
            badKey[i] = -1; //初始化
        }
        //-1 初始化
        //1 好
        //0 坏

        //开始遍历处理
        //将可能有问题的字符放在badKey 中。
        char curChar ;//当前处理的字符
        String res="";//最后的字符串
        Set<Character> set = new LinkedHashSet<>();
        for(int i = 0;i< str.length();i++) {
            curChar = str.charAt(i);//依次判断每个字符
            //System.out.println("curChar = "+curChar);
            int count = 0;
            while (count < k) {
                if (i + count< str.length() && str.charAt(i + count) == curChar) {//说明是重复的数据
                    count++;
                } else {
                    break;
                }
            }
            if (count % k == 0 && count !=0) {//说明这个字符可能是坏键
                if (badKey[map(curChar)] == -1 ) {//如果之前没有修改过，则设置成-1
                //if (map(curChar) != -1 || map(curChar) != 1) {//如果之前没有修改过，则设置成-1
                    badKey[map(curChar)] = 0;
                    set.add(curChar);
                }
                //只要满足倍数情况，那么都要执行 i += k-1
                i+=k-1;//再加2
            } else {//否则，不是坏键
                badKey[map(curChar)] = 1;
                if (set.contains(curChar)) {
                    set.remove(curChar);//移除
                }
            }
        }
        //System.out.print("badKey = ");

//        for(int i = 0;i<badKey.length;i++) {
//            if(badKey[i] == 0)
//            {
//                //System.out.println(i);
//                System.out.print(reverseMap(i));
//               // set.add(reverseMap(i));
//            }
//        }
        for (char c : set) {
            System.out.print(c);
        }System.out.println();


        //System.out.println("set.size = "+set.size());
        //输出正常的结果
        for(int i = 0;i<str.length();i++) {
            if (set.contains(str.charAt(i))) {
                i+=k-1;
            }
            System.out.print(str.charAt(i));
        }
    }
    public static int map(char curChar) {
        if (curChar >= 'a' && curChar <= 'z') {//如果是字符
            return curChar-87;//说明不可能是坏键了
        }
        else if(curChar == '_'){
            return 36;
        }
        else // 0-9 这几个字符
            return (int)curChar - 48;
    }
    public static char reverseMap(int number) {
        if (number >= 10 && number <= 35) {//如果是字符
            return (char)(number+87);//说明不可能是坏键了
        }
        else if(number == 36){
            return '-';
        }
        else // 0-9 这几个字符
            return (char)(number + 48);
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