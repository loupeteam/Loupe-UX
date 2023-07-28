
TYPE
	MTLookUpTable2DInternalType : 	STRUCT  (*Internal variables of function block MTLookUpTable2D().*)
		CycleTime : REAL; (*Task cycle time. Unit: [s].*)
		ParametersValid : {REDUND_UNREPLICABLE} BOOL; (*Data for internal use.*)
		NumberOfNodesX : {REDUND_UNREPLICABLE} USINT; (*Data for internal use.*)
		NumberOfNodesY : {REDUND_UNREPLICABLE} USINT; (*Data for internal use.*)
		CoordinateOrderX : SINT; (*Data for internal use.*)
		CoordinateOrderY : SINT; (*Data for internal use.*)
		InX : REAL; (*Data for internal use.*)
		InY : REAL; (*Data for internal use.*)
		DisModeX : SINT; (*Data for internal use.*)
		DisModeY : SINT; (*Data for internal use.*)
		UpdateOld : BOOL; (*Data for internal use.*)
		EnableOld : {REDUND_UNREPLICABLE} BOOL; (*Data for internal use.*)
		Nodes : REFERENCE TO MTLookUpInternalNode2DType; (*Data for internal use.*)
	END_STRUCT;
	MTLookUpInternalNode2DType : 	STRUCT  (*Internal variables of a linearization node*)
		XValues : REAL;
		YValues : REAL;
		FcnValues : REAL;
		k : ARRAY[0..1]OF REAL;
	END_STRUCT;
	MTLookUpInternalNodeType : 	STRUCT  (*Internal variables of a linearization node*)
		XValues : REAL;
		FcnValues : REAL;
		k : REAL;
		d : REAL;
	END_STRUCT;
	MTLookUpTableInternalType : 	STRUCT  (*Internal variables of function block MTLookUpTable().*)
		CycleTime : REAL; (*Task cycle time. Unit: [s].*)
		ParametersValid : BOOL; (*Data for internal use.*)
		NumberOfNodes : USINT; (*Data for internal use.*)
		CoordinateOrder : SINT; (*Data for internal use.*)
		InX : REAL; (*Data for internal use.*)
		DisMode : SINT; (*Data for internal use.*)
		UpdateOld : BOOL; (*Data for internal use.*)
		EnableOld : BOOL; (*Data for internal use.*)
		Nodes : ARRAY[0..49]OF MTLookUpInternalNodeType; (*Data for internal use.*)
		Mode : MTLookUpModeEnum; (*Data for internal use.*)
	END_STRUCT;
	MTLookUpModeEnum : 
		(
		mtLOOKUP_CONSTANT_END_VALUE := 0, (*Außerhalb des Stützstellenbereichs werden die Randwerte konstant gehalten.*)
		mtLOOKUP_LINEAR_EXTRAPOLATION := 1 (*Außerhalb des Stützstellenbereichs wird anhand der beiden linken oder beiden rechten Randwerte linear extrapoliert.*)
		);
END_TYPE
