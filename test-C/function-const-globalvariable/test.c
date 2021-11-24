/*text.c*/
/*EBCDICコードなど数字扱いで順番に増やせない場合のエンコードの例*/

#include <stdio.h>
#include <string.h>

//constだと書き換え防止になる
//ここで変数を作るとグローバル変数となる
const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
//char だから1文字ずつ代入されてるのか

//int型を返すsearch関数 ※関数定義(function)
int search(int ch ,int w ){
	int i ;
	int find = -1;
	
	//回してみてifにかからなければ-1を返すってこと
	for(i = 0; i<w ; i++){
		if(alphabet[i]==ch){
			find = i ;
			break;
		}
	}
	return find ;
}

//空返りの関数定義
void encode (char org_str[],char encode_str[],int s,int w){
	int i ;
	int find ;
	
	for(i = 0; i< strlen(org_str) + 1 ; i++){
		find = search(org_str[i],w);
		//-1が帰ってる場合
		if(find < 0){
			//そのままの文字を代入
			encode_str[i] = org_str[i];
		//-1じゃない場合(対象文字の場合)
		}else{
			//シフト分動かしたalphabetの中身を代入 ※跨ぎシフトは1周させるのでw割の余りを利用
			encode_str[i] =alphabet[(find + s) % w];
		}
	}
}

void decode(char encode_str[],char decode_str[],int s,int w){
	//シフト分マイナスした1周分で、グルっと戻す
	encode(encode_str,decode_str,w -s,w);
}

int main (void){
	char org_str[128];
	char encode_str[128] = {0};
	char decode_str[128] = {0};
	int s = 2 ;
	int w ;
	
	//全文字数の代入
	w = strlen(alphabet);
	
	printf("input original string : ");
	scanf("%s",org_str);
	
	printf("original string %s\n",org_str);
	
	encode(org_str,encode_str,s,w);
	printf("encode string %s\n",encode_str);
	
	decode(encode_str,decode_str,s,w);
	printf("decode string %s\n",decode_str);
	
	return 0;
}

/*実行結果
input original string : abc
original string abc
encode string cde
decode string abc*/

