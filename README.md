## Introduction

Dieses einfache Programm soll mit einem einzigen Aufruf aus, einige Bider zu einem fertigen 3D Model generieren.
Dafür werden die Librarys OpenMVG und MVE verwendet. In diesem Fall wird die Installation auf Linux umgesetzt.

Link zu OpenMVG: https://github.com/openMVG/openMVG

## Building

zuerst holen wir uns diesen Code.

	$ git clone https://github.com/AaronWr/Images-to-3D-OpenMVG-.git
	$ cd Images-to-3D-OpenMVG-

Es sind folgende Programme notwendig zu installieren bevor wir anfangen können.

 - Cmake
 - Git
 - c/c++ compiler ( gcc )   version >= 4.8.1


erforderliche externe Librarys werden installiert.

	$ sudo apt-get install libpng-dev libjpeg-dev libtiff-dev libxxf86vm1 libxxf86vm-dev 
	   libxrandr-dev


Dann holen wir uns die OpenMVG Sources.

	$ git clone --recursive https://github.com/openMVG/openMVG.git
	$ mkdir openMVG_Build
	$ cd openMVG_Build

	$ cmake -DCMAKE_BUILD_TYPE=RELEASE . ../openMVG/src/


jetzt muss das Project kompiliert werden

	$ make

oder mit multi-core compiliere. ( cores für die anzahl der Threads )

	$ make -j cores

MVE ist notwendig für das Programm
Um MVE nutzen zu können müssen wir die Sources compilen : 

	$ git clone https://github.com/simonfuhrmann/mve.git
	$ cd mve
	$ make -j cores


Die Datenstruktur sollte jetzt wie folgt aussehen.

	Images-to-3D-OpenMVG-
		|___mve
		|___openMVG
		|___openMVG_Build
		|___src


Das Programm kann dann mit nur einer Zeile verwendet werden:

	$ ./src/ImagesTo3DPly.o [pfad mit Images]
