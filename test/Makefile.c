
all:
	$(CXX) -O2 -std=c++11 main.cpp ../src/*.cpp -o test -I ../include

test:
	 ./test || exit 1
