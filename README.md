# NetWorld - Game Engine for IAs competition

NetWorld se veut devenir un moteur de jeux  KISS  (Keep It Stupid Simple) basés sur la librairie multi-plateforme RayLib.
La particularité du projet est de modéliser le monde comme un réseau de positions clés sur lesquelles peuvent de baller les entités en interaction.

## Installation


Projet conçu pour une compilation avec GCC et la librairie Raylib.


### Dépendance sous Linux (Ubuntu):


**Fortement recommandé...**


Installer gcc, CMake et git:


Dans un terminal:


```bash
sudo apt update
sudo apt install build-essential git cmake
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```


Installer Raylib sur la version 3.0.0


**Méthode avec compilation de la Raylib:**


En suivant le tutoriel pour linux [[cf. raylib-wiki](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)], avec un 'Build raylib using CMake' un peut modifié:


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


Vous pouvez optionnellement détruire le repo.


```bash
rm -fr raylib
```


### Dépendance sous Window :


**Non recommandé**


Installer Minimalist GNU for Windows GCC tools' set ([MinGW](http://www.mingw.org/)) with the [setup UI](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/) program.
L'installer directement à la racine de votre système (C:).
Select the developer toolkit (that automatically include msys), base-bin, and gcc for C++. Ne pas oublier de faire un "installation>update changes".


Ajouter "C:\MinGW\bin" dans votre variable d'environnement *PATH* (panneau de conifg. - système - param. système avancé - variable d'env. - *PATH*). Cette variables regroupe l'ensemble des chemins aux bous desquels le système peut trouver ces ressources.


Installer [Git for Windows](https://gitforwindows.org/). On utilisera notamment son invite de commande *git-bash* comme terminal.


Installer Raylib sur la version 3.0.0 sous Window [[cf. raylib-wiki](https://github.com/raysan5/raylib)] en passant par la [release](https://github.com/raysan5/raylib/releases) pour MinGW.


- Télécharger la version 3.0.0 de RayLib pour [Win32 mingw](https://github.com/raysan5/raylib/releases/download/3.0.0/raylib-3.0.0-Win32-mingw.zip) (même sur une machine 64bit).
- Extraire et copier le contenu des repertoires bin include et lib respectivement dans les répertoires bin, include et lib se trouvant dans "C:\MinGW"
- Copier "C:\MinGW\bin\libraylib.dll" en "C:\MinGW\bin\raylib.dll". 


Dans le terminal (git-bash):


```bash
cp C:\MinGW\bin\libraylib.dll C:\MinGW\bin\raylib.dll
```


On aura aussi besoin du programme *make* qui permet d'automatiser le processus de construction d'un projet. Il est déjà installé, mais sous le nom de '*C:\MinGW\bin\mingw32-make.exe*'


Dans le terminal (git-bash):


```bash
cp C:\MinGW\bin\mingw32-make.exe C:\MinGW\bin\make.exe
```


Rebooter la machine (pour notamment prendre en charge le nouveau *PATH*).


Ouf...



### Tester l'installation:


Récupérer l'[exemple](https://www.raylib.com/examples.html) basic de Raylib en copiant le code dans un fichier '*main-basic.c*'


Puis compiler dans votre terminal:


```bash
gcc -o basic-raylib main-basic.c -std=c99 -Wall -Wextra -lraylib
```
Un exécutable est normalement généré:


```bash
./basic-raylib
```


### Compiler NetWorld


Ya plus qu'à cloner et compiler NetWorld:


```bash
git clone ssh://git@gvipers.imt-lille-douai.fr:2222/fatus/networld.git NetWorld
cd NetWorld
make
```


Des exécutables sont générés au format *nw-xxxx*.



## Organisation du répertoire


Répertoire:


- *bin* : stocke de scripts pour automatiser des procédures utiles au projet.
- *.git* : répertoire de gestion de version propre à git.
- *src* : le code source du projet.
- *doc* : la documentation du projet.


Fichier à la racine:


- *.gitignore* : fichier de configuration git listant les ressources à ne pas versionner.
- *config* : Fichier de configuration pour le make (cf. *src/Makefile*).
- *config.default* : Fichier *config* utilisé à défaut (cf. *Makefile*).
- *Makefile* : Instruction de construction du projet pour *make*. Génère *config* et fait appel à *src/Makefile*.
- *projet-outline.md* : Un descriptif des composants logiciel réalisé et prévu.
- *nw-xxxx* : Les exécutables de NetWorld.
- *README,md* : Votre serviteur.



## Idée de jeux induits:



## Optimisation de routage dynamique (Pb. réseau)


Générer des robots et les déplacer pour couvrir au mieux un réseau.


- être résiliant aux pannes
- Réseau en constance augmentation
- Circonscrire les Zones défectueuses....


## WarBot


Des équipes de robots cherchent à s'entre-tuer.


## OpenDrive


Course de véhicule en environnement ouvert et dynamique. (Avec des aspects de dynamique des véhicules quasiment absents, mais la nécessité de prendre en compte aux mieux les autres véhicules pour optimiser sont choix de chemins).

## ...