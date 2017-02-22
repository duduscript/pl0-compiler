pl0 : main.o Parse.o Vm.o Error.o Token.o Code.o Identifier.o \
		   Lexer.o Symbol.o ObjCode.o Word.o Num.o
	clang++ -std=c++11 -o $@ $^

Parse.o : ./src/xxx.cpp/Parse.cpp ./src/xxx.h/Parse.h \
		./src/xxx.h/Error.h ./src/xxx.h/Token.h ./src/xxx.h/Identifier.h
	clang++ -std=c++11 -c $< 

Vm.o : ./src/xxx.cpp/Vm.cpp ./src/xxx.h/Vm.h \
		./src/xxx.h/ObjCode.h ./src/xxx.h/Code.h
	clang++ -std=c++11 -c $< 

Error.o : ./src/xxx.cpp/Error.cpp ./src/xxx.h/Error.h
	clang++ -std=c++11 -c $< 

Token.o : ./src/xxx.cpp/Token.cpp ./src/xxx.h/Token.h
	clang++ -std=c++11 -c $< 

Code.o : ./src/xxx.cpp/Code.cpp  ./src/xxx.h/Code.h
	clang++ -std=c++11 -c $<

Identifier.o : ./src/xxx.cpp/Identifier.cpp  ./src/xxx.h/Identifier.h
	clang++ -std=c++11 -c $<

Lexer.o : ./src/xxx.cpp/Lexer.cpp ./src/xxx.h/Lexer.h ./src/xxx.h/Num.h\
		./src/xxx.h/Word.h ./src/xxx.h/Symbol.h ./src/xxx.h/Error.h
	clang++ -std=c++11 -c $<

Symbol.o : ./src/xxx.cpp/Symbol.cpp  ./src/xxx.h/Symbol.h
	clang++ -std=c++11 -c $< 

ObjCode.o : ./src/xxx.cpp/ObjCode.cpp  ./src/xxx.h/ObjCode.h ./src/xxx.h/Code.h
	clang++ -std=c++11 -c $< 

Word.o : ./src/xxx.cpp/Word.cpp  ./src/xxx.h/Word.h
	clang++ -std=c++11 -c $< 

Num.o : ./src/xxx.cpp/Num.cpp  ./src/xxx.h/Num.h ./src/xxx.h/Token.h ./src/xxx.h/Error.h
	clang++ -std=c++11 -c $< 

main.o : ./src/xxx.cpp/main.cpp ./src/xxx.h/Vm.h
	clang++ -std=c++11 -c $< 

clean:
	rm pl0 *.o
