//プレイリストを取得
var listitems = document.querySelectorAll('li');
for (var i = 0; i < listitems.length; i++) {
  //clickイベントを設定
  listitems[i].addEventListener('click',
    (e)=>{
        var li_h = e.target;
        playMusic(li_h);

    }
  );
}
//再生中と停止中でイラストを切り替える
var audio_h = document.querySelector('audio');
audio_h.addEventListener('play',
  (e)=>{
    var img_h = document.querySelector('img');
    img_h.setAttribute('src','pict_play.png');
  }
);
audio_h.addEventListener('pause',
  (e)=>{
    var img_h = document.querySelector('img');
    img_h.setAttribute('src','pict_stop.png');
  }
);

//曲を最後まで再生したとき
audio_h.addEventListener('ended' ,
  (e)=>{
    //クロームだといらないっぽい
    var img_h = document.querySelector('img');
    img_h.setAttribute('src' , 'pict_stop.png');
    //次の居に切り替え
    var activeli = document.querySelector('.active');
    var nextli = activeli.nextElementSibling;
    console.log('active' + activeli + activeli.getAttribute('data-file'));
    console.log('next' + nextli + nextli.getAttribute('data-file'));
    if(nextli != null){
      playMusic(nextli);
    }
  }
);

//ランダム再生
var random = document.querySelector('#random');
random.addEventListener('click' ,
  (e)=>{
    e.preventDefault();
    var listitems = document.querySelectorAll('li');
    var nagasa = listitems.length;
    console.log(nagasa);
    var rand = Math.floor(Math.random() * nagasa);
    console.log(rand);
    playMusic(listitems[rand]);
  }
)


//関数作成
function playMusic(li_h){
  //イベントされたdate-fileを取得
  var file_h = li_h.getAttribute('data-file');
  //audioの要素を取得
  var audio_h = document.querySelector('audio')
  //srcに取得したファイルをセット
  audio_h.setAttribute('src', file_h);
  audio_h.play();

  //activeな項目を変更
  var active_h = document.querySelector('.active');
  active_h.className ='';
  li_h.className = 'active';
}
