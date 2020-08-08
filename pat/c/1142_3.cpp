#include <iostream>
#include <vector>
using namespace std;
int e[210][210];
int main() {
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;//表明这两个顶点之间有边 
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        vector<int> v(k);//这是几个意思？ 
        int hash[210] = {0}, isclique = 1, isMaximal = 1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;//hash[v[j]]=1 表明的是当前检测的顶点是1
        }
        for (int j = 0; j < k; j++) {
            if (isclique == 0) break;
            //这里并没有让 l=0开始，而是从 j+1 开始 
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {//等于0 说明两个顶点不连通 
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        
        //注意这里的外层循环是 j，意思就是查找 任一图节点和查询的k个节点是否存在相邻
		//只要有一个 e[v[l][j]] !=0 ，都会break出去；
		//如果都是每一个都 e[v[l][j]] !=0 ，则会使 l==k-1成立，然后输出Not Maximal 
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {//这里检测是不在当前出现的顶点 集 
                for (int l = 0; l < k; l++) {//判断输入的 k 个节点和图的顶点 是否存在连通边 
                    if (e[v[l]][j] == 0) break;
                    if (l == k - 1) isMaximal = 0;
                }
            }
            if (isMaximal == 0) {
                printf("Not Maximal\n");
                break;
            }
        }
        if (isMaximal == 1) printf("Yes\n");
    }
    return 0;
}

