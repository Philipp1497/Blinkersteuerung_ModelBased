

set defines=-DSPLINT -Dinterrupt=""

splint.exe ert_main.c %defines% >> log.txt 2>&1
splint.exe Taster.c %defines% >> log.txt 2>&1
splint.exe Timer.c %defines% >> log.txt 2>&1
splint.exe Init.c %defines% >> log.txt 2>&1
splint.exe Blinkersteuerung.c %defines% >> log.txt 2>&1
exit 0
pause