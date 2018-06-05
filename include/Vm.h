#ifndef VM_H
#define VM_H

class ObjCode;

class Vm
{
public:
	Vm(ObjCode&);
	~Vm();
	void pl0();
private:
	Vm(const Vm&)=delete;
	Vm& operator=(const Vm&)=delete;
	ObjCode& objCode;
};

#endif // VM_H
