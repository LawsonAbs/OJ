#include <iostream>
#include <vector>
using namespace std;
int e[210][210];
int main() {
    int nv, ne, m, ta, tb, k;
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        scanf("%d %d", &ta, &tb);
        e[ta][tb] = e[tb][ta] = 1;//��������������֮���б� 
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        vector<int> v(k);//���Ǽ�����˼�� 
        int hash[210] = {0}, isclique = 1, isMaximal = 1;
        for (int j = 0; j < k; j++) {
            scanf("%d", &v[j]);
            hash[v[j]] = 1;//hash[v[j]]=1 �������ǵ�ǰ���Ķ�����1
        }
        for (int j = 0; j < k; j++) {
            if (isclique == 0) break;
            //���ﲢû���� l=0��ʼ�����Ǵ� j+1 ��ʼ 
            for (int l = j + 1; l < k; l++) {
                if (e[v[j]][v[l]] == 0) {//����0 ˵���������㲻��ͨ 
                    isclique = 0;
                    printf("Not a Clique\n");
                    break;
                }
            }
        }
        if (isclique == 0) continue;
        
        //ע����������ѭ���� j����˼���ǲ��� ��һͼ�ڵ�Ͳ�ѯ��k���ڵ��Ƿ��������
		//ֻҪ��һ�� e[v[l][j]] !=0 ������break��ȥ��
		//�������ÿһ���� e[v[l][j]] !=0 �����ʹ l==k-1������Ȼ�����Not Maximal 
        for (int j = 1; j <= nv; j++) {
            if (hash[j] == 0) {//�������ǲ��ڵ�ǰ���ֵĶ��� �� 
                for (int l = 0; l < k; l++) {//�ж������ k ���ڵ��ͼ�Ķ��� �Ƿ������ͨ�� 
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

