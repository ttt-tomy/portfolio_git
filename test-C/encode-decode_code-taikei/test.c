/* test.c */

#include <stdio.h>
#include <string.h>

void encode (char org_str[],char encode_str[],int s,int w){//第4引数まで発行
	//sはシフトさせる数
	//wは全文字数 ※zまでの全文字数
	
	//今回の内容
	//元々の記述だと入力がzだった場合にif分岐させてaに変換してた
	//それだと可変シフトには対応できない
	//2個移動させる、3個移動させる、4個移動させる場合はどうする？
	//そこで今回の対応となる
	//全文字数で割るって方法 ※整数割り算
	//まずほぼ割れない、でそのままの数が余りとなる
	//ミソは最終間際
	//シフト数を足した数に対して割ると (if分で全文字数を超えた場合の処理でもいんちゃうかとも思うけど)
	//足した数分の余剰が余って出てくる
	//そいつ文字返還すればうまくいくよねって話し
	
	int i ;
	
	//入力文字数だけ繰り返す ※nullもあるから+1
	for (i = 0 ; i < strlen(org_str) + 1 ; i++){
		//a-zだった場合のみ適用
		if ((org_str[i] >= 'a') && (org_str[i] <= 'z')){
			//代入：入力文字から'a'を引いてシフト数足す、全文字数で割った余りに'a'を足す
			//例えば(25[y]-1[a]+3[shift])÷26 の余りが1、で1+1[a]=2、2がbやから3つ動いたねって
			//現段階では理論上での理解のみ(8章でここで使われている「コード体系」の内容に触れるとのこと)
			encode_str[i]=(org_str[i] - 'a' + s) % w + 'a';
		}else{
			//a-z以外いわゆるnullなどはそのまま代入
			encode_str[i] = org_str[i];
		}
	}
}
void decode (char encode_str[],char decode_str[],int s, int w){
	//encodeの関数がdecodeでも再利用できるみたい
	encode(encode_str,decode_str,w - s,w);//全文字数からシフト数を引く？、、あっ1周して戻って来いってことか(余りで変換してるから出来るワザやなw)
}

int main (void){
	
	char org_str[128];
	char encode_str[128] = {0};
	char decode_str[128] = {0};
	int s = 2;//シフトする文字数(入力ちゃうんけwまぁいいか...)
	int w = 'z' - 'a' + 1 ;//理論上はわかったけどzだけじゃあかんねやろか？(8章で学ぶ)
	
	
	printf("input original string : ");
	scanf("%s", org_str);
	printf("original string %s\n",org_str);
	//引数で指定すれば関数外スコープで扱えるみたい
	encode(org_str,encode_str,s,w);
	printf("encode string %s\n",encode_str);
	
	decode(encode_str,decode_str,s,w);
	printf("decode string %s\n",decode_str);
	
	
	return 0 ;
}

/*実行結果
original string abc
encode string cde
decode string abc
*/
//いまのところ理論上の理解、8章のコード体系で詳細を

/*
参考
フォーマット指定子とデータ型の一覧
https://k-cube.co.jp/wakaba/server/format.html
ヘッダファイル(ライブラリ)一覧
https://k-cube.co.jp/wakaba/server/head_top.html
ライブラリのリンクを忘れずに(コンパイル時) ※今回は-lm(link math)
https://qiita.com/percipere/items/678a8ec1299a7564f6a3
*/

