# NetWorld - Game Engine for IAs competition



## Installation sour linux (Ubuntu):

**recomandé...**

Installer gcc, CMake et git:

Dans un terminal:

```bash
sudo apt update
sudo apt install gcc CMake
```

Installer Raylib sur la version 3.0.0 sous linux [[cf. raylib-wiki](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)] en suivant le 'Build raylib using CMake' un peut modifie suivant:

```bash
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
git checkout 3.0.0
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

Compiling NetWorld using a little home made script:

```bash
bin/make.sh
```

## Idée de jeux induit:


## Optimisation de routage dynamique (Pb. réseaux)

Générer des robots et les déplacer pour couvrir au mieux un réseaux.

- être résiliant aux pannes
- Réseau en constance augmentation
- Circonscrire les Zones defectueuse....

## WarBot
