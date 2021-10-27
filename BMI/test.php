<?php
$x = hyouzyun(175);
print "標準体重は" . $x . "kgです";
//ブラウザ入力なしの理由：サーバー処理だからセキュリティフィルタもいれなあかん

function hyouzyun($s){
  $sc = $s /100;
  //roundで四捨五入の指定(第二引数が小数点以下の指定数)
  return round($sc * $sc * 22, 1);
}
?>
