CXX = g++
CXXFLAGS = -Wall

proj4: MailHouse.o driver.cpp 
	$(CXX) $(CXXFLAGS) MailHouse.o Package.o Letter.o Ups.o FedEx.o Carrier.o Mail.o  driver.cpp -o proj4

MailHouse.o: MailHouse.h MailHouse.cpp Carrier.o FedEx.o Ups.o Letter.o Package.o
	$(CXX) $(CXXFLAGS) -c MailHouse.cpp

Package.o: Package.h Package.cpp Mail.o
	$(CXX) $(CXXFLAGS) -c Package.cpp

Letter.o: Letter.h Letter.cpp Mail.o
	$(CXX) $(CXXFLAGS) -c Letter.cpp

Ups.o: Ups.h Ups.cpp Carrier.o
	$(CXX) $(CXXFLAGS) -c Ups.cpp

FedEx.o: FedEx.h FedEx.cpp Carrier.o
	$(CXX) $(CXXFLAGS) -c FedEx.cpp

Carrier.o: Carrier.h Carrier.cpp Mail.o
	$(CXX) $(CXXFLAGS) -c Carrier.cpp

Mail.o: Mail.h Mail.cpp
	$(CXX) $(CXXFLAGS) -c Mail.cpp

clean:
	rm*~

run:
	./proj4

run1:
	./proj4 proj4_t1.txt

run2:
	./proj4 proj4_t2.txt

run3:
	./proj4 proj4_t3.txt

run4:
	./proj4 proj4_t4.txt

val1:
	valgrind ./proj4 proj4_t1.txt

val2:
	valgrind ./proj4 proj4_t2.txt

val3:
	valgrind ./proj4 proj4_t3.txt

val4:
	valgrind ./proj4 proj4_t4.txt