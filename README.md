# MoonVeil

**MoonVeil** is a 2D game engine framework written in modern C++.  
It provides a component-based architecture to build dynamic, interactive gameplay with tile maps, camera control, audio, and scene management.

## 🎮 Features

- Object-oriented and modular C++ architecture
- Scene system with transitions (e.g., death screen, victory screen)
- Support for multiple characters (e.g., Galmar, David)
- Tile map loading from `.tmx` files
- Collision detection system
- Entity and object lifecycle management
- Parallel updates using C++ standard library execution policies
- HUD and game timer system
- Audio and background music support (via Raylib)

## 🛠 Technologies & Dependencies

- C++17 / C++20
- [Raylib](https://www.raylib.com/) — graphics, audio, input
- [Raygui](https://github.com/raysan5/raygui) — immediate-mode GUI for raylib
- [Raylib-TMX](https://github.com/RobLoach/raylib-tmx) — TMX tile map loader
- [SimpleINI](https://github.com/brofield/simpleini) — INI file parser for configuration
- CMake for build system
- STL and standard parallel algorithms
- Doxygen for documentation
