config=`pkg-config --libs opencv`

all:
	g++ $(config) src/vision.cpp $(config) -o bin/VisionTracking

calibration:
	g++ $(config) src/calibration.cpp $(config) -o bin/calibrate

testalgorithms:
	g++ -Isrc src/target.h src/target.cpp test/TestAlgorithm.cpp -o bin/algorithmtest
