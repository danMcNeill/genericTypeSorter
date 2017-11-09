
# Here's the flag for C++11 support and a flag asking to be warned about
# everything. 
FLAGS = -Wall -std=c++11

all: Lab5T

Lab5T: Lab5T.o TesterClass.o
	g++ $(FLAGS) Lab5T.o TesterClass.o -o Lab5T

%.o: %.cpp
	g++ $(FLAGS) -c $^

clean:
	rm -f *.o Lab5T

