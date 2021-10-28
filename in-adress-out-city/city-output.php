<?php
$text = $_POST['adress'];
//第1引数：参照文字列、第2引数：開始位置、第3引数：抜き出す文字数
//開始位置は0始まり
$text3 = mb_substr($text , 2 ,1);
$text4 = mb_substr($text , 3 ,1);

//第1引数の中から、第2引数の場所を返す、なければfalseが返る。
if (mb_strpos("都道府県" , $text3) !== false){
  print mb_substr($text , 0 , 3);
}elseif ($text4 == "県") {
  print mb_substr($text , 0 , 4);
}else {
  print "都道府県名はありません";
}
?>
