config=`pkg-config --libs opencv`

all:
	g++ $(config) -Isrc src/main.cpp src/target.cpp src/vision.cpp $(config) -o bin/VisionTracking

calibration:
	g++ $(config) src/calibration.cpp $(config) -o bin/calibrate

targettest:
	g++ $(config) -Isrc src/target.cpp src/vision.cpp test/target/TargetTest.cpp $(config) -o bin/TargetTest
