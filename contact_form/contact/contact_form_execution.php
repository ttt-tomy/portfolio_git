<?php
         
//関数定義ファイルを読み込み
require '../libs/functions.php';

//入力内容を格納、なければ NULL（変数の初期化）
$name = isset( $_POST[ 'name' ] ) ? $_POST[ 'name' ] : NULL;
$email = isset( $_POST[ 'email' ] ) ? $_POST[ 'email' ] : NULL;
$body = isset( $_POST[ 'body' ] ) ? $_POST[ 'body' ] : NULL;
//$tel = isset( $_POST[ 'tel' ] ) ? $_POST[ 'tel' ] : NULL;


//POST送信を受けて発火
if ($_SERVER["REQUEST_METHOD"] == "POST") {
   FILTER();
   if (empty($error) && $_SERVER['REQUEST_METHOD']==='POST'){//エラーがなく且つ POST でのリクエストか判定
      //$mailToを記述したファイルの読み込み
      require '../libs/mailvars.php';
      //なりすまし防止
      if($email == MAIL_TO || $email == MAIL_RETURN_PATH){
         $error['email'] = '・メールアドレスが不正です';
      }
      if(isset($error['email']))echo h($error['email']) .'<br>';
   }else{
      print "入力内容のエラーです。" .'<br>';
      if(isset($error['name']))echo h($error['name']) .'<br>';
      if(isset($error['email']))echo h($error['email']) .'<br>';
      if(isset($error['tel']))echo h($error['tel']) .'<br>';
      if(isset($error['tel_format']))echo h($error['tel_format']) .'<br>';
      //if(isset( $error['subject']))echo h($error['subject']) .'<br>';
      if(isset($error['body']))echo h($error['body']) .'<br>';
      if(empty($error))echo '_POSTリクエストではありません。';
   }
}

//'submitted'のPOSTリクエストで発火
//コードで編集はできるためセキュリティは再度行う
if (isset($_POST['submitted'])) {
   $overlay = 1 ;
   //当ページ上のformのため再度入力内容を格納、なければ NULL（変数の初期化）
   $name = isset( $_POST[ 'name' ] ) ? $_POST[ 'name' ] : NULL;
   $email = isset( $_POST[ 'email' ] ) ? $_POST[ 'email' ] : NULL;
   $body = isset( $_POST[ 'body' ] ) ? $_POST[ 'body' ] : NULL;
   //$tel = isset( $_POST[ 'tel' ] ) ? $_POST[ 'tel' ] : NULL;
   FILTER();
   if (empty($error) && $_SERVER['REQUEST_METHOD']==='POST'){//エラーがなく且つ POST でのリクエストか判定
      //$mailToを記述したファイルの読み込み
      require '../libs/mailvars.php';
      //なりすまし防止
      if($email != MAIL_TO && $email != MAIL_RETURN_PATH){
         //回収メールアドレスの代入
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
         $header = "From: " . mb_encode_mimeheader( AUTO_REPLY_NAME ) . " <" . AUTO_REPLY . ">\n";
         //メール送信
         if(ini_get('safe_mode')){
            //セーフモードがOnの場合は第5引数が使えない
            $result = mb_send_mail($mailTo,"ホームページからのお問い合わせ",$mail_body,$header);
         }else{
            $result = mb_send_mail($mailTo,"ホームページからのお問い合わせ",$mail_body,$header,'-f' . $returnMail);
         }
            //メールが送信された場合の処理
         if ($result) {
            //自動返信
            date_default_timezone_set('Asia/Tokyo'); 
            $ar_header = "MIME-Version: 1.0\n";
            $ar_header .= "From: " . mb_encode_mimeheader( AUTO_REPLY_NAME ) . " <" . AUTO_REPLY . ">\n";
            $ar_header .= "Reply-To: " . mb_encode_mimeheader( AUTO_REPLY_NAME ) . " <" . AUTO_REPLY . ">\n";
            $ar_subject = 'お問い合わせありがとうございます(自動返信)';//件名
            $ar_body = $name." 様\n\n";//本文ここから
            $ar_body .= "この度は、お問い合わせいただき誠にありがとうございます。" . "\n";
            $ar_body .= "下記の内容で受け付けました。\n\n";
            $ar_body .= "お問い合わせ日時：" . date("Y-m-d H:i") . "\n";
            $ar_body .= "お名前：" . $name . "\n";
            $ar_body .= "メールアドレス：" . $email . "\n";
            //$ar_body .= "お電話番号： " . $tel . "\n\n" ;
            $ar_body .="＜お問い合わせ内容＞" . "\n" . $body . "\n\n" ;
            $ar_body .="※※ご注意※※" . "\n" . "このメールは送信専用のメールアドレスから配信されています。\nこのメールへの返信はできませんのでご了承ください。" ;//本文ここまで
            if ( ini_get( 'safe_mode' ) ) {
               $result2 = mb_send_mail( $email, $ar_subject , $ar_body , $ar_header  );
            } else {
               $result2 = mb_send_mail( $email, $ar_subject , $ar_body , $ar_header , '-f' . $returnMail );
            }
            //空の配列を代入し、すべてのPOST変数を消去
            $_POST = array();
            //変数の値も初期化
            $name = '';
            $email = '';
            //$tel = '';
            //$subject = '';
            $body = '';
            //ページ再読み込みによる送信の防止
            $params = '?result='. $result;
            //サーバー変数 $_SERVER['HTTPS'] が取得出来ない環境用
            if(isset($_SERVER['HTTP_X_FORWARDED_PROTO']) and $_SERVER['HTTP_X_FORWARDED_PROTO'] === "https"){
            $_SERVER['HTTPS'] = 'on';
            }
            $url = (empty($_SERVER['HTTPS']) ? 'http://' : 'https://').$_SERVER['HTTP_HOST'].$_SERVER['SCRIPT_NAME']; 
            header('Location:' . $url . $params);
            exit;
         }else{
            print "send_mailエラー";
         }
      }else{
         print "メールアドレスが不正です。";
      }
   }else{
      print "入力内容のエラーです。" .'<br>';
      if(isset($error['name']))echo h($error['name']) .'<br>';
      if(isset($error['email']))echo h($error['email']) .'<br>';
      //if(isset($error['tel']))echo h($error['tel']) .'<br>';
      //if(isset($error['tel_format']))echo h($error['tel_format']) .'<br>';
      //if(isset( $error['subject']))echo h($error['subject']) .'<br>';
      if(isset($error['body']))echo h($error['body']) .'<br>';
      if(empty($error))echo '_POSTリクエストではありません。';
   }
}


//フィルターを定義
function FILTER(){
   //POSTされたデータに不正な値がないかを別途定義した checkInput() 関数で検証
   global $_POST,$name,$email,$body,$error,$name,$pattern;
   $_POST = checkInput( $_POST );
   //入力内容を成形
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

   //エラーメッセージを保存する配列の初期化
   $error = array();
   //値の検証
   if ( $name == '' ) {
      $error['name'] = '・お名前は必須項目です。';
   //制御文字でないことと文字数をチェック
   } else if ( preg_match( '/\A[[:^cntrl:]]{1,30}\z/u', $name ) == 0 ) {
      $error['name'] = '・お名前の入力は30文字以内です。';
   }
   if ( $email == '' ) {
      $error['email'] = '・メールアドレスは必須です。';
   } else { //メールアドレスを正規表現でチェック
      $pattern = '/^([a-z0-9\+_\-]+)(\.[a-z0-9\+_\-]+)*@([a-z0-9\-]+\.)+[a-z]{2,6}$/uiD';
      if ( !preg_match( $pattern, $email ) ) {
         $error['email'] = '・メールアドレスの形式が正しくありません。';
      }
   }
   //if ( $email_check == '' ) {
   //   $error['email_check'] = '*確認用メールアドレスは必須です。';
   //} else { //メールアドレスを正規表現でチェック
   //   if ( $email_check !== $email ) {
   //      $error['email_check'] = '*メールアドレスが一致しません。';
   //   }
   //}
   //if ( preg_match( '/\A[[:^cntrl:]]{0,30}\z/u', $tel ) == 0 ) {
   //   $error['tel'] = '*電話番号は30文字以内でお願いします。';
   //}
   //if ( $tel != '' && preg_match( '/\A\(?\d{2,5}\)?[-(\.\s]{0,2}\d{1,4}[-)\.\s]{0,2}\d{3,4}\z/u', $tel ) == 0 ) {
   //   $error['tel_format'] = '*電話番号の形式が正しくありません。';
   //}
   //if ( $subject == '' ) {
   //   $error['subject'] = '*件名は必須項目です。';
   //   //制御文字でないことと文字数をチェック
   //} else if ( preg_match( '/\A[[:^cntrl:]]{1,100}\z/u', $subject ) == 0 ) {
   //$error['subject'] = '*件名は100文字以内でお願いします。';
   //}
   if ( $body == '' ) {
      $error['body'] = '・内容は必須項目です。';
      //制御文字（タブ、復帰、改行を除く）でないことと文字数をチェック
   } else if ( preg_match( '/\A[\r\n\t[:^cntrl:]]{1,1050}\z/u', $body ) == 0 ) {
      $error['body'] = '・内容は1000文字以内でお願いします。';
   }
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
<?php  if (isset($_GET['result']) && $_GET['result'] ) : // 送信が成功した場合?>
      <p>お問い合わせありがとうございます。<br>送信完了しました。</p>
   <?php elseif (isset($result) && !$result ): // 送信が失敗した場合 ?>
      <p>送信に失敗しました。<br>送信完了しました。別のブラウザでお試しいただくか、しばらく経ってから再度お試しください。</p>
   <?php elseif (isset($result2) && !$result2 ): // 自動返信が失敗した場合 ?>
      <p>自動送信に失敗しました。</p>
   <?php endif; ?>
   <!--セーフモードごとの表示切り替え-->
   <?php  if (isset($_GET['result']) && $_GET['result'] && ini_get('safe_mode')) : ?>
      <p>※セーフモードが有効です。迷惑メールへ振り分けられる可能性があります。</p>
      <hr>
   <?php elseif(isset($_GET['result']) && $_GET['result']): ?>
      <p>※迷惑メールに振り分けられることがあります。※<br>当方からのメールがご利用の環境により迷惑メールに振り分けられることがありますので、ご注意ください。</p>
      <hr>
<?php endif; ?>
<?php if (empty($error) && $_SERVER['REQUEST_METHOD']==='POST'): ?>
<form action="contact_form_execution.php" method="post">
         <input type="hidden" name="name" value="<?php echo $name; ?>">
         <input type="hidden" name="email" value="<?php echo $email; ?>">
         <input type="hidden" name="body" value="<?php echo $body; ?>">
         <!-- <input type="hidden" name="tel" value="<?php echo $tel; ?>"> -->
         <h1>メッセージ内容確認</h1>
         <p>内容に間違えなければ「送信する」をクリックして下さい。</p>
               <p>お名前：<?php echo $name; ?></p>
               <p>メールアドレス：<?php echo $email; ?></p>
               <!-- <p>電話番号：<?php echo $tel; ?></p> -->
               <p>メッセージ内容：<br><?php echo $body ?></p>
   <input type="button" value="内容を修正する" onclick="history.back(-1)">
   <button name="submitted" type="submit">送信する</button>
</form>
<?php endif; ?>
</div>
</body>
</html>

