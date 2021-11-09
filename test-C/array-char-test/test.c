/* test.c */

#include <stdio.h>

int main (void){
	
	char org_str[] = "apple";
	char copy_str[128] = {0};//配列の初期化
	
	//null含めて1文字ずつ入ってる
	copy_str[0] = org_str[0];
	copy_str[1] = org_str[1];
	copy_str[2] = org_str[2];
	copy_str[3] = org_str[3];
	
	printf("original string %s\n",org_str);
	printf("copy string %s\n",copy_str);
	
	return 0 ;
}

/*実行結果
original string apple
copy string appl
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

