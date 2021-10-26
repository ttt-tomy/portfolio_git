<?php
for ($i=1; $i <= 5 ; $i++) {
  print "<h4>"."$i"."回目</h4>";
    //0～2のどれか(ランダム)を代入する
    $n = rand(0,2);
    if ($n == 0) {
      print "勝ち</br>";
    }elseif ($n == 1) {
      print"あいこ</br>";
    }else {
      print "負け</br>次がんばってね！</br><a href=\"./\">再挑戦する</a>";
      break;
    }
    if ($i == 5) {
      print "<font color = red>おめでとう！！！！！！！</br>一度も負けなかったぞ！！！！！</br>クリアぁぁぁぁぁーーーー！！！！</font>";
    }
  }
?>
