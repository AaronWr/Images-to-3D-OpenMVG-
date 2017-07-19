## Introduction

Dieses einfache Programm soll mit einem einzigen Aufruf aus, einige Bilder zu einem fertigen 3D Model generieren.
Dafür werden die libraries OpenMVG und MVE verwendet. In diesem Fall wird die Installation auf Linux umgesetzt.

Link zu OpenMVG: https://github.com/openMVG/openMVG

## Building

Zuerst holen wir uns diesen code.

	$ git clone https://github.com/AaronWr/Images-to-3D-OpenMVG-.git
	$ cd Images-to-3D-OpenMVG-

Dann ist es notwendig folgende Programme zu installieren.

 - Cmake
 - Git
 - c/c++ compiler ( gcc )   version >= 4.8.1


Mit dem folgenden command werden die erforderlichen libraries installiert.

	$ sudo apt-get install libpng-dev libjpeg-dev libtiff-dev libxxf86vm1 libxxf86vm-dev 
	   libxrandr-dev


Dann holen wir uns die OpenMVG sources.

	$ git clone --recursive https://github.com/openMVG/openMVG.git
	$ mkdir openMVG_Build
	$ cd openMVG_Build

	$ cmake -DCMAKE_BUILD_TYPE=RELEASE . ../openMVG/src/


Jetzt muss das Projekt compiled...

	$ make

 ... oder mit multi-core compiled werden. ( cores für die Anzahl der Threads )

	$ make -j cores

MVE ist notwendig für das Programm.  
Um MVE nutzen zu können müssen wir die sources compilen : 

	$ git clone https://github.com/simonfuhrmann/mve.git
	$ cd mve
	$ make -j cores


Die Datenstruktur sollte jetzt wie folgt aussehen.

	Images-to-3D-OpenMVG-
		|___mve
		|___openMVG
		|___openMVG_Build
		|___src


Jetzt kann das Programm mit einer einzigen Zeile verwendet werden :

	$ ./src/ImagesTo3DPly.o [pfad mit Images]
