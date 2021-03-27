# M5Stack-PixelArt

M5Stack-PixelArt is a sketch that displays pixel arts of Digimon on M5Stack.  
The source code was implemented using a test-driven approach with GoogleTest.
 
## DEMO
**M5Stack Sketch**  
![l9cjp-6j1ga](https://user-images.githubusercontent.com/14195687/112708203-175bf900-8ef4-11eb-89d4-b0fc42cc5d74.gif)

**Console Emulator**  
![degimon](https://user-images.githubusercontent.com/14195687/112707662-4ec8a680-8ef0-11eb-8fc9-325859c90ddf.gif)
 
## Requirement
 
* gcc 9.3.0
* GNU Make 4.2.1
* Cmake 3.16
* Arduino IDE
 
## Clone
```bash
$ git clone --recursive https://github.com/interimadd/M5Stack-PixelArt.git
$ cd M5Stack-PixelArt/
```

## Usage

**Build And Run Test**  
```bash
$ make test
set -x && cd test/build && cmake .. && make && ./m5stack-pixelart-test
       :
[----------] 4 tests from TestPixelArtM5stack
[ RUN      ] TestPixelArtM5stack.Init
[       OK ] TestPixelArtM5stack.Init (0 ms)
[ RUN      ] TestPixelArtM5stack.SetPixelArt
[       OK ] TestPixelArtM5stack.SetPixelArt (0 ms)
[ RUN      ] TestPixelArtM5stack.SetPixelArtWithSizeAndScale
[       OK ] TestPixelArtM5stack.SetPixelArtWithSizeAndScale (0 ms)
[ RUN      ] TestPixelArtM5stack.ButtonOperation
[       OK ] TestPixelArtM5stack.ButtonOperation (0 ms)
[----------] 4 tests from TestPixelArtM5stack (0 ms total)

[----------] Global test environment tear-down
[==========] 25 tests from 5 test cases ran. (1 ms total)
[  PASSED  ] 25 tests.
```

**Build And Run Console Emulator**  
```bash
$ make test
$ cd main/build/
/main/build$ ./console-pixelart
```

**Upload Sketch To M5Stack**  
Open M5Stack-PixelArt/pixel_art_m5stack/pixel_art_m5stack.ino with Arduino IDE and upload.
 
# References
**Pixel Art References**  
[デジタルモンスター Ver.20th ニューカラー3種 | デジモンウェブ | デジモン公式総合サイト](https://digimon.net/20th/)
