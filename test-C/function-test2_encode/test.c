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

int main (void){
	
	char org_str[128];
	char encode_str[128] = {0};//配列の初期化
	int i ;
	
	printf("input original string : ");
	scanf("%s", org_str);
	
	//引数で指定すれば関数外スコープで扱えるみたい
	encode(org_str,encode_str);
	
	printf("original string %s\n",org_str);
	printf("original string %d\n",org_str);
	printf("encode string %s\n",encode_str);
	
	return 0 ;
}

/*実行結果
input original string : apple
original string apple
original string -1228533488
encode string bqqmf
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

