all : demo

demo : min_stack.o
	g++ -o demo min_stack.o
	
min_stack.o : min_stack.cpp min_stack.hpp
	gcc -std=c++11 -g -c min_stack.cpp
	
.PHONY : clean
clean :
	rm -f *.o demo