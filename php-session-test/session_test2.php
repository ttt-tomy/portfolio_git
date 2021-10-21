<?php
session_start();
print "セッションを開始しました<br>";
print "設定されたセッションのデータを表示します<br>";
print_r($_SESSION);
print "<br>クリア処理以前のCookieのセッション情報を表示します<br>";
print $_COOKIE["PHPSESSID"] . "<br>";
print "ここではセッションを終了します<br>";
session_destroy();
$_SESSION = array();
//setcookie(Cookieの名前,保管する値,有効期限,Cookieを有効にするパス);
setcookie("PHPSESSID","",TIME() - 3600,"/");
print "セッションを終了し、セッション変数とブラウザ側のクッキーをクリアしました<br>";
print "下をクリックして次のページへ移動してください"


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
<button onclick="location.href='session_test3.php'">セッション終了の確認</button>
</body>
</html>