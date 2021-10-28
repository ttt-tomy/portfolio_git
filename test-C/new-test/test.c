/* test.c */

//標準入出力を利用する為のヘッダファイル(ライブラリ)読み込み
#include <stdio.h>
//三角関数など数学系を利用する為のヘッダファイル(ライブラリ)読み込み
//ライブラリ変数にM_PI(π)がいる模様
//コンパイル時にライブラリリンクオプションが必要
#include <math.h>

int main (void){ //main:メイン関数の意味らしい void:空の意味(引数)
	
	printf("%f\n",sin(0));
	//sin関数の返り値はdouble型、引数はラジアン(弧度法)で指定する
	//%fは実数、倍精度実数の%lfでも良いような気がする（処理速度の問題だろうか)
	
	int i ;
	
	printf("%s","M_PI(%f指定)は、");
	printf("%f\n",M_PI);
	printf("%s","M_PI(%lf指定)は、");
	printf("%lf\n",M_PI);
	
	for(i=0;i<91;i++){
		printf("%2d° %f\n",i,sin(i*M_PI/180));
		//%2dの2は二桁桁枠指定の2
	}
	
	return(0);
	
}

/*
実行結果
0.000000
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


