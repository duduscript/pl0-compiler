#include "Parse.h"
#include "Vm.h"

#include <iostream>
#include <string>

int main(int argc, char *argv[]){
	if (argc > 2 || argc == 1){
		std::cerr<<"Usage: ./a.out filepath"<<std::endl;
	} else {
		std::string FileName = argv[1];
		Parse p(FileName);
		p.GrammerAnalyzier();
		Vm virtualMach(p.getCode());
		virtualMach.pl0();
	}
	return 0;
}
