# SatelliteMovementManager
Library for sattelite controlling and simulating trajectory of its movement.   

# build instructions for linux with gcc

cd SatelliteMovementManager/SatteliteSimulator/

sudo mkdir build

cd build

sudo cmake ..

sudo make -j

# build instructions for linux with clang

cd SatelliteMovementManager/

sudo mv CMakelists_clang.txt CMakelists.txt

cd SatteliteSimulator/

sudo mkdir build

cd build

sudo cmake ..

sudo make -j

