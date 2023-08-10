
TYPE
	TestStruct : 	STRUCT 
		command : BOOL;
		slider : REAL;
		random : REAL;
		struct2 : TestStruct1;
		struct3 : TestStruct1;
		struct1 : TestStruct1;
		myvalue : TestStruct3;
	END_STRUCT;
	TestStruct1 : 	STRUCT 
		struct1 : TestStruct2;
		struct2 : TestStruct2;
	END_STRUCT;
	TestStruct2 : 	STRUCT 
		member : BOOL;
		member1 : INT;
		member2 : DINT;
		member3 : STRING[80];
	END_STRUCT;
	TestStruct3 : 	STRUCT 
		x : REAL;
	END_STRUCT;
END_TYPE
