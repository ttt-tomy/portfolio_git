/* prog0207.c */

//printfなどを扱うためのファイル読み込み
#include <stdio.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	int speed ;
	int distance ;
	int time ;
	int min ;
	int sec ;
	
	//キーボードからの入力
	printf("所要時間を算出します。\n");
	printf("速度(km/秒),距離(km)の順で入力してください。(半角)\n"); //これの改行方法と
	scanf("%d%d",&speed,&distance);
/*	printf("%s\n","距離を入力してください。(km | 半角)"); //これの改行方法は同じ結果だった %sが文字列の入力フォーマット指定子 ※なしだと何も表示されない*/
/*	scanf("%d",&distance); //&は、割り当ての意味*/
	
	time = distance / speed ; //データ型の宣言は変数発行時のみ
	
	min = time/60 ; //intで発行した変数であり、intは(小数点以下切り捨ての)整数のデータ型であるため小数点以下切り捨て
	sec = time%60 ; //余りを求めるのはいつも通りの"%"
	
	printf("所要時間は、");
	printf("%d",time); // %d:10進数(Decimal) /n:改行
	printf("%s","秒です。");
	printf("(");
	printf("%d",min);
	printf("分");
	printf("%d",sec);
	printf("%s\n","秒)");
	//こうゆう書き方も可能
	printf("所要時間は、%d秒です。(%d分%d秒)←構文を変えたバージョン\n",time,min,sec);

	return 0 ;
}
