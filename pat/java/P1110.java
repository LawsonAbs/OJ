import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class P1110 {
    public static void main(String[] args) throws IOException {
        int [][] tree =new int[30][2];//用于存储每个节点下的子节点编号  => 一个二维数组
        //建议这个使用int 型二维数组存储，如果不使用int 型，则在后面进行转换时就比较麻烦

        String c = "-";
        Reader.init(System.in);
        int nodeNum = Reader.nextInt();

        //System.out.println("节点数是："+nodeNum);
        for(int i = 0;i< nodeNum;i++) {
            for(int j = 0; j< 2;j++) {
                c = Reader.next(); //问题的根源 => 可能这个下标不仅仅是一位数
                //System.out.println("c = "+c);
                if (!c.equals("-")) {
                    //System.out.println("Integer.valueOf(c) = "+Integer.valueOf(c));
                    tree[i][j] = Integer.valueOf(c) ; // get the number
                }
                else{ tree[i][j] = -1 ;}
            }
        }

//        for(int i = 0;i < 9;i++) {
//            System.out.print("node "+i+": ");
//            for(int j = 0;j < 2;j++) {
//                System.out.print(tree[i][j]+" ");
//            }
//            System.out.println();
//        }
        int root = 0;
        if (nodeNum == 1) {
            root = 0;
            System.out.println("YES 0");
            System.exit(0);//直接退出
        } else {
            //找出根节点
            //array[] = -2 表示的是根节点
            int array[] = new int[nodeNum];
            //初始化一遍
            for(int i = 0;i< nodeNum;i++) {
                array[i] = -2;
            }
            for(int i = 0;i< nodeNum;i++ ) {
                for(int j = 0;j < 2;j++) {
                    if (tree[i][j] == -1) {
                        array[i] = i;
                    } else {
                        array[tree[i][j]] = tree[i][j];
                    }
                }
            }
            for(int i = 0;i<nodeNum;i++) {
                if (array[i] == -2) {
                    root = i;//get the value of root
                    //System.out.println("root :"+ i);
                }
            }
        }

        //=================================================================
        //接下来就是针对root 开始遍历整个二叉树，判断是否是完整二叉树
        Queue<Integer> queue = new LinkedList<>();
        queue.add(root);
        int leftNode ;
        int rightNode;

        int tempRoot = 0;
        int lastNode = 0;
        while (!queue.isEmpty()) {
            tempRoot = queue.peek(); //队首元素
            //System.out.println("tempRoot = "+tempRoot);
            leftNode = tree[tempRoot][0]; // 得到根节点的左节点
            rightNode = tree[tempRoot][1]; // 得到根节点的左节点
            if (leftNode == -1 && rightNode != -1) { //有右节点，但是没有左节点  => 肯定不是完全二叉树
                System.out.println("NO "+root);
                System.exit(0);
            }

            //如果有左右子节点均为空，或者左子树不为空，但是右子树为空
            // 则需要遍历queue 中之后的所有的节点，判断是不是完全二叉树
            if ((leftNode == -1 && rightNode == -1) || (leftNode != -1 && rightNode == -1)) {
                if(leftNode!=-1){
                    queue.add(leftNode);
                }
                if(rightNode!=-1){
                    queue.add(rightNode);
                }

                queue.poll(); //先将队首移出，然后接着比较队首之后的元素
                while (!queue.isEmpty()) {//遍历检查是否还有节点存在子节点
                    tempRoot = queue.peek(); //队首元素
                    leftNode = tree[tempRoot][0]; // 得到根节点的左节点
                    rightNode = tree[tempRoot][1]; // 得到根节点的左节点
                    if (leftNode != -1 || rightNode != -1) {//说明还有子节点
                        System.out.println("NO "+root);
                        System.exit(0);
                    }
              //      System.out.println("队首元素是： "+queue.peek());
                    lastNode = tempRoot;
                    queue.poll(); //
                }
            }
            if(leftNode!=-1){
                queue.add(leftNode);
            }
            if(rightNode!=-1){
                queue.add(rightNode);
            }
            //System.out.println("队首元素是： "+queue.peek());
            queue.poll();
            lastNode = tempRoot;
        }
        System.out.println("YES "+lastNode);
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

/* 注意这里在John 159之后有一个换行。
9
7 8
- -
- -
- -
0 1
2 3
4 5
- -
- -



8
- -
4 5
0 6
- -
2 3
- 7
- -
- -

8
- -
4 5
0 6
- -
2 3
7 -
- -
- -




1
- -


3
- 1
- 2
- -

2
- 1
- -

4
3 1
2 -
- -
- -



4
1 2
- -
3 -
- -


5
1 2
4 -
3 -
- -
- -



6
1 2
4 5
3 -
- -
- -
- -
*/