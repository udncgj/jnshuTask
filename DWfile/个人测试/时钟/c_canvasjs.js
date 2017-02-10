// JavaScript Document
window.onload = function(){
  
  setInterval(Clock,500);
}

function Clock(){
	//console.time("test");
	var c=document.getElementById("clock");
	var ctx=c.getContext("2d");
	var wid = c.width;
	c.height = wid;
	var radius = wid/2-3;
	var cFont = Math.round(wid/10)+"px 宋体";
	ctx.font=cFont;
	ctx.translate(wid/2,wid/2);
	ctx.beginPath();
	ctx.arc(0,0,radius,0,2*Math.PI,true);
	ctx.closePath();
	ctx.lineWidth=5;
	ctx.stroke();
	ctx.beginPath();
	ctx.arc(0,0,wid/50,0,2*Math.PI,true);
	ctx.closePath();
	ctx.fill();
	ctx.lineWidth=1;
	for(var i=0;i<12;i++){	
		var num = i+1;
		var pos = (30*num-90)*2*Math.PI/360;
		if(num>=10){
		  var pTextX = Math.cos(pos)*(radius-wid/8)-Math.round(wid/20);
		}else{
			var pTextX = Math.cos(pos)*(radius-wid/8)-Math.round(wid/40);
		}
		var pTextY = Math.sin(pos)*(radius-wid/8)+Math.round(wid/30);
		var pPointX = Math.cos(pos)*(radius-wid/20);
		var pPointY = Math.sin(pos)*(radius-wid/20);
		ctx.beginPath();
		ctx.arc(pPointX,pPointY,radius/50,0,2*Math.PI,true);
		ctx.closePath();
		ctx.fill();
		ctx.strokeText(num,pTextX,pTextY);
	}
	var time = new Date();
	var s = time.getSeconds();
	var m = time.getMinutes()+s/60;
	var h = time.getHours()+m/60;
	if(h>=12){
		h-=12;
		ctx.strokeText("PM",-Math.round(wid/30),-wid/6);
	}
	var posS = (6*s-90)*2*Math.PI/360;
	var posM = (6*m-90)*2*Math.PI/360;
	var posH = (30*h-90)*2*Math.PI/360;
	ctx.lineWidth=2;
	ctx.moveTo(0,0);
	ctx.lineTo(Math.cos(posS)*(radius-wid/8),Math.sin(posS)*(radius-wid/8));
	ctx.stroke();
	ctx.lineWidth=3;
	ctx.moveTo(0,0);
	ctx.lineTo(Math.cos(posM)*(radius-wid/5),Math.sin(posM)*(radius-wid/5));
	ctx.stroke();
	ctx.lineWidth=4;
	ctx.moveTo(0,0);
	ctx.lineTo(Math.cos(posH)*(radius-wid/4),Math.sin(posH)*(radius-wid/4));
	ctx.stroke();
	//console.timeEnd("test");
}