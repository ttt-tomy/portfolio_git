/* test.c */

#include <stdio.h>
#include <string.h>

int main (void){
	
	char org_str[] = "Apple";
	char encode_str[128] = {0};//配列の初期化
	int i ;
	
	//strlenはnullは数えてない模様
	for (i = 0 ; i < strlen(org_str) + 1 ; i++){
		if ((org_str[i] >= 'a') && (org_str[i] <= 'z')){
			//数字表記に1を加えて暗号化
			encode_str[i] = org_str[i] + 1;
		}else{
			//数字表記に1を加えずにそのまま代入(暗号化しない)
			encode_str[i] = org_str[i];
		}
	}

	
	printf("original string %s\n",org_str);
	printf("original string %d\n",org_str);
	printf("encode string %s\n",encode_str);
	
	return 0 ;
}

/*実行結果
original string Apple
original string 1316729744
encode string Aqqmf
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

