<?php
//24時間表示で時間を取得
$t = date("G");
if ($t < 6 or $t >= 18) {
  print "<body bgcolor = gray>
    <p>夜</p>
  </body>";
}elseif ($t >= 9) {
  print "<body bgcolor = lime>
    <p昼</p>
  </body>";
} elseif ($t >= 6) {
  print "<body bgcolor = blue>
    <p朝</p>
  </body>";
}
?>
