
class A{
public:
	int i;
	virtual int Foo(){
		return (int)this;
	}

	int GetData(){
		//segment fault for this pointer
		return this->i;
	}

	int GetOffset(){
		//this is ok.For not reading the value of the address
		return (int)&(this->i);
	}
};

int main(int argc, _TCHAR* argv[])
{
	int address = 0x1000;
	int offset = ((A*)address)->GetOffset();
	//this == 0
	int addr = ((A *)0x0)->Foo();
	//this == 0x1000
	int data = ((A *)0x1000)->GetData();
	return 0;
}
