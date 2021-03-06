/* test.c */

//printfなどを扱うためのファイル読み込み
#include <stdio.h>
//exitを使うためのファイル読み込み
#include <stdlib.h>
//再入力で回す仕様にしたので使わなかったが、returnで定義した関数の終了、exitでプログラム自体の終了とスコープに違いがあることがわかった。

//functionは、使えない模様(戻り値ありは型名を、戻り値なしはvoidらしい)
//これで関数作成できる。あっ...下と同じか...
//mainが優先的に実行され、定義関数は順不同だが、先に使うより前に記述するのが通例のよう
int filter(int xx){
	int error; //変数の発行
	if(xx <= 0){
		printf("正の数で入力してください\n");
		error = 1 ;
	}else{
		error = 0 ;
	}
	return error ;
}
int even_n(int yy){
	int error; //変数の発行
	if(yy % 2){
		printf("偶数で入力してください\n");
		error = 1 ;
	}else{
		error = 0 ;
	}
	return error ;
}

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	//整数型の配列a,整数型の変数i,整数型の公差differenceを宣言
	int i , sum , sumleg , sumlegx , turu , kame , xx , error , error2 , anser;
	
	printf("鶴と亀の合計匹数を入力してください\n");
	scanf("%d",&sum);
	//フィルターをエラーでなくなるまで回す。forの第3引数はなくてもコンパイル可能
	for(error = 1 ; error != 0 ;){
		//整数フィルター
		error = filter(sum);//返り値を代入(実行して代入してる模様、中身のprintfも出力される。)
		if(error != 0 )scanf("%d",&sum);
	}
	printf("鶴と亀の合計の足の数を入力してください\n");
	scanf("%d",&sumleg);
	for(error = 1 ; error != 0 ;){
		//整数フィルター
		error = filter(sumleg);
		//偶数フィルター
		error2 = even_n(sumleg);
		if(error != 0 || error2 != 0)scanf("%d",&sumleg);
	}
	anser = 0 ;
	for(i = 0 ; i <= sum ; i++){
		turu = i ;//iをなくしてturuにしてコード短縮可能
		kame = sum - i ;
		sumlegx = 2 * turu + 4 * kame ;
		if(sumlegx == sumleg){
			printf("鶴の数は、%dです。亀の数は、%dです。\n",turu,kame);
			anser = 1 ;
		}
	}
	if(anser == 0)printf("その組み合わせの解はありません\n");
	
	return 0 ;
}

/*
実行結果
[root@localhost new-test]# ./a.out
鶴と亀の合計匹数を入力してください
-5
正の数で入力してください
-5
正の数で入力してください
5
鶴と亀の合計の足の数を入力してください
-16
正の数で入力してください
-15
正の数で入力してください
偶数で入力してください
15
偶数で入力してください
16
鶴の数は、2です。亀の数は、3です。
[root@localhost new-test]# ./a.out
鶴と亀の合計匹数を入力してください
40
鶴と亀の合計の足の数を入力してください
60
その組み合わせの解はありません
*/


