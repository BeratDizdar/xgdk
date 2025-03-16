@echo off
SETLOCAL ENABLEDELAYEDEXPANSION

cls

REM VCPKG'yi unutma ha

SET COMPILER_PATH=C:\raylib\w64devkit\bin
SET PATH=%COMPILER_PATH%;%PATH%
SET CC=gcc
SET CFLAGS=-static -O2 -Wall -Iexternal -DPLATFORM_DESKTOP
SET LDFLAGS=-lraylib -lopengl32 -lgdi32 -lwinmm
SET NAME_PART=main
SET OUT=bin\%NAME_PART%.exe

SET OBJ=
IF NOT EXIST obj mkdir obj
IF NOT EXIST bin mkdir bin

FOR %%f IN (src\engine\*.c) DO (
    SET FILENAME=%%~nf
    %CC% -c %%f -o obj\!FILENAME!.o %CFLAGS%
    SET OBJ=!OBJ! obj\!FILENAME!.o
)
FOR %%f IN (src\game\*.c) DO (
    SET FILENAME=%%~nf
    %CC% -c %%f -o obj\!FILENAME!.o %CFLAGS%
    SET OBJ=!OBJ! obj\!FILENAME!.o
)

%CC% -o %OUT% main.c %OBJ% %CFLAGS% %LDFLAGS%

IF EXIST %OUT% (
    upx %OUT%
    %OUT%
) ELSE (
    echo Error: Executable not found.
)
