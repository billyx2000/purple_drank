# NetWorld - Game Engine for IAs competition

## Installation sour Linux (Ubuntu):

**Fortement recommandé...**

Installer gcc, CMake et git:

Dans un terminal:

```bash
sudo apt update
sudo apt install build-essential git cmake
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

Cloner NetWorld.


Installer Raylib sur la version 3.0.0 sous linux [[cf. raylib-wiki](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)] en suivant le 'Build raylib using CMake' un peut modifie suivant:

```bash
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
 git checkout '3.0.0'
mkdir build && cd build
cmake -DSHARED=ON -DSTATIC=ON ..
make
sudo make install
cd ..
```



First test of RayLib:

```bash
gcc -o nw-hello src/hello.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./nw-hello
```

Compiling NetWorld using a little home-made script:

```bash
bin/build.sh
```

## Installation sous Window :

**non recommandé**

Installer Minimalist GNU for Windows GCC tools' set ([MinGW](http://www.mingw.org/)) with the [setup UI](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/) program.
L'installer directement à la racine de votre système (C:).
Select the developer toolkit (that automatically include msys), base-bin, and gcc for C++. Ne pas oublier de faire un "installation>update changes".

Ajouter "C:\MinGW\bin" dans votre variable d'environnement PATH. (panneau de conifg. - système - param. système avancé - variable d'env. - PATH)

Installer [Git for Windows](https://gitforwindows.org/).

Installer VSC (Visual Studio Code), on utilisera son terminal PowerShell.

Rebooter la machine.

Installer Raylib sur la version 3.0.0 sous Window [[cf. raylib-wiki](https://github.com/raysan5/raylib)] en passant par la [release](https://github.com/raysan5/raylib/releases) pour MinGW.

- Télécharger la version 3.0.0 de RayLib pour [Win32 mingw](raylib-3.0.0-Win32-mingw.zip) (même sur une machine 64bit).
- Extraire et copier le contenu des repertoires bin include et lib respectivement dans les répertoires bin, include et lib se trouvant dans "C:\MinGW"
- copier "C:\MinGW\bin\libraylib.dll" en "C:\MinGW\bin\raylib.dll". 
Dans un terminal PowerShell:

```bash
cp C:\MinGW\bin\libraylib.dll C:\MinGW\bin\raylib.dll
```
Ouf...

On peut tester de compiler un premier programme hello.c avec raylib. Dans un terminal PowerShell:

```bash
gcc -o nw-hello src/hello.c -std=c99 -lraylib
./nw-hello
```

## Idée de jeux induits:


## Optimisation de routage dynamique (Pb. réseaux)

Générer des robots et les déplacer pour couvrir au mieux un réseau.

- être résiliant aux pannes
- Réseau en constance augmentation
- Circonscrire les Zones défectueuses....

## WarBot
