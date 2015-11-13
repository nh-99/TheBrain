config=`pkg-config --libs opencv`

all:
	g++ $(config) src/main.cpp $(config) -o bin/VisionTracking

calibration:
	g++ $(config) src/calibration.cpp $(config) -o bin/calibrate

imagelist:
	g++ $(config) tools/imagelist_creator.cpp $(config) -o bin/imagelist
