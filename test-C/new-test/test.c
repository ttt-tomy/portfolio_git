/* test.c */

#include <stdio.h>

int main (void){
	
	char org_str[] = "apple";
	char copy_str[128];
	
	printf("original string %s\n",org_str);
	printf("copy string %s\n",copy_str);
	
	return 0 ;
}

/*実行結果
original string apple
copy string 
→資料によるとデタラメな値が表示されるようだが、何も表示されなかった。
  他テストして変数を読みに行っているのは確認できた、よって中身がない模様

//char copy_str[128]; → char copy_str[128]="aaa";
original string apple
copy string aaa
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

