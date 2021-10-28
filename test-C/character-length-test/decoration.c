/* decoration.c */

//printfなどを扱うためのファイル読み込み
#include <stdio.h>
#include <string.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	
	char str[128];
	int i , length ;
	
	printf("文字列を入力してください\n");
	scanf("%s",str); //文字列のinputは&が必要ない
	printf("↓入力された文字\n");
	printf("%s\n",str);
	printf("↓文字のバイト数\n");
	printf("%d\n",(int)strlen(str)); //int型にキャスト
	
	length = strlen(str); //キャストせずにint型の変数に代入する方法
	
	for(i=0;i<length+2;i++)printf("+");
	printf("\n");
	
	printf("+");
	printf("%s",str);
	printf("+\n");
	
	for(i=0;i<length+2;i++)printf("+");
	printf("\n");
	
	return 0 ;
}

/*
フォーマット指定子とデータ型の一覧
https://k-cube.co.jp/wakaba/server/format.html
*/

/*
実行結果
[root@localhost character-length-test]# ./a.out
文字列を入力してください
aaa
↓入力された文字
aaa
↓文字のバイト数
3
+++++
+aaa+
+++++
[root@localhost character-length-test]# ./a.out
文字列を入力してください
あああ
↓入力された文字
あああ
↓文字のバイト数
9
+++++++++++
+あああ+
+++++++++++
*/


