// JavaScript Document
window.onload = function(){
	//setInterval(Clock,500);//时钟
	var aList = document.getElementsByClassName('list_li');
	for(var i=0; i<aList.length; i++){//list触发
		aList[i].onmouseover = function(){
			clearTimeout(i);
			var showMes = this.getElementsByTagName('ul')[0];
			showMes.className = "list_show" ;
			//showMes.style.filter = 'alpha(opacity:0)';
	        //showMes.style.opacity = '0';
			boxChange(showMes,{opacity:100},8);
		}
		aList[i].onmouseout = function(){
			var hideMes = this.getElementsByTagName('ul')[0];
	        boxChange(hideMes,{opacity:0},3);
			i = setTimeout(function(){
				hideMes.className = "list_hide";
			},500);
		}
	}
	showFocus();//
	document.getElementsByClassName('pic')[0].style.display = 'block';
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

function showFocus(){
	myFocus.set({
		id:'boxID',//焦点图盒子ID
		pattern:'mF_fancy',//风格应用的名称
		time:2,//切换时间间隔(秒)
		trigger:'click',//触发切换模式:'click'(点击)/'mouseover'(悬停)
		width:150,//设置图片区域宽度(像素)
		height:310,//设置图片区域高度(像素)
		txtHeight:'default'//文字层高度设置(像素),'default'为默认高度，0为隐藏
	})
}

function boxChange(obj,json,s){//,fn){
	var flag = true;
	clearInterval(obj.timer);
	obj.timer = setInterval(function(){
		for(var model in json){
			var target = json[model];
			if(model == 'opacity'){
				var nowValue = parseFloat(getStyle(obj,model))*100;
			}else{
				var nowValue = parseInt(getStyle(obj,model));
			}
			var speed = (target-nowValue)/s;
			speed = speed >0?Math.ceil(speed):Math.floor(speed);
			if(nowValue != target){
				flag = false;
			}
			if(model == 'opacity'){
				obj.style[model] = (nowValue+speed)/100;
				obj.style.filter = 'alpha(opactiy:'+(nowValue+speed)+')';
			}else{
				obj.style[model] = nowValue+speed+'px';
			}
		}
		if(flag){
			clearInterval(obj.timer);
			/*if(fn){
			  fu();
			}*/
		}
	},50);
}

function getStyle(obj,attr){
	if(obj.currentStyle){
		return obj.currentStyle[attr];
	}else{
		return getComputedStyle(obj,false)[attr];
	}
}

$(document).ready(function(e) {
	var $sujectHide = $('.suject_hide');
	$sujectHide.click(function(){                 //.unbind('click')取消绑定
		var i = $sujectHide.index(this);
		var $changeHide = $('.suject_hide:eq('+i+')~div:eq(0)');
		$changeHide.slideToggle(500);//下拉
		//隐藏、显示
		/*if($changeHide.css('display') == 'none'){
			$changeHide.css('display','block');
		}else{
			$changeHide.css('display','none');
		}*/
	});
	var $textDd = $('.suject_mes dd');
	console.log($textDd.eq(4).text());
	var $textShow = $('.suject_text div');
	$textDd.click(function(){
		var i = $textDd.index(this);
		console.log(i);
		$textShow.each(function(index, element) {
            $textShow.eq('+index+').removeClass();
		console.log(i);
        });
		$textShow.eq('+i+').addClass('text_show');
	})
});