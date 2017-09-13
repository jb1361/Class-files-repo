@echo off
cd %cd%
Echo Current Directory:  %cd%
set /p files= Enter files to compile: 
g++ -c  %files%
pause