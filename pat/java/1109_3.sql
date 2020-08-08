import java.util.*;

public class Main {
    private static Map<String, Integer> student = new HashMap<String, Integer>();
    private static List<Map.Entry<String, Integer>> lists ;
    private static Stack<String> stack = new Stack<String>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int totalNumber = in.nextInt();//总人数
        int lineNumber = in.nextInt();//每行的人数
        in.nextLine();

        String line[];
        String name;
        int height;

        for (int i = 0; i < totalNumber; i++) {
            line = in.nextLine().trim().split(" ");
            name = line[0];
            height = Integer.parseInt(line[1]);
            student.put(name, height);
        }

        lists = new ArrayList<Map.Entry<String, Integer>>(student.entrySet());
        sort();
        for(int j = 0;j < lists.size();j++) {
              System.out.println(lists.get(j));
        }

        //lineNumber 表示的是每行站队的人数
        //List<Map.Entry<String, Integer>> rows = new ArrayList<>();
        int rowNumber = totalNumber / lineNumber;

        //这个result 是用于保存每行的站队人数的姓名
        //但是不能用lineNumber 作为数组大小，因为可能会导致数组溢出
        String[] result = new String[lineNumber*2];

//==============================================================第一行==============================================
        int position = 0; //表示每个人的下标
        int rest = totalNumber % lineNumber + lineNumber; // 最后一行站队的人数
        for(int j= rest - 1;j > 0 ;j-=2) { //从左往右添加
            System.out.print("position = " + position);
            System.out.println("lists.get(j).getKey() = "+lists.get(j).getKey());
            result[position] = lists.get(j).getKey(); //将姓名添加到其中
            position ++;
        }

        position = rest - 1 ;//reset -> 因为这个是从位置1开始存放
        for(int j= rest - 2 ; j > 0  ;j-=2) { //从左往右添加
            System.out.print("position = " );
            System.out.println( position);
            System.out.println("lists.get(j).getKey() = "+lists.get(j).getKey());
            result[position] = lists.get(j).getKey(); //将姓名添加到其中
            position --;
        }

        //System.out.println("最高个："+ lists.get(rest-1).getKey());
        result[rest/2] = lists.get(0).getKey();
        //每行的站队排好之后 就输出
        for(int k = 0;k < result.length;k++) { // invalid null
            if (result[k] == null) {
                System.out.println();//输出换行
                stack.push("\n");
                break;
            }
            if (result[k+1] != null) {
                System.out.print(result[k] + " ");
                stack.push(result[k] + " ");
            } else {
                System.out.print(result[k]);
                stack.push(result[k]);
            }
        }

        int j = 0;
        while(j< rest) {
            System.out.println("待删除的list是："+lists.get(0));
            lists.remove(0);//删除前 lineNumber 个元素
            j++;
        }

        System.out.println(".........剩下的lists......");
        for(j = 0;j < lists.size();j++) {
            System.out.println(lists.get(j));
        }


//==============================        这个循环是用于找出每行的站队人数 => 但是不包括最后一行==============================================
        //因为上面的结果对后面的计算可能有污染，所以需要重置结果
        for(int i = 0;i< result.length;i++) {
            result[i] = null;
        }

        for(int i = 0;i < rowNumber - 1 ;i++) {
            position = 0; //表示每个人的下标
            for(j= lineNumber -1;j>0 ;j-=2) { //从左往右添加
                System.out.print("position = " + position);
                System.out.println("lists.get(j).getKey() = "+lists.get(j).getKey());
                result[position] = lists.get(j).getKey(); //将姓名添加到其中
                position ++;
            }

            position = lineNumber - 1 ;//reset -> 因为这个是从位置1开始存放
            for( j=  lineNumber-2;j > 0 ;j-=2) { //从左往右添加
                System.out.print("position = " );
                System.out.println( position);
                System.out.println("lists.get(j).getKey() = "+lists.get(j).getKey());
                result[position] = lists.get(j).getKey(); //将姓名添加到其中
                position --;
            }

            //System.out.println("最高个："+ lists.get(lineNumber-1).getKey());
            result[lineNumber/2] = lists.get(0).getKey();
            //每行的站队排好之后 就输出
            for(int k = 0;k < result.length;k++) { // invalid null
                if (result[k] == null) {
                    System.out.println();//输出换行
                    stack.push("\n");
                    break;
                }
                if (result[k+1] != null) {
                    System.out.print(result[k] + " ");
                    stack.push(result[k] + " ");
                } else {
                    System.out.print(result[k]);
                    stack.push(result[k] );
                }
            }

             j = 0;
            while(j< lineNumber) {
                System.out.println("待删除的list是："+lists.get(0));
                lists.remove(0);//删除前 lineNumber 个元素
                j++;
            }

            //System.out.println("再次打印lists...");
            for(j = 0;j < lists.size();j++) {
                System.out.println(lists.get(j));
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
                    status = (o1.getKey().compareTo(o2.getKey())) ;
                }
                return -1 * status; //降序排序
            }
        });
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


4 4
Tom 188
Bob 175
Nick 186
Joe 190
*/