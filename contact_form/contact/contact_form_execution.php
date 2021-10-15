<?php

//関数定義ファイルを読み込み
require '../libs/functions.php';

//入力内容を格納、なければ NULL（変数の初期化）
$name = isset( $_POST[ 'name' ] ) ? $_POST[ 'name' ] : NULL;
$email = isset( $_POST[ 'email' ] ) ? $_POST[ 'email' ] : NULL;
$body = isset( $_POST[ 'body' ] ) ? $_POST[ 'body' ] : NULL;
//$tel = isset( $_POST[ 'tel' ] ) ? $_POST[ 'tel' ] : NULL;

//送信ボタンで発火
if (isset($_POST['submitted'])) {
   FILTER();
   if ($_SERVER['REQUEST_METHOD']==='POST'){//_POSTのリクエストか判定
      //$mailToを記述したファイルの読み込み
      require '../libs/mailvars.php';
      //回収アドレスの代入
      $mailTo = mb_encode_mimeheader(MAIL_TO_NAME) ."<" . MAIL_TO. ">";
      //Return-Pathに指定するメールアドレス
      $returnMail = MAIL_RETURN_PATH; 
      //日本語設定
      mb_language("japanese");
      mb_internal_encoding("UTF-8");
      //格納内容の本文構成。値は h() でエスケープ処理
      $mail_body = 'ホームページからのお問い合わせ' . "\n\n";
      $mail_body .=  "お名前： " .h($name) . "\n";
      $mail_body .=  "Email： " . h($email) . "\n"  ;
      $mail_body .=  "＜お問い合わせ内容＞" . "\n" . h($body);
      // 送信者情報（From ヘッダー）の設定
      $header = "From: " . mb_encode_mimeheader($name) ."<" . $email. ">\n";
      //メール送信
      if(ini_get('safe_mode')){
         //セーフモードがOnの場合は第5引数が使えない
         $result = mb_send_mail($mailTo,"ホームページからのお問い合わせ",$mail_body,$header);
         print "お客様の環境がセーフモードのため、迷惑メールに振り分けられる可能性があります。";
      }else{
         $result = mb_send_mail($mailTo,"ホームページからのお問い合わせ",$mail_body,$header,'-f' . $returnMail);
      }
   }else{
      print "_POSTでのリクエストではありません。";
   }

   //メールが送信された場合の処理
   if ( $result ) {
      //空の配列を代入し、すべてのPOST変数を消去
      $_POST = array();
      //変数の値も初期化
      $name = '';
      $email = '';
      $tel = '';
      $subject = '';
      $body = '';
      //再読み込みによる二重送信の防止
      $params = '?result='. $result;
      //サーバー変数 $_SERVER['HTTPS'] が取得出来ない環境用
      if(isset($_SERVER['HTTP_X_FORWARDED_PROTO']) and $_SERVER['HTTP_X_FORWARDED_PROTO'] === "https"){
         $_SERVER['HTTPS'] = 'on';
      }
      $url = (empty($_SERVER['HTTPS']) ? 'http://' : 'https://').$_SERVER['HTTP_HOST'].$_SERVER['SCRIPT_NAME']; 
      header('Location:' . $url . $params);
      exit;
   } 
}


//フィルターを定義
function FILTER(){
   //POSTされたデータに不正な値がないかを別途定義した checkInput() 関数で検証 
   $_POST = checkInput( $_POST );
   if(isset($_POST['name'])) {
      //スクリプトタグがあれば除去
      $name = filter_var($_POST['name'], FILTER_SANITIZE_STRING);
   }
   if(isset($_POST['email'])) {
      //全ての改行文字を削除
      $email = str_replace(array("\r", "\n", "%0a", "%0d"), '', $_POST['email']);
      //E-mail の形式にフィルタ
      $email = filter_var($email, FILTER_VALIDATE_EMAIL);
   }
   if(isset($_POST['body'])) {
      $body = filter_var($_POST['body'], FILTER_SANITIZE_STRING);
   }
   //if(isset($_POST['tel'])) {
      //数値の形式にフィルタ（数字、+ 、- 記号 以外を除去）
      //$tel = filter_var($_POST['tel'], FILTER_SANITIZE_NUMBER_INT);
   //}
}
?>

<!DOCTYPE html>
<html lang="ja">
<head>
   <meta charset="utf-8">
   <meta name="Description" content="" />
   <meta name="Keywords"  content="" />
   <title>コンタクトフォーム</title>
</head>
<body>
   <?php  if ( isset($_GET['result']) && $_GET['result'] ) : // 送信が成功した場合?>
      <p>送信完了しました。</p>
      <p>お問い合わせありがとうございます。</p>
      <hr>
   <?php elseif (isset($result) && !$result ): // 送信が失敗した場合 ?>
      <p>送信に失敗しました。</p>
      <p>別のブラウザでお試しいただくか、しばらく経ってから再度お試しください。</p>
      <hr>
   <?php endif; ?>
</body>
</html>