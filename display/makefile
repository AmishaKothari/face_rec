output: display.o
	g++ display.o -o output `pkg-config --cflags --libs opencv`
display.o: dispaly.cpp
	g++ -c dispaly.cpp -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

clean:
	rm *.o output
 
