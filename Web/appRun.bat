@REM @echo off
@REM if "%1" == "h" goto begin 
@REM mshta vbscript:createobject("wscript.shell").run("%~nx0 h",0)(window.close)&&exit 
@REM :begin
node app.js