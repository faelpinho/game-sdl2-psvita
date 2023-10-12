cd bin

cmake .. && make

cp meuhello.self eboot.bin

rm meuhello meuhello.self meuhello.self.out meuhello.velf meuhello.vpk.out

cp meuhello.vpk ~/.local/share/Vita3K/Vita3K/ux0/temp/meuhello.vpk

vita3k meuhello.vpk
