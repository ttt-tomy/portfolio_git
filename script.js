$(function() {
   // トップへ戻るボタン
   $('#top-btn').click(function(){
      $('html,body').animate({
         'scrollTop': 0
      },700);
      });
   $('#form').submit(function() {
      var selectItem = $('#select-form').val();
      var textItem = $('#text-form').val();
      if (textItem == '' || textItem == 'サイトの見た目が、\n\だと良いと思います。' || textItem == 'サイトの動線が、\n\だと良いと思います。' || textItem == 'サイトの内容が、\n\だと良いと思います。') {
         $('#error-message').text('内容を記入してください');
      } else {
         $('#error-message').text('');
      }
      $('#output-select').text(selectItem);
      $('#output-text').text(textItem);
      return false;
   });
   $('.option-btn').click(function() {
      var optionText = $(this).text();
     // 変数clickedOptionに、クリックした要素のdata-optionの値を代入
      var clickedOption = $(this).attr('data-option');
      console.log(clickedOption);
      
      $('#text-form').val('サイトの' + optionText + 'が、' + '\n\だと良いと思います。');
      // 変数clickedOptionを用いて、「#select-form」の値を自動で入力
      $('#select-form').val(clickedOption);
   });
   $('.index-btn').click(function() {
      $('.active').removeClass('active');
      var clickedIndex = $('.index-btn').index($(this));
      $('.slide').eq(clickedIndex).addClass('active');
      
     // 変数slideIndexに「.active」要素のインデックス番号を代入
      var slideIndex = $('.slide').index($('.active'));
     // change-btn要素を表示
      $('.change-btn').show();
      
     // 「.change-btn」の表示/非表示
      if(slideIndex === 0){
         $('.prev-btn').hide();
      }else if(slideIndex === 3){
         $('.next-btn').hide();
      }
   });
   
   $('.change-btn').click(function() {
      var $displaySlide = $('.active');
      $displaySlide.removeClass('active');
      if ($(this).hasClass('next-btn')) {
         $displaySlide.next().addClass('active');
      } else {
         $displaySlide.prev().addClass('active');
      }
      
     // 「.index-btn」のクリックイベントと同様の処理
      var slideIndex = $('.slide').index($('.active'));
     // 3. change-btn要素を表示
      $('.change-btn').show();
      
     // 「.change-btn」の表示/非表示
      if(slideIndex == 0){
         $('.prev-btn').hide();
      }else if(slideIndex == 3){
         $('.next-btn').hide();
      }
   });
   //////////// 新規登録モーダル ////////////
   $('.signup-show').click(function() {
      $('#signup-modal').fadeIn();
      $('.overlay').fadeIn();
      //ジャンプ抑止
      return false;
   });
   //閉じるボタン
   $('#close-modal').click(function() {
      $('#signup-modal').fadeOut();
      $('.overlay').fadeOut();
   });
   //範囲外クリック
   $('.overlay').click(function() {
      $('#signup-modal').fadeOut();
      $('.overlay').fadeOut();
   });
   //////////// ログインモーダル ////////////
   $('.login-show').click(function() {
      $('#login-modal').fadeIn();
      $('.overlay').fadeIn();
      //ジャンプ抑止
      return false;
   });
   //閉じるボタン
   $('.close-modal').click(function() {
      $('#login-modal').fadeOut();
      $('.overlay').fadeOut();
   });
   //範囲外クリック
   $('.overlay').click(function() {
      $('#login-modal').fadeOut();
      $('.overlay').fadeOut();
   });

   // Q＆Aのアコーディオン トグルクラスメソッドなし
   $('.qa-list-item').click(function() {
      var $answer = $(this).find('.answer');
      if($answer.hasClass('open')) {
         // answerをクローズ
         $answer.removeClass('open');
         $answer.slideUp();
         $(this).find('span').html('回答を見る');
      } else {
        // 全部をクローズ
         $('.answer').slideUp();
         $('.answer').removeClass('open');
         $('.qa-list-item').find('span').html('回答を見る');
         //answerをオープン
         $answer.addClass('open');
         $answer.slideDown();
         $(this).find('span').html('閉じる');
      }
   });
   // ハンバーガーメニュー トグルクラスメソッドあり
   $('.hamburger').click(function() {
      $('.hamburger-bg').toggleClass('active');
      $(this).toggleClass('active');
      if ($(this).hasClass('active')) {
         $('.globalMenuSp').addClass('active');
      } else {
         $('.globalMenuSp').removeClass('active');
         $('.hamburger-bg').fadeIn();
      }
   });
   //範囲外クリックで閉じる
   $('.hamburger-bg').click(function() {
      $('.hamburger-bg').removeClass('active');
      $('.hamburger').removeClass('active');
      $('.globalMenuSp').removeClass('active');
      $('.hamburger-bg').fadeIn();
   });
   //////////// 問い合わせフォーム送信 ////////////
   //////////// ローダー ////////////
   $('.contact-form-submit').click(function() {
      $('.loader-bg').fadeIn();
      //ジャンプ抑止
      return false;
   });
});
