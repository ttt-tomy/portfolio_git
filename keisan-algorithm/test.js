//DOMの準備後に実行する内容
$(function(){
  $("#keisan").click(function(){
    // 入力値を取得
    var exp = $("#exp").val();
  	// 入力値の長さ
	var explen = exp.length;
  	// 実行結果kotaeに代入
	var kotae = compute(exp, explen);
  	// 答えを表示
  	document.getElementById("result").innerHTML = '答え' + kotae;
  	
  	// 上で使ってる関数
	function compute(Expression, ExpLen)
	{
	    // 変数や配列を宣言及び初期化
		var Operator = Array(100);
		var Priority = Array(100);
		var Value = Array(100);
		Value[0] = 0;
		var OpCnt = 0;
		var nest = 0;
		var chr, i, ip;

		// 長さ分繰り返す
	    for (i=0; i<ExpLen; i++) {
	    	// 処理の対象にする文字を格納
	        chr = Expression[i];
	    	// 0～9なら ※数字なら
	        if (0 <= chr || chr <= 9) {
	        	// 答え文字？桁数処理？
	            Value[OpCnt] = 10 * Value[OpCnt] + Number(chr);
	        }
	    	// 記号の場合
	        if (chr == '+' || chr == '-' || chr == '×' || chr == '÷') {
	        	// オペレーター用の配列に順に代入
	            Operator[OpCnt] = chr;
	            if (chr == '+' || chr == '-') {
	            	// 順番情報に代入
	                Priority[OpCnt] = nest + 1;
	            } else {
	            	// ×と÷は優先度が高いのでプラ1で順番値を代入
	                Priority[OpCnt] = nest + 2;
	            }
	            OpCnt = OpCnt + 1;
	        	// 答え用文字配列次のヤツを初期化　一応？
	            Value[OpCnt] = 0;
	        }
	    	// 括弧はさらに優先の為nestの値を動かしておく
	        if (chr == '(') {
	            nest = nest + 10;
	        }
	    	// 括弧優先の為に動かしていたnestの値戻す
	        if (chr == ')') {
	            nest = nest - 10;
	        }
	    }

	    //一旦ここでの配列内容を画面に表示
	    document.getElementById("Value").innerHTML = 'Value[] = ' + Value.join(',');
	    document.getElementById("Operator").innerHTML = 'Operator[] = ' + Operator.join(',');
		document.getElementById("Priority").innerHTML = 'Priority[] = ' + Priority.join(',');
			
	    //オペレーターのかず分処理を回す
	    while (0 < OpCnt) {
	        ip = 0;
	    	// 計算する順番を処理
	        for (i=1; i<OpCnt; i++) {
	            if (Priority[ip] < Priority[i]) {
	                ip = i;
	            }
	        }
	    	// 計算箇所
	        chr = Operator[ip];
	        if (chr == '+') {
	            Value[ip] = Value[ip] + Value[ip+1];
	        }
	        if (chr == '-') {
	            Value[ip] = Value[ip] - Value[ip+1];
	        }		    
	        if (chr == '×') {
	            Value[ip] = Value[ip] * Value[ip+1];
	        }		
	        if (chr == '÷') {
					console.log(Value[ip],Value[ip+1]);
	            Value[ip] = Value[ip] / Value[ip+1];
							
	        }
	        //演算した要素の部分を左詰めする処理
	        for (i=ip+1; i<OpCnt; i++) {
	            Value[i] = Value[i+1];
	            Operator[i-1] = Operator[i];
	            Priority[i-1] = Priority[i];
	        }
	        OpCnt = OpCnt - 1;
	    }
	    return Value[0];
	}
  	
  });
});


