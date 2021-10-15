var canvas, stage;
var DEGREE = 90;
var RADIUS = 38;
var centerPoint;
var lineCircle, circleColor;
var anchorList, controlList;

function init(){
   var controlRadius;
   var color;
   canvas = document.getElementById("canvas");
   stage = new createjs.Stage(canvas);
   centerPoint = {x: canvas.width / 2, y: canvas.height / 2};
   anchorList = getPointList(DEGREE, 0, RADIUS);
   controlRadius = RADIUS / Math.cos(Math.PI * DEGREE / 2 / 180);
   controlList = getPointList(DEGREE, DEGREE / 2, controlRadius);
   //色固定
   //circleColor = createjs.Graphics.getRGB(28,182,170);
   //ランダム配色
   circleColor = createjs.Graphics.getRGB(Math.floor(Math.random() * 0xFFFFFF));
   //画像背景　動作テスト及びデバック必要
   //circleColor = createjs.Bitmap("./img/main.jpg");
   lineCircle = new createjs.Shape(getLineCircle(anchorList, controlList));
   stage.addChild(lineCircle);
   createjs.Ticker.useRAF = true;
   createjs.Ticker.addEventListener('tick', tick);
}
function tick(){
   var point;
   var len = controlList.length;
   lineCircle.graphics.clear();
   for(var i = 0; i < len; i += 1){
      point = anchorList[i];
      point.update();
      point = controlList[i];
      point.update();
   }
   //色指定の場合
   lineCircle.graphics = getLineCircle(anchorList,  controlList);
   stage.update();
}
function getPointList(degree, offsetDegree ,radius){
   var pointList = [];
   var len = 360 / degree;
   var point;
   var radian;
   for(var i = 0; i < len; i += 1){
      radian = Math.PI * (degree * i + offsetDegree) / 180;
      point = new CustomPoint(
         //高さ
         Math.floor(Math.cos(radian) * radius * 200) / 80 + centerPoint.x,
         //幅
         Math.floor(Math.sin(radian) * radius * 200) / 80 + centerPoint.y
      );
      pointList.push(point);
   }
   return pointList;
}
function getLineCircle(anchorPointList, controlPointList){
   var anchorPoint, controlPoint;
   var g;
   var len = anchorPointList.length;
   g = new createjs.Graphics();
   g.beginFill(circleColor);
   for(var i = 0; i < len; i += 1){
      anchorPoint = anchorPointList[i];
      if(i === 0){
         g.moveTo(anchorPoint.x, anchorPoint.y);
      }else{
         controlPoint = controlPointList[i - 1];
         g.quadraticCurveTo(controlPoint.x, controlPoint.y, anchorPoint.x, anchorPoint.y);
      }
   }
   anchorPoint = anchorPointList[0];
   controlPoint = controlPointList[len - 1];
   g.quadraticCurveTo(controlPoint.x, controlPoint.y, anchorPoint.x, anchorPoint.y);
   g.endStroke();
   return g;
}
document.addEventListener("DOMContentLoaded", init, false);
//====================
// CustomPoint
//====================
CustomPoint = {};
(function (){
   function CustomPoint(x, y){
      this.initialize(x, y);
   }
   //Inheritance from Point
   var p = CustomPoint.prototype = new createjs.Point();
   p.Point_initialize = CustomPoint.prototype.initialize;
   p.initialize = function(x, y){
      //call to initialize() method from parent class
      this.Point_initialize();
      // override??
      this.x = x;
      this.y = y;
      //
      this._dX = Math.floor(Math.random() * 10) / 20;
      this._dY = Math.floor(Math.random() * 10) / 20;
      this._degree = Math.floor(Math.random() * 360);
   };
   p.update = function(){
      var radian = Math.PI * this._degree / 180;
      this.x += this._dX * Math.sin(radian);
      this.y += this._dY * Math.cos(radian);
      this._degree += 12;
      if(this._degree >= 360){
         this._degree = 0;
         //揺れ幅
         this._dX = Math.floor(Math.random() * 15) / 18;
         this._dY = Math.floor(Math.random() * 15) / 20;
      }
   };
   this.CustomPoint = CustomPoint;
}());