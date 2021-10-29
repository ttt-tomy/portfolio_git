//DOMの準備後に実行する内容
$(function(){
  $("#getButton").click(function(){
    //HTMLの取得
    var text = $("#view").html();
    //値に変数textを反映
    $('#userText').val(text);
  });
  $("#backButton").click(function(){
    //値の取得
    var text = $("#userText").val();
    //HTMLの反映
    $('#view').html(text);
  });
});
