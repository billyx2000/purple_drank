# NetWorld - Game Engine for IAs competition



## Installation sour linux (Ubuntu):

**recomandé...**

Installer gcc, CMake et git:

Dans un terminal:

```bash
sudo apt update
sudo apt install gcc CMake
```

Installer Raylib sous linux [[cf. raylib-wiki](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)] en suivant le 'Build raylib using CMake':

```bash
git clone https://github.com/raysan5/raylib.git raylib
cd raylib
mkdir build && cd build
cmake -DSHARED=ON -DSTATIC=ON ..
make
make install
cd ..
```

First test of RayLib:

```bash
gcc -o nw-test src/test.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./nw-test
```

With CMake:


```bash
mkdir build
cd build
cmake ..
make
./nw-test
```

## Idée de jeux induit:


## Optimisation de routage dynamique (Pb. réseaux)

Générer des robots et les déplacer pour couvrir au mieux un réseaux.

- être résiliant aux pannes
- Réseau en constance augmentation
- Circonscrire les Zones defectueuse....

## WarBot
