
Debian
====================
This directory contains files used to package helveticumd/helveticum-qt
for Debian-based Linux systems. If you compile helveticumd/helveticum-qt yourself, there are some useful files here.

## helveticum: URI support ##


helveticum-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install helveticum-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your helveticum-qt binary to `/usr/bin`
and the `../../share/pixmaps/helveticum128.png` to `/usr/share/pixmaps`

helveticum-qt.protocol (KDE)

