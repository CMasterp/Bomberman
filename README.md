<p align="center">
    <a><img src="./img/bomberman.gif" alt="[002]"></a>
</p>

# Indie Studio - Time to go cross-platform

- **Binary name:** bomberman
- **Language:** C++
- **Compilation:** CMake 3.17

# Subject

The aim of the Indie Studio is to implement a cross-platform 3D video game with real-world tools.

Making an enjoyable game is just as important as writing clean code.
A working game which is no fun to play is pointless!

> :speaking_head: Let’s be honest. Implementing a video game is generally not fun (at least not all the time). But it can be, and having someone else enjoy a game you made is an amazing feeling. The result will be worth the effort, so do your best! And most importantly, have fun.

You MUST use CMake as a cross-platform build system:
    • Linux: it must generates a Makefile to be able to build the project.
    • Windows: it must generates a Visual Studio solution .sln (will be tested with Visual Studio 2019).

You also must use the [raylib](!https://www.raylib.com/) library and use assets. We don’t want to see any fighting cubes! A CMake module for raylib is provided, you MUST use it to generate your project.

You may use Boost to help you with some aspects of the project (or for bonuses).

## Nao Marvin

| Details      | Nao Marvin :robot: (%) |
| ------------- |:-------------:|
| `blabla`: xxx% \| `blabla`: xxx% \| `blabla`: xxx% | xxx% |

## Prerequisites

What you need

```
C++ Library
g++
Graphics Library
cmake
```

### Resources

This repository only contain the source code.

All the resources useless during the CMake meta-compilation and the Makefile/MSVC compilation are placed on an another [Git Repository](https://github.com/Jose-JohnEm/indie-studio-ressources).

It is when we call the CMakeLists.txt on the root that we fetch resources as compressed file and decompress it to obtain all our resources (see [cmake/Findresources.cmake](https://github.com/EpitechIT2020/B-YEP-400-LYN-4-1-indiestudio-lucas.guichard/tree/feature_fetch/cmake)).

We fetch the compressed ressource archive from a SFTP Server. During the CMake step we check for new updates on this server; if there is a new version then we fetch from else we continue without fetching.

We wrote [Tarer.sh](https://github.com/EpitechIT2020/B-YEP-400-LYN-4-1-indiestudio-lucas.guichard/tree/script/tarer.sh) a bash script which compress the resources and send them to the SFTP Server.

To add new resources you have to use it at [the root of the resources Git Repository](https://github.com/Jose-JohnEm/indie-studio-ressources).
[ _sshpass is required_ ]
`$ sudo apt install sshpass`

**Note** : _Previously, we also put the resources on the source code repository but during the developpement they became too heavy (4 GB !!!) that we encouter a big (heavy_ :laughing:) _problem :_
_When we had a problem and we needed to clone all the project then we had to spent a lot of time only to fetch resources._
_That's why we didn't leave our resources here anymore_.

## Compiling

Clone the repository and go inside. Then,

```
$ mkdir build && cd build
$ cmake .. && cmake --build .
$ cp bomberman ../ && cd ../
$ ./bomberman

OR

$ cd build && cmake .. && cmake --build . -j && cp bomberman ../ && cd ../; ./bomberman
```

## Usage

```
∼/B-YEP-400> ./bomberman
```

## GAME

### BOMBERMAN

![Image of Bomberman](https://ih1.redbubble.net/image.1974098109.8245/st,small,507x507-pad,600x600,f8f8f8.jpg)

The game you must implement is a Bomberman-like game.
**Bomberman** is one of the most famous video games of all time. With over 70 franchises, ranging from the first version on MSX, ZX Spectrum and Sharp MZ-700 in 1983 to the lastest versions on modern consoles, over 10 million units have been sold.

Our gameplay reference is Neo Bomberman, released on the Neo Geo and MVS systems in 1997.

Here’s the required features :
    • Local multi-player with the possibility to play with a friend + AI’s controlled bots.
    • A main game menu (to start a new game or load an existing one).
    • Your game must feature 3D graphics but a 2D gameplay.
    • Your game must feature procedurally generated maps (random obstacles, random bonus...).
    • Save/Load a game.
    • Animation and sounds to give life to the game (especially during various interactions).
    • Think about bomb explosion, player walking, background music...
    • Some Power-ups (Bomb Up, Speed Up, Fire Up, Wall Pass).

The goal of this project is not only to code a video game, but it’s to code a fully finished video game. This means that the efforts you make to polish your game will count as much as the technical aspect.

Do your best to avoid clunky animations or graphical glitches, manage your camera in a way that the “outside” of the game is never visible, pay attention to game design, level design and sound design, add variations in ennemies and environnements, etc.

## TESTS

We have implemented tests with Google Tests, to use them you must compile the project like its explain in the compilation section.

Once this done, use these commands (at root of the project):

```
$ cd Tests
$ mkdir build && cd build
$ cmake .. && cmake --build .
$ cp test_bomberman .. && cd ../
$ ./test_bomberman

OR

$ cd Tests && cd build && cmake .. && cmake --build . && cp test_bomberman .. && cd ../; ./test_bomberman
```

## DOCUMENTATION

To see more check into the folder ./doc.

### XRay

...

> :speaking_head: We had to hit this project
