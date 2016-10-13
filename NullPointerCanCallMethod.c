class A{
	int i;
public:
	int Foo(){
		return (int)this;
	}

	int GetData(){
		//segment fault for this pointer
		return this->i;
	}
};

int main(int argc, _TCHAR* argv[])
{
	//this == 0
	int addr = ((A *)0x0)->Foo();
	//this == 0x1000
	int data = ((A *)0x1000)->GetData();
	return 0;
}
