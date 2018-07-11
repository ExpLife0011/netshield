@echo off

echo Analyze raw tcpdump trace
echo.
..\bin\Release\NetShield.exe -c ..\rule\vulsig-http-sample-0.1.xml -t sample.tcpdump
echo.

echo Analyze raw tcpdump trace using the parser generated by UltraPac
echo.
..\bin\Release\NetShield.exe -c ..\rule\vulsig-http-sample-0.1.xml -t sample.tcpdump --use-pac
echo.

echo Do tcp reassembling first and then analyze application-layer data
echo.
if exist sample.rsm del sample.rsm
..\bin\Release\TCPReassembler.exe sample.tcpdump sample.rsm
..\bin\Release\NetShield.exe -c ..\rule\vulsig-http-sample-0.1.xml -r sample.rsm
echo.

echo Do tcp reassembling first and then analyze application-layer data using the parser generated by UltraPac
echo.
if exist sample.rsm del sample.rsm
..\bin\Release\TCPReassembler.exe sample.tcpdump sample.rsm
..\bin\Release\NetShield.exe -c ..\rule\vulsig-http-sample-0.1.xml -r sample.rsm --use-pac
echo.

echo on
