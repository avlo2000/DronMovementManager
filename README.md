# SatelliteMovementManager
Library for sattelite controlling and simulating trajectory of its movement.   

# build instructions for linux with gcc

cd SatelliteMovementManager/SatteliteSimulator/

sudo mkdir build

cd build

sudo cmake ..

sudo make -j

# build instructions for linux with clang

cd SatelliteMovementManager/SatteliteSimulator/

sudo mv CMakeLists.txt CMakeLists.txt_back

sudo mv CMakeLists_clang.txt CMakeLists.txt

sudo mkdir build

cd build

sudo cmake ..

sudo make -j

