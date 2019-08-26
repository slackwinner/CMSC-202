CXX = g++
CXXFLAGS = -Wall

lab11: Registration.o lab11.cpp
	$(CXX) $(CXXFLAGS) Registration.o lab11.cpp -o lab11

Registration.o: Registration.h Registration.cpp
	$(CXX) $(CXXFLAGS) -c Registration.cpp

clean:
	rm *.o
	rm *~

run:
	./lab11