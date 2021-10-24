/* prog0204.c */

//printfなどを扱うためのファイル読み込み
#include <stdio.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	int speed = 300000; //int:整数を扱うデータ型の宣言
	int distance = 150000000;
	int time; //代入なしで変数作成可能

	printf("%d\n",time); //初期化子なし場合の値確認
	
	time = distance / speed ; //データ型の宣言は変数発行時のみ
	printf("%d\n",time); // %d:10進数(Decimal) /n:改行

	return 0 ;
}

/*実行結果*/
/*32767*/
/*500*/
