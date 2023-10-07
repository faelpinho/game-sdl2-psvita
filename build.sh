cd bin
rm eboot.bin meuhello meuhello.self.out meuhello.velf meuhello.vpk.out

cmake .. && make

cp meuhello.self eboot.bin

cp meuhello.vpk ~/.local/share/Vita3K/Vita3K/ux0/temp/meuhello.vpk

# caja "ftp://192.168.1.16:1337/"

# vita3k
