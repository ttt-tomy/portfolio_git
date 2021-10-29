/* test.c */

//標準入出力を利用する為のヘッダファイル(ライブラリ)読み込み
#include <stdio.h>
#include <string.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	
	//返り値指定なしの関数発行
	//実行内容をそのまま返してる模様
	//voidの箇所を変えればデータ型が指定できるのかな？
	void drawLine(int length){//関数の引数を","で区切って複数利用することも可能(関数の第1引数,第2...)
		int i ;
		//引数(入力文字数)プラス2回分指定記号を繰り返す
		for(i= 0;i<length+2;i++){
			printf("+");
		}
		printf("\n");
	}
	
	//引数なしの関数も発行できる
	void Line(void){
		printf("-----------\n");
	}
	
	//返り値なしの関数発行
	void sideDecoration(char str[]){//引数に配列の文字列を指定※仮変数の場合は[]内不要
		//引数(文字列)を指定記号で囲う
		printf("+");
		printf("%s",str);
		printf("+\n");
	}
	
	char str[128];//7bitと関係ありそう...ASCII?
	int length;

	printf("文字列を入力してください");
	//入力
	scanf("%s",str);
	//str文字数を代入
	length = strlen(str);
	
	drawLine(length);
	sideDecoration(str);
	drawLine(length);
	Line();
	
	return(0);
	
}

/*
実行結果
[root@localhost new-test]# ./a.out
文字列を入力してくださいaaa
+++++
+aaa+
+++++
-----------
[root@localhost new-test]# ./a.out
文字列を入力してくださいあああ
+++++++++++
+あああ+
+++++++++++
-----------
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


