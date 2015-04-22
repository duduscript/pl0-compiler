#include "parse.h"
#include "vm.h"

#include <string>

int main()
{
	string FileName;
	cin>>FileName;
	Parse p(FileName);
	p.GrammerAnalyzier();
	Vm virtualMach(p.getCode());
	virtualMach.pl0();
	system("pause");
	return 0;
}
