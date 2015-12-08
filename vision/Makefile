config=`pkg-config --libs opencv`

all:
	g++ $(config) src/vision.cpp $(config) -o bin/VisionTracking

calibration:
	g++ $(config) src/calibration.cpp $(config) -o bin/calibrate

test:
	g++ -o bin/testrunner -I$CXXTEST test/runner.cpp
