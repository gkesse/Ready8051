@echo off

setlocal enabledelayedexpansion

for /d %%i in (*) do ( 
set GDIR=%%i

del /Q !GDIR!\keil\*.lst
del /Q !GDIR!\keil\*.obj
del /Q !GDIR!\keil\*.M51
del /Q !GDIR!\keil\*.plg
del /Q !GDIR!\keil\*.lnp
del /Q !GDIR!\keil\*.Bak
del /Q !GDIR!\keil\*.Opt
del /Q !GDIR!\keil\GProject

del /Q !GDIR!\proteus\*.pdsbak
del /Q !GDIR!\proteus\*.workspace
)

