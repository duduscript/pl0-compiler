a : main.o Parse.o Vm.o Error.o Token.o Code.o Identifier.o \
		   Lexer.o Symbol.o ObjCode.o Word.o Num.o
	g++ -std=c++11 -o a main.o Parse.o Vm.o Error.o Token.o Code.o Identifier.o Lexer.o Symbol.o ObjCode.o Word.o Num.o

Parse.o : ./src/xxx.cpp/Parse.cpp ./src/xxx.h/Parse.h ./src/xxx.h/Error.h ./src/xxx.h/Token.h ./src/xxx.h/Identifier.h
	g++ -std=c++11 -c ./src/xxx.cpp/Parse.cpp

Vm.o : ./src/xxx.cpp/Vm.cpp ./src/xxx.h/Vm.h ./src/xxx.h/ObjCode.h ./src/xxx.h/Code.h
	g++ -std=c++11 -c ./src/xxx.cpp/Vm.cpp

Error.o : ./src/xxx.cpp/Error.cpp ./src/xxx.h/Error.h
	g++ -std=c++11 -c ./src/xxx.cpp/Error.cpp

Token.o : ./src/xxx.cpp/Token.cpp ./src/xxx.h/Token.h
	g++ -std=c++11 -c ./src/xxx.cpp/Token.cpp

Code.o : ./src/xxx.cpp/Code.cpp  ./src/xxx.h/Code.h
	g++ -std=c++11 -c ./src/xxx.cpp/Code.cpp

Identifier.o : ./src/xxx.cpp/Identifier.cpp  ./src/xxx.h/Identifier.h
	g++ -std=c++11 -c ./src/xxx.cpp/Identifier.cpp

Lexer.o : ./src/xxx.cpp/Lexer.cpp ./src/xxx.h/Lexer.h ./src/xxx.h/Num.h\
		./src/xxx.h/Word.h ./src/xxx.h/Symbol.h ./src/xxx.h/Error.h
	g++ -std=c++11 -c ./src/xxx.cpp/Lexer.cpp

Symbol.o : ./src/xxx.cpp/Symbol.cpp  ./src/xxx.h/Symbol.h
	g++ -std=c++11 -c ./src/xxx.cpp/Symbol.cpp

ObjCode.o : ./src/xxx.cpp/ObjCode.cpp  ./src/xxx.h/ObjCode.h ./src/xxx.h/Code.h
	g++ -std=c++11 -c ./src/xxx.cpp/ObjCode.cpp

Word.o : ./src/xxx.cpp/Word.cpp  ./src/xxx.h/Word.h
	g++ -std=c++11 -c ./src/xxx.cpp/Word.cpp

Num.o : ./src/xxx.cpp/Num.cpp  ./src/xxx.h/Num.h ./src/xxx.h/Token.h ./src/xxx.h/Error.h
	g++ -std=c++11 -c ./src/xxx.cpp/Num.cpp

main.o : ./src/xxx.cpp/main.cpp ./src/xxx.h/Vm.h
	g++ -std=c++11 -c ./src/xxx.cpp/main.cpp

clean:
	rm a *.o
