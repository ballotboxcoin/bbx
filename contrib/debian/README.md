
Debian
====================
This directory contains files used to package ballotboxd/ballotbox-qt
for Debian-based Linux systems. If you compile ballotboxd/ballotbox-qt yourself, there are some useful files here.

## ballotbox: URI support ##


ballotbox-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ballotbox-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ballotbox-qt binary to `/usr/bin`
and the `../../share/pixmaps/ballotbox128.png` to `/usr/share/pixmaps`

ballotbox-qt.protocol (KDE)

