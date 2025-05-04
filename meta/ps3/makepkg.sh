#!/bin/sh

APPID="HATC00000"
CONTENTID="UP0001-"$APPID"_00-0000000000000000"

rm -Rf pkg
mkdir -p pkg/USRDIR

cp ICON0.PNG pkg
cp PIC1.PNG pkg
cp Data.hatch pkg/USRDIR

ppu-strip -S $1
sprxlinker $1
make_self_npdrm $1 pkg/USRDIR/EBOOT.BIN $CONTENTID

sfo.py --title "Hatch Engine" --appid $APPID -f sfo.xml pkg/PARAM.SFO
pkg.py --contentid $CONTENTID pkg/ $2

rm -Rf pkg