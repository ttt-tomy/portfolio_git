<?php
//エスケープ処理の関数
function h($var) {
  if(is_array($var)){
    //$varが配列の場合、h()関数をそれぞれの要素について呼び出す（再帰）
    return array_map('h', $var);
  }else{
    return htmlspecialchars($var, ENT_QUOTES, 'UTF-8');
  }
}
//入力値に不正なデータがないかなどをチェックする関数
function checkInput($var){
  //変数が配列であるか判定
  if(is_array($var)){
    //変数をバラし、それぞれにcheckInput関数処理
    return array_map('checkInput', $var);
  //バラしたからこっちが走る。
  }else{
    //NULLバイト攻撃対策
    if(preg_match('/\0/', $var)){
      //スクリプトの終了（メッセージあり）
      die('不正な文字が含まれています。');
    }//else echo 'フィルター通過<br>'; //動作テスト用
          //動作テスト
          //if(preg_match('/yyy/', $var)){
          //  die('テストyyy不通');
          //}else echo 'テストyyy通過<br>'; //動作テスト用
    //文字エンコードのチェック
    if(!mb_check_encoding($var, 'UTF-8')){ 
      die('不正なエンコードです。');
    }//else echo 'フィルター通過<br>'; //動作テスト用
    //改行、タブ以外の制御文字のチェック
    if(preg_match('/\A[\r\n\t[:^cntrl:]]*\z/u', $var) === 0){  
      die('不正な入力です。制御文字は使用できません。');
    }//else echo 'フィルター通過<br>'; //動作テスト用
    //変数を返す（誤動作抑止）
    return $var;
  }
}
?>