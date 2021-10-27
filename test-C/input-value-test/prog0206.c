/* prog0206.c */

//printfなどを扱うためのファイル読み込み
#include <stdio.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	int speed = 300000; //int:整数を扱うデータ型の宣言
	int distance ;
	int time ; //代入なしで変数作成可能
	
	//キーボードからの距離の入力
	printf("距離を入力してください。(半角)"); 
	scanf("%d",&distance); //&は、変数を取ってくる意味
	
	time = distance / speed ; //データ型の宣言は変数発行時のみ
	printf("%d\n",time); // %d:10進数(Decimal) /n:改行

	return 0 ;
}
