#include "../xxx.h/Parse.h"
#include "../xxx.h/Vm.h"

#include <string>

int main(int argc, char *argv[])
{
	std::string FileName = argv[1];
	Parse p(FileName);
	p.GrammerAnalyzier();
	Vm virtualMach(p.getCode());
	virtualMach.pl0();
	return 0;
}
