<?php
session_start();
print "セッションを開始しました<br>";
print "セッション名は" . session_name() . "<br>";
print "セッションIDは" . session_id() . "<br>";
print "セッション変数は" . "<br>";
print_r ($_SESSION);
print "<br>";
print "Cookieのセッション情報を表示します<br>";
//セッションIDがブラウザのクッキーに登録されている。
print $_COOKIE["PHPSESSID"];
print "<br>";
if(!isset($_SESSION["acsses-count"])){
   $_SESSION["acsses-count"] = 1 ;
}else{
   $_SESSION["acsses-count"]++;
}
print "アクセス回数は" . $_SESSION["acsses-count"];
?>

<!DOCTYPE html>
<html lang="ja">
<head>
   <meta charset="utf-8">
   <meta name="Description" content="" />
   <meta name="Keywords"  content="" />
<title></title>
</head>
<body>
<br>
<br>
<button onclick="location.href='session_test2.php'">セッションの終了</button>
</body>
</html>