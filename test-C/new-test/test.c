/* test.c */

//標準入出力を利用する為のヘッダファイル(ライブラリ)読み込み
#include <stdio.h>
#include <string.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	
	void drawLine1(int length){
		int i ;
		
		for(i= 0;i<length+2;i++){
			printf("+");
		}
		printf("\n");
	}
	
	
	void drawLine2(char str[]){
		printf("+");
		printf("%s",str);
		printf("+\n");
	}
	
	char str[128];
	int length;

	printf("文字列を入力してください");
	scanf("%s",str);
	length = strlen(str);
	
	drawLine1(length);
	drawLine2(str);
	drawLine1(length);
	
	return(0);
	
}

/*
実行結果

*/

/*
参考
フォーマット指定子とデータ型の一覧
https://k-cube.co.jp/wakaba/server/format.html
ヘッダファイル(ライブラリ)一覧
https://k-cube.co.jp/wakaba/server/head_top.html
ライブラリのリンクを忘れずに(コンパイル時) ※今回は-lm(link math)
https://qiita.com/percipere/items/678a8ec1299a7564f6a3
*/


