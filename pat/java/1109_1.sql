import java.util.*;

public class Main {
    private static Map<String, Integer> student = new HashMap<String, Integer>();
    private static List<Map.Entry<String, Integer>> lists ;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int totalNumber = in.nextInt();//总人数
        int lineNumber = in.nextInt();//每行的人数
        System.out.println("total Number = " + totalNumber + ", lineNumber = " + lineNumber);
        in.nextLine();

        String line[];
        String name;
        int height;

        for (int i = 0; i < totalNumber; i++) {
            line = in.nextLine().trim().split(" ");
            name = line[0];
            height = Integer.parseInt(line[1]);
            //System.out.println("name = " + name + ", height = " + height);
            student.put(name, height);
        }
//        System.out.println("student.size = " + student.size());

        lists = new ArrayList<Map.Entry<String, Integer>>(student.entrySet());
        sort();
        for(int i = 0;i < lists.size();i++) {
            System.out.println(lists.get(i));
        }

        //lineNumber 表示的是每行站队的人数
        //List<Map.Entry<String, Integer>> rows = new ArrayList<>();
        int rowNumber = totalNumber / lineNumber;
       // System.out.println("需要站成 "+rowNumber+" 行");

        //这个result 是用于保存每行的站队人数的姓名
        //但是不能用lineNumber 作为数组大小，因为可能会导致数组溢出
        String[] result = new String[lineNumber*2];

        //这个循环是用于找出每行的站队人数
        for(int i = 0;i < rowNumber ;i++) {
            int position = 0; //表示每个人的下标
            for(int j= 0;j< lineNumber -1 ;j+=2) { //从右往左添加
                System.out.print("rowNumber - 1 - position = " );
                System.out.println( lineNumber - 1 - position);
                System.out.println("lists.get(j).getKey() = "+lists.get(j).getKey());
                result[lineNumber - 1 - position] = lists.get(j).getKey(); //将姓名添加到其中
                position += 2;
            }

            position = 1;//reset -> 因为这个是从位置1开始存放
            for(int j= 1;j< lineNumber-1 ;j+=2) { //从左往右添加
                System.out.print("position = " );
                System.out.println( position);
                System.out.println("lists.get(j).getKey() = "+lists.get(j).getKey());

                result[position] = lists.get(j).getKey(); //将姓名添加到其中
                position += 2;
            }
            
            System.out.println("最高个："+ lists.get(lineNumber-1).getKey());
            result[lineNumber/2] = lists.get(lineNumber-1).getKey();
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
            while(j< lineNumber) {
                //System.out.println("待删除的list是："+lists.get(0));
                lists.remove(0);//删除前 lineNumber 个元素
                j++;
            }

            System.out.println("再次打印lists...");
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
                    status = o1.getKey().compareTo(o2.getKey());
                }
                return status;
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
*/