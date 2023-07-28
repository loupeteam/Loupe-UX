
{REDUND_OK} FUNCTION_BLOCK LCRPID (* PID controller. *)
	VAR_INPUT
		enable : BOOL;
		ident : {REDUND_UNREPLICABLE} UDINT;
		W : REAL;
		X : REAL;
		Y_max : REAL;
		Y_min : REAL;
		A : REAL;
		Y_man : REAL;
		Y_fbk : REAL;
		hold_I : BOOL;
		mode : USINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		e : REAL;
		Y : REAL;
		Yp : REAL;
		Yi : REAL;
		Yd : REAL;
	END_VAR
	VAR
		Set_Yi : BOOL;
		Yi_set : REAL;
		force_Yi : BOOL;
		Yi_min : REAL;
		Yi_max : REAL;
		joltFreeDoneLowerLim : BOOL;
		joltFreeDoneUpperLim : BOOL;
		Yi_minInternal : REAL;
		Yi_maxInternal : REAL;
		Tv_Tf_old : REAL;
		enable_old : BOOL;
		e_old : REAL;
		deadband_state : UINT;
		sysinfo_inst : {REDUND_UNREPLICABLE} SysInfo;
		scal_inst : LCRScal;
		store1 : {REDUND_UNREPLICABLE} UDINT;
		store2 : {REDUND_UNREPLICABLE} UDINT;
		timeCnt : {REDUND_UNREPLICABLE} UDINT;
		musecs_old : {REDUND_UNREPLICABLE} UINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRScal (* Scaling of REAL signals. *)
	VAR_INPUT
		x : REAL;
		x1 : REAL;
		y1 : REAL;
		x2 : REAL;
		y2 : REAL;
	END_VAR
	VAR_OUTPUT
		y : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRCurveByPoints (* y=f(x) function using coordinates. *)
	VAR_INPUT
		x : REAL;
		NoOfPoints : UINT;
		ptr_table : REFERENCE TO lcrCurveByPoints_TabEntry_type;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		y : REAL;
	END_VAR
	VAR
		i_tab : INT;
		iterations : UINT;
		scal1 : LCRScal;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRPIDpara (* Manual configuration of the PID controller. *)
	VAR_INPUT
		enable : BOOL;
		enter : BOOL;
		WX_max : REAL;
		WX_min : REAL;
		invert : BOOL;
		deadband : REAL;
		deadband_mode : USINT;
		dY_max : REAL;
		Kp : REAL;
		Tn : REAL;
		Tv : REAL;
		Tf : REAL;
		Kw : REAL;
		Kfbk : REAL;
		fbk_mode : USINT;
		d_mode : USINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		ident : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
	VAR
		internal_data : lcrpid_internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRContinServo (* Control of a continuous servo drive without position feedback. *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		max_value : REAL;
		min_value : REAL;
		t_impulse : REAL;
		t_change_up : REAL;
		t_change_down : REAL;
		ref : BOOL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		up : BOOL;
		down : BOOL;
		hysteresis_up : REAL;
		hysteresis_down : REAL;
		refOk : BOOL;
	END_VAR
	VAR
		enable_old : BOOL;
		counter_state : UINT;
		bootkey_old : {REDUND_UNREPLICABLE} UDINT;
		systicks_old : {REDUND_UNREPLICABLE} UDINT;
		musecs_old : {REDUND_UNREPLICABLE} UINT;
		ref_old : BOOL;
		t_cnt_1 : DINT;
		t_cnt_2 : DINT;
		y_dbl_1 : DINT;
		y_dbl_2 : DINT;
		sysInfo_inst : {REDUND_UNREPLICABLE} SysInfo;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRPT1 (* First-order delay element, see LCRPT1e(). *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		t : REAL;
		y_set : REAL;
		set : BOOL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		y : REAL;
	END_VAR
	VAR
		counter_state : UINT;
		bootkey_old : {REDUND_UNREPLICABLE} UDINT;
		systicks_old : {REDUND_UNREPLICABLE} UDINT;
		musecs_old : {REDUND_UNREPLICABLE} UINT;
		y_dbl_1 : DINT;
		y_dbl_2 : DINT;
		sysinfo_inst : {REDUND_UNREPLICABLE} SysInfo;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRRamp (* Ramp generator. *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		dy_up : REAL;
		dy_down : REAL;
		y_max : REAL;
		y_min : REAL;
		y_set : REAL;
		set : BOOL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		y : REAL;
		x_reached : BOOL;
		max_limit : BOOL;
		min_limit : BOOL;
	END_VAR
	VAR
		y_dbl_1 : DINT;
		y_dbl_2 : DINT;
		timestore1 : UDINT;
		timestore2 : UDINT;
		getDtForceOff : UDINT;
		sysinfo_inst : {REDUND_UNREPLICABLE} SysInfo;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRIntegrate (* Integrator with limits and set value. *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		tn : REAL;
		y_max : REAL;
		y_min : REAL;
		y_set : REAL;
		set : BOOL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		y : REAL;
		max_limit : BOOL;
		min_limit : BOOL;
	END_VAR
	VAR
		counter_state : UINT;
		bootkey_old : {REDUND_UNREPLICABLE} UDINT;
		systicks_old : {REDUND_UNREPLICABLE} UDINT;
		musecs_old : {REDUND_UNREPLICABLE} UINT;
		y_dbl_1 : DINT;
		y_dbl_2 : DINT;
		sysinfo_inst : {REDUND_UNREPLICABLE} SysInfo;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRLimit (* Limiter with overrun indicators. *)
	VAR_INPUT
		in : REAL;
		max_value : DINT;
		min_value : DINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		out : DINT;
		max_limit : BOOL;
		min_limit : BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRLimScal (* Scaling and limiting of REAL signals. *)
	VAR_INPUT
		x : REAL;
		x1 : REAL;
		y1 : REAL;
		x2 : REAL;
		y2 : REAL;
	END_VAR
	VAR_OUTPUT
		y : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRPWM (* Pulse width modulator (can also be used as pulse frequency modulator). *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		max_value : REAL;
		min_value : REAL;
		t_min_pulse : REAL;
		t_period : REAL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		pulse : BOOL;
		t_on : REAL;
		t_off : REAL;
	END_VAR
	VAR
		cnt_terron_1 : DINT;
		cnt_terron_2 : DINT;
		cnt_terroff_1 : DINT;
		cnt_terroff_2 : DINT;
		cnt_t_pulse_1 : DINT;
		cnt_t_pulse_2 : DINT;
		store1 : UDINT;
		store2 : UDINT;
		timeCnt : UDINT;
		sysinfo_inst : SysInfo;
		corr : BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRMovAvgFlt (* Floating average value filter. *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		base : UINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		y : REAL;
	END_VAR
	VAR
		sum_old_dbl_1 : DINT;
		sum_old_dbl_2 : DINT;
		p_xold : {REDUND_UNREPLICABLE} UDINT;
		i_xold : UINT;
		base_old : {REDUND_UNREPLICABLE} UINT;
		enable_old : {REDUND_UNREPLICABLE} BOOL;
		bootkey_old : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRTimeBasedOnOff (* 3-position step output, see LCRContinServo(). *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		max_value : REAL;
		min_value : REAL;
		timpulse : REAL;
		tchange_up : REAL;
		tchange_down : REAL;
		ref : BOOL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		up : BOOL;
		down : BOOL;
		hysteresis_up : REAL;
		hysteresis_down : REAL;
		refOk : BOOL;
	END_VAR
	VAR
		enable_old : BOOL;
		counter_state : UINT;
		bootkey_old : UDINT;
		systicks_old : UDINT;
		musecs_old : UINT;
		ref_old : BOOL;
		t_cnt_1 : DINT;
		t_cnt_2 : DINT;
		y_dbl_1 : DINT;
		y_dbl_2 : DINT;
		sysInfo_inst : SysInfo;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRDifferentiate (* Differentiator with filter. *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		tv : REAL;
		tf : REAL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		y : REAL;
	END_VAR
	VAR
		store1 : {REDUND_UNREPLICABLE} UDINT;
		store2 : {REDUND_UNREPLICABLE} UDINT;
		timeCnt : {REDUND_UNREPLICABLE} UDINT;
		counter_state : UINT;
		bootkey_old : {REDUND_UNREPLICABLE} UDINT;
		systicks_old : {REDUND_UNREPLICABLE} UDINT;
		musecs_old : {REDUND_UNREPLICABLE} UINT;
		sysinfo_inst : {REDUND_UNREPLICABLE} SysInfo;
		a11 : DINT;
		a12 : DINT;
		a21 : DINT;
		a22 : DINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRSlimPID (* PID controller with integrated tuning. *)
	VAR_INPUT
		enable : BOOL;
		W : REAL;
		X : REAL;
		request : UDINT;
		pPar : REFERENCE TO lcrslimpid_par_typ;
	END_VAR
	VAR_OUTPUT
		e : REAL;
		Y : REAL;
		status : UINT;
		addInfo : UINT;
	END_VAR
	VAR
		MovAvgFlt_inst : LCRMovAvgFlt;
		PIDTune_inst : LCRPIDTune;
		PID_inst : LCRPID;
		enable_old : BOOL;
		requ_old : UDINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRPIDTune (* Automatically determines the control parameters for an LCRPID() instance with different methods. *)
	VAR_INPUT
		enable : BOOL;
		Y_min : REAL;
		Y_max : REAL;
		Y0 : REAL;
		Y1 : REAL;
		okToStep : BOOL;
		X0 : REAL;
		X_min : REAL;
		X_max : REAL;
		P_manualAdjust : INT;
		I_manualAdjust : INT;
		D_manualAdjust : INT;
		request : UDINT;
		pAddPar : REFERENCE TO lcrpid_tune_addpar_typ;
		pOptions_osc : REFERENCE TO lcrpid_tune_osc_options_typ;
		pOptions_step : REFERENCE TO lcrpid_tune_step_options_typ;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		addInfo : UINT;
		ident : UDINT;
		state : UINT;
		rdyToStep : BOOL;
	END_VAR
	VAR
		t_autotune : REAL;
		status_tmp : UINT;
		counter_state : UINT;
		bootkey_old : UDINT;
		systicks_old : UDINT;
		musecs_old : UINT;
		curveDown : BOOL;
		e : REAL;
		e_minAmp : REAL;
		e_old_up : REAL;
		e_old_down : REAL;
		curveUp : BOOL;
		e_old : REAL;
		sysinfo_inst : SysInfo;
		MovAvgFlt_inst : LCRMovAvgFlt;
		old : lcrpid_old_typ;
		processPar : lcrpid_procPar_typ;
		internal_data : lcrpid_internal_typ;
		addPar : lcrpid_tune_addpar_typ;
		oscillation : lcrpid_tune_osc_typ;
		stepresponse : lcrpid_tune_step_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRPFM (* Pulse frequency modulator. *)
	VAR_INPUT
		enable : BOOL;
		x : REAL;
		max_value : REAL;
		min_value : REAL;
		t_pulse : REAL;
		t_pause : REAL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		pulse : BOOL;
	END_VAR
	VAR
		area : REAL;
		area_c : REAL;
		range : REAL;
		last : REAL;
		tpls : REAL;
		enable_old : BOOL;
		counter_state : UINT;
		bootkey_old : UDINT;
		systicks_old : UDINT;
		musecs_old : UINT;
		sysinfo_inst : SysInfo;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRSimModExt (* Thermal simulation model of an extruder with heating zones and cooling circulation. *)
	VAR_INPUT
		enable : BOOL;
		Tt_h : DINT;
		Tt_c : DINT;
		k_h : REAL;
		k_c : REAL;
		PT2_T1 : REAL;
		PT2_T2 : REAL;
		Temp_amb : REAL;
		Temp_c : REAL;
		Alpha_h : REAL;
		Alpha_c : REAL;
	END_VAR
	VAR_OUTPUT
		y : REAL;
		status : UINT;
	END_VAR
	VAR
		Tt_heat : LCRTt;
		Tt_cool : LCRTt;
		k_h_intern : REAL;
		k_c_intern : REAL;
		PT2 : LCRPT2;
		y_c : REAL;
		y_end : REAL;
		y_h : REAL;
		Bootkey : UDINT;
		enable_old : BOOL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRTt (* Delay time. *)
	VAR_INPUT
		enable : BOOL;
		Tt : DINT;
		x : REAL;
		y_set : REAL;
		set : BOOL;
	END_VAR
	VAR_OUTPUT
		y : REAL;
		status : UINT;
	END_VAR
	VAR
		Ts : DINT;
		Tt_Max : DINT;
		pRingBuf : {REDUND_UNREPLICABLE} REFERENCE TO REAL;
		pBuf_OutIn : {REDUND_UNREPLICABLE} REFERENCE TO REAL;
		set_old : USINT;
		Set_y : USINT;
		enable_old : {REDUND_UNREPLICABLE} BOOL;
		Bootkey : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRPT2 (* Second-order delay element. *)
	VAR_INPUT
		enable : BOOL;
		V : REAL;
		T1 : REAL;
		T2 : REAL;
		x : REAL;
		y_set : REAL;
		set : USINT;
	END_VAR
	VAR_OUTPUT
		y : REAL;
		status : UINT;
	END_VAR
	VAR
		x1_dbl_1 : UDINT;
		x1_dbl_2 : UDINT;
		x2_dbl_1 : UDINT;
		x2_dbl_2 : UDINT;
		Ts : DINT;
		Ts_dbl_1 : UDINT;
		Ts_dbl_2 : UDINT;
		set_old : USINT;
		Set_y : USINT;
		Bootkey : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRPT1e (* First-order delay element. *)
	VAR_INPUT
		enable : BOOL;
		V : REAL;
		T1 : REAL;
		x : REAL;
		y_set : REAL;
		set : USINT;
	END_VAR
	VAR_OUTPUT
		y : REAL;
		status : UINT;
	END_VAR
	VAR
		x1_dbl_1 : UDINT;
		x1_dbl_2 : UDINT;
		Ts : DINT;
		Ts_dbl_1 : UDINT;
		Ts_dbl_2 : UDINT;
		set_old : USINT;
		Set_y : USINT;
		Bootkey : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRDblActPID (* PID controller with two outputs for two opposing manipulated variables and integrated tuning. *)
	VAR_INPUT
		enable : BOOL;
		W : REAL;
		X : REAL;
		Y_man : REAL;
		hold_I : BOOL;
		mode : USINT;
		okToStep : BOOL;
		pPar1 : REFERENCE TO lcrdblpid_par_typ;
		pPar2 : REFERENCE TO lcrdblpid_par_typ;
		pAddPar : REFERENCE TO lcrpid_tune_addpar_typ;
		pOpt : REFERENCE TO lcrdblpid_tune_typ;
	END_VAR
	VAR_OUTPUT
		e : REAL;
		Y1 : REAL;
		Y2 : REAL;
		status : UINT;
		tuneState : USINT;
		rdyToStep : BOOL;
	END_VAR
	VAR
		enable_old : BOOL;
		pid : LCRPID;
		tune : LCRPIDTune;
		sysinfo_inst : SysInfo;
		gradient : REAL;
		Y_avg : REAL;
		tcnt_1 : UDINT;
		tcnt_2 : UDINT;
		Tmeas : REAL;
		y_lim_old : REAL;
		p_fact : REAL;
		bootkey_old : UDINT;
		systicks_old : UDINT;
		musecs_old : UINT;
		use_par : USINT;
		meas : USINT;
		mode_old : USINT;
		tune_step : USINT;
		tune_grad : USINT;
		tune_2nd : USINT;
		invert : USINT;
		counter_state : USINT;
		mode_int : USINT;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRMinMax (* Smallest and largest peak value. *)
	VAR_INPUT
		reset : BOOL;
		in : REAL;
	END_VAR
	VAR_OUTPUT
		out_min : REAL;
		out_max : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRTempPID (* PID controller especially for temperature systems. *)
	VAR_INPUT
		enable : BOOL;
		Temp_set : REAL;
		Temp : REAL;
		Y_man : REAL;
		mode : UDINT;
		update : BOOL;
		pSettings : REFERENCE TO lcrtemp_set_typ;
	END_VAR
	VAR_OUTPUT
		y_heat : REAL;
		y_cool : REAL;
		status : UINT;
	END_VAR
	VAR
		pid : LCRPID;
		pid_para : LCRPIDpara;
		Temp_set_delay : REAL;
		Temp_set_int : REAL;
		TempSetOld : REAL;
		delayCnt : REAL;
		delayFlag : BOOL;
		enable_old : BOOL;
		stateOld : SINT;
		state : SINT;
		a : REAL;
		sysinfo_inst : SysInfo;
		para_check_done : USINT;
		internal_para : lcrtemp_pid_internal_typ;
		dbl_dt : REAL;
		tAlt : REAL;
		altTime : REAL;
		tKnick : REAL;
		fAlt : REAL;
		altActive : BOOL;
		a_alt : REAL;
		a_e : REAL;
		a_internal : REAL;
		err_flag : BOOL;
		Temp_set_int_old1 : REAL;
		Temp_set_int_old2 : REAL;
		Temp_set_int_old3 : REAL;
		mode_old : UDINT;
		timestore1 : UDINT;
		timestore2 : UDINT;
		yManInternal : REAL;
		timeCnt : UDINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRTempTune (* Precision tuning process especially for temperature systems. *)
	VAR_INPUT
		enable : BOOL;
		start : BOOL;
		Temp_set : REAL;
		Temp : REAL;
		okToHeat : BOOL;
		okToFree : BOOL;
		okToFreeEnd : BOOL;
		okToCool : BOOL;
		okToCoolEnd : BOOL;
		pSettings : REFERENCE TO lcrtemp_set_typ;
	END_VAR
	VAR_OUTPUT
		y_heat : REAL;
		y_cool : REAL;
		rdyToHeat : BOOL;
		rdyToFree : BOOL;
		rdyToFreeEnd : BOOL;
		rdyToCool : BOOL;
		rdyToCoolEnd : BOOL;
		done : BOOL;
		busy : BOOL;
		status : UINT;
	END_VAR
	VAR
		enable_old : BOOL;
		pid : LCRPID;
		pid_para : LCRPIDpara;
		DT2 : LCRDifferentiate;
		pt2 : LCRPT2o;
		Temp_flt : REAL;
		step : UINT;
		t : REAL;
		Temp_start : REAL;
		mem00 : REAL;
		cnt02 : REAL;
		cnt33 : REAL;
		cnt20 : REAL;
		pem01 : REAL;
		pem33 : REAL;
		pem10 : REAL;
		pem02 : REAL;
		pem44 : REAL;
		pem20 : REAL;
		tol01 : REAL;
		tol10 : REAL;
		tol02 : REAL;
		tol20 : REAL;
		tol22 : REAL;
		Temp_old : REAL;
		delta_Temp : REAL;
		tcnt_1 : UDINT;
		tcnt_2 : UDINT;
		tcnt_dT_1 : UDINT;
		tcnt_dT_2 : UDINT;
		sysinfo_inst : SysInfo;
		Temp_set_internal : REAL;
		timecounter : REAL;
		internal_para : lcrtemp_tune_internal_typ;
		dbl_dt : REAL;
		call_counter : UDINT;
		store1 : UDINT;
		store2 : UDINT;
		timeCnt : UDINT;
		timer2 : REAL;
		waitCounter : UINT;
		Y_heat_tune_intern : REAL;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_OK} FUNCTION_BLOCK LCRPT2o (* Oscillating 2nd order delay element. *)
	VAR_INPUT
		enable : BOOL;
		V : REAL;
		D : REAL;
		Tf : REAL;
		u : REAL;
		Set_y : USINT;
		y_set : REAL;
	END_VAR
	VAR_OUTPUT
		y : REAL;
		status : UINT;
	END_VAR
	VAR
		Internal : lcrpt2o_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK LCRSchedulePWM (* Pulse width modulator for n inputs with a specified power limitation. *)
	VAR_INPUT
		enable : BOOL;
		Pmax : REAL;
		n : UINT;
		pPar : UDINT;
		min_value : REAL;
		max_value : REAL;
		t_min_pulse : REAL;
		t_period : REAL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
	END_VAR
	VAR
		sysinfo_inst : SysInfo;
		store1 : UDINT;
		store2 : UDINT;
		timeCnt : UDINT;
		numberUnits : UINT;
		limFact : UINT;
		enable_old : BOOL;
		cmd_delay : BOOL;
		err_flag : BOOL;
		limAll : BOOL;
		Pact : REAL;
		Pman : REAL;
		intern0 : ARRAY[0..5] OF REAL;
		in : REFERENCE TO lcrschedule_par_typ;
	END_VAR
END_FUNCTION_BLOCK
