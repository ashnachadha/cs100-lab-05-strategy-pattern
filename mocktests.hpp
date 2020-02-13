class SevenOpMock: public Base {
	public:
		SevenOpMock() {}

		virtual double evaluate() { return 7.5; }
		virtual string stringify() { return "7.5"; }
}

class ZeroOpMock: public Base {
	public:
		ZeroOpMock() {}
		
		virtual double evaluate() { return 0.0; }
		virtual string stringify() { return "0.0"; }
}

class NegOpMock: public Base {
	public:
		NegOpMock() {}
		
		virtual double evaluate() { return -5.0; }
		virtual string stringify() { return "-5.0"; }
}

