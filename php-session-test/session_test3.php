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

print "確認のためのセッションが開始されたため、ここではセッションを自動終了します<br>";
session_destroy();
$_SESSION = array();
//setcookie(Cookieの名前,保管する値,有効期限,Cookieを有効にするパス);
setcookie("PHPSESSID","",TIME() - 3600,"/");
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
<button onclick="location.href='session_test.php'">再度セッションを開始</button>
</body>
</html>