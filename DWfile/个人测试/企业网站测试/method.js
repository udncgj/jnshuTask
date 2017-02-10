// JavaScript Document
window.onload = function(){
	var wea = document.getElementsByName('weather_check');
	var tianqi = document.getElementById('tianqi8_wetherinfo');
	wea[0].onclick = function(){
	if(wea[0].checked){
		tianqi.style.display="block";
	}else{
		tianqi.style.display="none";
	}
	}
}