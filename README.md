# Multithreaded-App
Demo application that uses multiple threads.
Main window allows us to open other windows with spinning shapes by clicking coloured shapes.
Each sub window runs on different thread.
You can check process information and thread count by clicking gray buttons.
Info will be displayed in console-like window below the main panel.

## How can I run it?
### Requirements:
- CMake version 3.20
- MinGW-w64 (GCC 10.3)
- Windows OS (Linux not supported)

### Build process
1) Clone the repository by ```git clone```
2) Enter the repo directory and open Git Bash
3) ```mkdir build && cd build```
4) ```cmake -G "MinGW Makefiles" ..``` - cmake will set up everything for you<br>! Required library will be downloaded from GitHub automatically, so make sure you are connected to the internet !
5) Once complete, enter ```cmake --build .```
6) Executable will be placed in current directory (_./build_), you can directly run it by ```./MultithreadedApp.exe```
