
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
  <title>MINATEC Portail captif</title>
  <meta http-equiv="Cache-control" content="no-cache">
  <meta http-equiv="Pragma" content="no-cache">
  <SCRIPT LANGUAGE="JavaScript">
    var blur = 0;
    var starttime = new Date();
    var startclock = starttime.getTime();
    var mytimeleft = 0;
		var theTime;
		
		document.onmousemove=stockTime;
		function stockTime() {
		currentTime=new Date();
		theTime=currentTime.getTime();
		}

		function verifTime() {
		currentTime=new Date();
		var timeNow=currentTime.getTime();
		if (timeNow-theTime>60000000) { 
		document.location.href=('http://192.168.98.1:3990/logoff');		
		window.close();
		alert('Fermeture de la connexion');
		}
		}
		

    function doTime() {
      window.setTimeout( "doTime()", 1000 );
      t = new Date();
      time = Math.round((t.getTime() - starttime.getTime())/1000);
      if (mytimeleft) {
        time = mytimeleft - time;
        if (time <= 0) {
          window.location = "?res=popup3&uamip=192.168.98.1&uamport=3990";
        }
      }
      if (time < 0) time = 0;
      hours = (time - (time % 3600)) / 3600;
      time = time - (hours * 3600);
      mins = (time - (time % 60)) / 60;
      secs = time - (mins * 60);
      if (hours < 10) hours = "0" + hours;
      if (mins < 10) mins = "0" + mins;
      if (secs < 10) secs = "0" + secs;
      title = "Temps de connexion: " + hours + ":" + mins + ":" + secs;
      if (mytimeleft) {
        title = "Temps restant: " + hours + ":" + mins + ":" + secs;
      }
      if(document.all || document.getElementById){
         document.title = title;
      }
      else {   
        self.status = title;
      }
    }

    function popUp(URL) {
      if (self.name != "chillispot_popup") {
        chillispot_popup = window.open(URL, 'chillispot_popup', 'toolbar=0,scrollbars=0,location=0,statusbar=0,menubar=0,resizable=0,width=600,height=375');
      }
    }

    function doOnLoad(result, URL, userurl, redirurl, timeleft) {
      if (timeleft) {
        mytimeleft = timeleft;
      }
      if ((result == 1) && (self.name == "chillispot_popup")) {
        doTime();
				

      }
      if ((result == 1) && (self.name != "chillispot_popup")) {
        chillispot_popup = window.open(URL, 'chillispot_popup', 'toolbar=0,scrollbars=0,location=0,statusbar=0,menubar=0,resizable=0,width=600,height=375');
      }
      if ((result == 2) || result == 5) {
        document.form1.UserName.focus()

		
		alert(notyet);
		alert('Fermeture de la connexion');
      }
      if ((result == 2) && (self.name != "chillispot_popup")) {
        chillispot_popup = window.open('', 'chillispot_popup', 'toolbar=0,scrollbars=0,location=0,statusbar=0,menubar=0,resizable=0,width=600,height=375');

		alert(notyet);
		alert('HOLA');
      }
      if ((result == 12) && (self.name == "chillispot_popup")) {
        doTime();
        if (redirurl) {
          opener.location = redirurl;
        }
        else if (opener.home) {
          opener.home();
        }
        else {onUnLoad
          opener.location = "about:home";
        }
        self.focus();
        blur = 0;

      }
      if ((result == 13) && (self.name == "chillispot_popup")) {
        self.focus();
        blur = 1;
      }
    }

    function doOnBlur(result) {
      if ((result == 12) && (self.name == "chillispot_popup")) {
        if (blur == 0) {
          blur = 1;
          self.focus();
        }
      }
    }

     function deCo(result) {
	if ((result==12) && (self.name == "chillispot_popup")) {			
	   document.location.href=('http://192.168.98.1:3990/logoff');
	   alert('Fermeture de la connexion');
	}
      }
	
	function clOse() {
	window.close();
	}

	function lOgOut() {
	 document.location.href=('http://192.168.98.1:3990/logoff');
	}
	
	window.setInterval('verifTime()',10000);
  </script>
  
  <link href='/style.css' type='text/css' rel='Stylesheet'>
</head>
<body onLoad="javascript:doOnLoad(5, '?res=popup2&uamip=192.168.98.1&uamport=3990&userurl=http%3a%2f%2fwww.robotronik.org%2f&redirurl=&timeleft=','http://www.robotronik.org/', '', '')" onBlur = "javascript:doOnBlur(5)" bgColor = '#c0d8f4'onUnLoad="javascript:deCo(5)" >
<center><table width=80% border=0>
<tr>
<td align=center>
<h2>
Bienvenu sur le Portail Captif MINATEC.
</h2>
</td>
<td align=center>
<img src=/images/minatec.jpg border=0><br>
</td></tr>
</table></center>

<center>
<table width=80% border=0>
<tr>
<td align=center colspan=2>
<br><br>Bonjour, <br><br>
<br>
Si vous poss&eacute;dez un identifiant <b>MINATEC</b>, veuillez saisir comme nom d'utilisateur : <b>identifiant@minatec</b><br>
Si vous poss&eacute;dez un identifiant <b>AGALAN</b>, veuillez saisir comme nom utlisateur : <b>identifiant@agalan</b><br>
Enfin, si vous poss&eacute;dez un compte <b>invit&eacute;</b> saisissez : <b>identifiant@guest</b><br>.
<br><br>
Pour tout probl&egrave;me informatique n'h&eacute;sitez pas &agrave; contacter notre support : <b>help@minatec.inpg.fr</b><br><br>
Bonne navigation.<br>
Le Service Informatique MINATEC<br><br>
</td>
</tr>
</table>
</center>

  <H2 style="text-align: center;">Authentification</H2><br>
  
  <form name="form1" method="post" action="">
  <INPUT TYPE="hidden" NAME="challenge" VALUE="e5b9c12468340162be0279275290805e">
  <INPUT TYPE="hidden" NAME="uamip" VALUE="192.168.98.1">
  <INPUT TYPE="hidden" NAME="uamport" VALUE="3990">
  <INPUT TYPE="hidden" NAME="userurl" VALUE="http%3a%2f%2fwww.robotronik.org%2f">
  <center>
  <table border="0" cellpadding="5" cellspacing="0" style="width: 60%;">
    <tbody>
      <tr>
        <td align="right"><b>Identifiant : </b></td>
        <td><input STYLE="font-family: Arial" type="text" name="UserName" size="20" maxlength="128"></td>
      </tr>
      <tr>
        <td align="right"><b>Mot de passe : </b></td>
        <td><input STYLE="font-family: Arial" type="password" name="Password" size="20" maxlength="128"></td>
      </tr>
      <tr>
        <td align="center" colspan="2" height="23"><input type="submit" name="button" value="Connexion" onClick="javascript:popUp('?res=popup1&uamip=192.168.98.1&uamport=3990')"></td> 
      </tr>
    </tbody>
  </table>
  </center>
  </form>
  <BR><BR>
  
<center>
<br><br>
<img src=/images/inpg.gif border=0>
</center>
</body>

</body>
</html>
</pre>
<A NAME="chap1"></A>
<pre>