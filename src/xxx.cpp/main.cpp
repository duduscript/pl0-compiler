#include "parse.h"
#include "vm.h"

int main()
{
	Parse p("abc.txt");
	p.GrammerAnalyzier();
	Vm virtualMach(p.getCode());
	virtualMach.pl0();
	system("pause");
	return 0;
}
