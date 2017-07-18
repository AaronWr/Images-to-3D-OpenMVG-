## Introduction

Dieses einfache Programm soll mit einem Einzigen Aufruff aus, einige Bider zu einem fertigen 3D Model generieren.
Dafür werden die Librarzs OpenMVG und MVE verwendet.

## Building

zuerst hollen wir uns diesen Code.

	$ git clone https://github.com/AaronWr/Images-to-3D-OpenMVG-.git
	$ cd Images-to-3D-OpenMVG-

Es sind folgende Programme notwending zu installieren bevor wir anfangen können.

 - Cmake
 - Git
 - c/c++ compiler ( gcc )   version >= 4.8.1


erforderliche externe Librarys werden installiert.

	$ sudo apt-get install libpng-dev libjpeg-dev libtiff-dev libxxf86vm1 libxxf86vm-dev 
	   libxrandr-dev


Dann hollen wir uns die OpenMVG Sources.

	$ git clone --recursive https://github.com/openMVG/openMVG.git
	$ mkdir openMVG_Build
	$ cd openMVG_Build

	$ cmake -DCMAKE_BUILD_TYPE=RELEASE . ../openMVG/src/


jetzt muss das Project compiliert werden

	$ make

oder mit multi-core compiliere. ( cores für die anzahl der Threads )

	$ make -j cores

MVE ist notwendig fuer das Programm
Um mve nutzen zu können müssen wir die Sources Compilen : 

	$ git clone https://github.com/simonfuhrmann/mve.git
	$ cd mve
	$ make -j cores


Jetzt beginnen wir mit dem eigentlichen Programm. Unsere Daten Struktur sollte jetzt wie folgt aussehen wenn wir den "res" ordner noch manuel hinzufügen, und im images ordner kommen unsere Bilder die gescannt werden.

	Images-to-3D-OpenMVG-
		|___mve
		|___openMVG
		|___openMVG_Build
		|___res
			|___images
			|___output
		|___src
