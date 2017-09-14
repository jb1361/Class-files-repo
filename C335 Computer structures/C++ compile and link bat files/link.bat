@echo off
cd %cd%
Echo Current Directory:  %cd%
set /p files= Enter files to link: 
g++ %files% -o output
pause