import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static Map<String, Integer> student = new HashMap<String, Integer>();
    private static List<Map.Entry<String, Integer>> lists ;

    public static void main(String[] args) throws IOException {
        Reader.init(System.in);
        int totalNumber = Reader.nextInt();//总人数
        int lineNumber = Reader.nextInt();//每行的人数

        String name;
        int height;

        for (int i = 0; i < totalNumber; i++) {
            name = Reader.next();
            height = Integer.parseInt(Reader.next());
            //System.out.println("name="+name+","+height);
            student.put(name, height);
        }

        lists = new ArrayList<Map.Entry<String, Integer>>(student.entrySet());
        sort();

        //lineNumber 表示的是每行站队的人数
        //List<Map.Entry<String, Integer>> rows = new ArrayList<>();
        int rowNumber = totalNumber / lineNumber;

        //这个result 是用于保存每行的站队人数的姓名
        //但是不能用lineNumber 作为数组大小，因为可能会导致数组溢出
        String[] result = new String[lineNumber*2];

//==============================================================第一行==============================================
        int rest = totalNumber % lineNumber + lineNumber; // 最后一行站队的人数
        int position = rest / 2 ; //表示每个人的下标 + 初始化值
        //System.out.println("最高个："+ lists.get(rest-1).getKey());
        result[rest/2] = lists.get(0).getKey(); //最高者的位置

        for(int j = 1 ; j < rest  ;j += 2) { //从左往右添加
            position -= 1; //往前移一个下标
            result[position] = lists.get(j).getKey(); //将姓名添加到其中
        }

        position = rest / 2 ;//reset
        for(int j = 2 ; j < rest  ;j += 2) { //从左往右添加
            position ++;
            result[position] = lists.get(j).getKey(); //将姓名添加到其中
        }

        //每行的站队排好之后 就输出
        for(int k = 0;k < result.length;k++) { // invalid null
            if (result[k] == null) {
                System.out.println();//输出换行
                break;
            }
            if (result[k+1] != null) {
                System.out.print(result[k] + " ");
            } else {
                System.out.print(result[k]);
            }
        }

        int j = 0;
        while(j< rest) {
            lists.remove(0);//删除前 lineNumber 个元素
            j++;
        }

//==============================        这个循环是用于找出每行的站队人数 => 但是不包括最后一行==============================================
        //因为上面的结果对后面的计算可能有污染，所以需要重置结果
        for(int z = 0;z< result.length;z++) {
            result[z] = null;
        }

        for(int i = 0;i < rowNumber - 1 ;i++) {
            result[lineNumber/2] = lists.get(0).getKey();

            position = lineNumber/2;
            for(j = 1;j < lineNumber ;j += 2) { //从左往右添加
                position --;
                result[position] = lists.get(j).getKey(); //将姓名添加到其中
            }

            position = lineNumber / 2 ;//reset -> 因为这个是从位置1开始存放
            for( j = 2;j < lineNumber ;j += 2) { //从右往左添加
                position ++;
                result[position] = lists.get(j).getKey(); //将姓名添加到其中
            }

            //每行的站队排好之后 就输出
            for(int k = 0;k < result.length;k++) { // invalid null
                if (result[k] == null) {
                    System.out.println();//输出换行
                    break;
                }
                if (result[k+1] != null) {
                    System.out.print(result[k] + " ");
                } else {
                    System.out.print(result[k]);
                }
            }

            j = 0;
            while(j< lineNumber) {
              //  System.out.println("待删除的list是："+lists.get(0));
                lists.remove(0);//删除前 lineNumber 个元素
                j++;
            }
        }
    }

    //根据height and name 排序
    public static void sort() {
        Collections.sort(lists, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                int status = o1.getValue().compareTo(o2.getValue()) ;
                if (status == 0) {
                    status =  -1 * (o1.getKey().compareTo(o2.getKey())) ;
                }
                return -1 * status; //降序排序
            }
        });
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
}

/* 注意这里在John 159之后有一个换行。
10 3
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159


10 3
Tom 188
Mike 170
Eva 168
Tim 158
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159



10 4
Tom 188
Mike 170
Eva 168
Tim 160
Joe 190
Ann 168
Bob 175
Nick 186
Amy 160
John 159




3 3
Tim 160
Amy 160
John 159


3 3
Mike 170
Eva 168
Ann 168

3 3
Mike 170
Eva 170
Ann 168


4 3
Tom 188
Bob 175
Nick 186
Joe 190
*/