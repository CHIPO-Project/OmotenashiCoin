
Debian
====================
This directory contains files used to package omotenashicoind/omotenashicoin-qt
for Debian-based Linux systems. If you compile omotenashicoind/omotenashicoin-qt yourself, there are some useful files here.

## omotenashicoin: URI support ##


omotenashicoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install omotenashicoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your omotenashicoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/omotenashicoin128.png` to `/usr/share/pixmaps`

omotenashicoin-qt.protocol (KDE)

