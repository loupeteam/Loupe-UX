
{REDUND_OK} FUNCTION_BLOCK MTLookUpTable (*Lookup table.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enable function block.*)
		NodeVectorX : ARRAY[0..49] OF REAL; (*Lookup table points on the X-Axis*)
		FcnValues : ARRAY[0..49] OF REAL; (*Lookup table points on the Y-Axis*)
		NumberOfNodes : USINT; (*Number of nodes from the node vector that are used to define the point-to-point linear function 'f(x)'. Valid value range: NumberOfNodes >= 0.*)
		Update : BOOL; (*Changes to NumberOfNodes, Invert and the node vector listed above only go into effect at the positive edge of Update.*)
		Mode : MTLookUpModeEnum; (*Mode to calculate the function values if the X-axis values lies byond the range of defined nodes.*)
		InX : REAL; (*Abscissa value of 'f(x)' or 'f-1(x)'. Valid value range: X1 <= x <= Xn or Y1 <= x <= Yn.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Error occured.*)
		StatusID : DINT; (*Function block status information.*)
		UpdateDone : BOOL; (*Update done.*)
		Out : REAL; (*Ordinate value of 'f(x)' or 'f-1(x)'.*)
	END_VAR
	VAR
		Internal : MTLookUpTableInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} FUNCTION_BLOCK MTLookUpTable2D (*2D lookup table.*) (* $GROUP=mapp Control,$CAT=Control Tools,$GROUPICON=Icon_mapp.png,$CATICON=Icon_MpControlTools.png *)
	VAR_INPUT
		Enable : BOOL; (*Enable function block.*)
		NodeVectorX : ARRAY[0..19] OF REAL; (*Lookup table points on the X-Axis*)
		NodeVectorY : ARRAY[0..19] OF REAL; (*Lookup table points on the Y-Axis*)
		FcnValues : ARRAY[0..19,0..19] OF REAL; (*Lookup table points on the Z-Axis*)
		NumberOfNodesX : USINT; (*Number of nodes from the node vector that are used to define the 2D-function 'f(x,y)'. Valid value range: 21> NumberOfNodesX > 1.*)
		NumberOfNodesY : USINT; (*Number of nodes from the node vector that are used to define the 2D-function 'f(x,y)'. Valid value range: 21 > NumberOfNodesY > 1.*)
		Update : BOOL; (*Changes to NumberOfNodesX, NumberOfNodesY and the node vector listed above only go into effect at the positive edge of Update.*)
		InX : REAL; (*x-coordinate of 'f(x,y)'. Valid value range: X1 <= x <= Xj.*)
		InY : REAL; (*y-coordinate of 'f(x,y)'. Valid value range: Y1 <= y <= Yk.*)
	END_VAR
	VAR_OUTPUT
		Active : BOOL; (*Function block is active.*)
		Error : BOOL; (*Error occured.*)
		StatusID : DINT; (*Function block status information.*)
		UpdateDone : BOOL; (*Update done.*)
		Out : REAL; (*z-coordinate of 'z=f(x,y)'.*)
	END_VAR
	VAR
		Internal : MTLookUpTable2DInternalType; (*Data for internal use.*)
	END_VAR
END_FUNCTION_BLOCK
