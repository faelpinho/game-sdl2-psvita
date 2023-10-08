cd bin
rm eboot.bin meuhello meuhello.self.out meuhello.velf meuhello.vpk.out

cmake .. && make

cp meuhello.self eboot.bin

cp meuhello.vpk ~/.local/share/Vita3K/Vita3K/ux0/temp/meuhello.vpk

vita3k meuhello.vpk
