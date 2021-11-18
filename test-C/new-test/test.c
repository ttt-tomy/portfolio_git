/* test.c */

#include <stdio.h>
#include <string.h>

//function 特徴として以下の条件下を引数として利用
//関数内変数であり、関数外で使いたい変数 ← ※スコープの考え方がjavascriptと異る気がする
void encode (char org_str[],char encode_str[]){
	int i ;
		//nullもあるから注意
	for (i = 0 ; i < strlen(org_str) + 1 ; i++){
		if ((org_str[i] >= 'a') && (org_str[i] <= 'z')){
			if(org_str[i] == 'z'){
				encode_str[i] = 'a' ;
			}else{
				//数字表記に1を加えて暗号化
				encode_str[i] = org_str[i] + 1;
			}
		}else{
			//数字表記に1を加えずにそのまま代入(暗号化しない)
			encode_str[i] = org_str[i];
		}
	}
}
void decode (char en[],char dec[]){
	int i ;
	for (i = 0 ; i < strlen(en) + 1 ; i++){
		if ((en[i] >= 'a') && (en[i] <= 'z')){
			if(en[i] == 'a'){
				dec[i] = 'z' ;
			}else{
				dec[i] = en[i] - 1;
			}
		}else{
			dec[i] = en[i];
		}
	}
}

int main (void){
	
	char org_str[128];
	char encode_str[128] = {0};//配列の初期化
	char decode_str[128] = {0};
	int i ;
	
	printf("input original string : ");
	scanf("%s", org_str);
	
	//引数で指定すれば関数外スコープで扱えるみたい
	encode(org_str,encode_str);
	
	printf("original string %s\n",org_str);
	printf("original string %d\n",org_str);
	printf("encode string %s\n",encode_str);
	
	printf("input encode string : ");
	scanf("%s", encode_str);
	
	//引数の名前は同一にする必要はなく、また配列であるため記憶領域を共有しておりスコープを飛び越えている原理らしい
	decode(encode_str,decode_str);
	
	printf("encode string %s\n",encode_str);
	printf("encode string %d\n",encode_str);
	printf("decode string %s\n",decode_str);
	
	return 0 ;
}

/*実行結果
input original string : Apple
original string Apple
original string 1530903872
encode string Aqqmf
input encode string : Aqqmf
encode string Aqqmf
encode string 1530903744
decode string Apple
*/
//なんでマイナスなのかはわからんけどstring.hのライブラリを読み込んだか%dの返し方が変わったとかかな？

/*
参考
フォーマット指定子とデータ型の一覧
https://k-cube.co.jp/wakaba/server/format.html
ヘッダファイル(ライブラリ)一覧
https://k-cube.co.jp/wakaba/server/head_top.html
ライブラリのリンクを忘れずに(コンパイル時) ※今回は-lm(link math)
https://qiita.com/percipere/items/678a8ec1299a7564f6a3
*/

