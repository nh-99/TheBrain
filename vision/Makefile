config=`pkg-config --libs opencv`

all:
	g++ $(config) src/vision.cpp $(config) -o bin/VisionTracking

calibration:
	g++ $(config) src/calibration.cpp $(config) -o bin/calibrate

testmain:
	g++ -Isrc/vision.h src/vision.cpp $(config) src/main.cpp $(config) -o bin/main

testalgorithms:
	g++ -Isrc src/target.h src/target.cpp test/TestAlgorithm.cpp -o bin/algorithmtest
