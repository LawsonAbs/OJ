#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define maxn 1000

struct bookInfo{
	string id;
	string title;
	string author;
	string keyWord;
	string publisher;
	string year; 
};

struct bookInfo{
	string title;
	string author;
	string keyWord;
	string publisher;
	string year;
	int number; 
};


int main(){
	bookInfo book[maxn];
	bookInfo query[maxn];//��ѯ��� 
	int n,m;
	int i;
	
	scanf("%d",&n);
	getchar();//�Ե��س� 
	
	for(i = 0;i< n;i++){
		getline(cin,book[i].id); 
		getline(cin,book[i].title);
		getline(cin,book[i].author);
		getline(cin,book[i].keyWord);
		getline(cin,book[i].publisher);
		getline(cin,book[i].year);
	}

	scanf("%d",&m);//�����ѯ����
	getchar();
	
	for(i = 0;i< n;i++){
		getline(cin,query[i].title);
		getline(cin,query[i].author);
		getline(cin,query[i].keyWord);
		getline(cin,query[i].publisher);
		getline(cin,query[i].year);
	}
	
	
	for(i = 0;i< m;i++){//�Բ�ѯ���ַ������д��� 
		
		for(j = 0;j< 3;j++){
			query[i].title.erase(query[i].title.begin());
			query[i].author.erase(query[i].author.begin());
			query[i].keyWord.erase(query[i].keyWord.begin());
			query[i].publisher.erase(query[i].publisher.begin());
			query[i].year.erase(query[i].year.begin());
		} 
	}
	
	for(i = 0;i< m;i++){
		for(j = 0;j< n;j++){
			if(query[i].title == book[j].title)
				cout<<book[j].id<<endl;	
			
		}
				
	}
} 
/**
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found

ע
1.cin���ܿ��ƿո�����룬��cin�������ո�ʱ����һ������
2.c������ʹ��gets(),puts()�������������ַ��������ո񣩣�C++��ʹ��getline()���� 
*/

