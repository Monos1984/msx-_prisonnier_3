echo off

rem ================================
rem ** Compilation des fichiers C **
rem ================================
sdcc -c -mz80 source/main.c 
sdcc -c -mz80 source/data.c 
sdcc -c -mz80 source/scene_manager.c 
sdcc -c -mz80 source/scene_game.c 
sdcc -c -mz80 source/scene_tiles.c 
sdcc -c -mz80 source/game_controllers.c
sdcc -c -mz80 source/sprite_update.c
sdcc -c -mz80 source/title_screen.c
sdcc -c -mz80 source/load_asset.c
sdcc -c -mz80 source/windows.c

sdcc -c -mz80 source/scene_credit.c
sdcc -c -mz80 source/player_sound.c
rem =================================
rem ** linkage des fichiers objets **
rem =================================
sdcc -o msx.ihx -mz80 --no-std-crt0 --code-loc 0x107 --data-loc 0x0 rel/crt0_msxdos.rel lib/fusion.lib main.rel data.rel scene_manager.rel scene_game.rel scene_tiles.rel game_controllers.rel sprite_update.rel title_screen.rel load_asset.rel windows.rel scene_credit.rel player_sound.rel 

rem =====================
rem ** Creation de bin **
rem =====================
hex2bin -e com msx.ihx

rem ** DSK **
copy msx.com dsk\pris3.com /y

pause
rem ** mennage **
del *.com
del *.asm
del *.ihx
del *.lk
del *.lst
del *.map
del *.noi
del *.sym
del *.rel

0-Lunch_HB_F700D
pause