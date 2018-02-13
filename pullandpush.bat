@echo off
set /p file="Enter Commit Message: "
git pull
git add --all
git commit -m " %file% "
git push
pause