                                                                      
TYPE
    udpIP_MREQ_typ		: STRUCT	(*multicast*)
		pMcastAddr		: UDINT;	(*pointer to the multicast address*)
		pIfAddr			: UDINT;	(*pointer to the interface address*)
	END_STRUCT;
	
	udpSO_ADDRESS_typ	: STRUCT	(*socket address*)
		pPort			: UDINT;	(*pointer where to store the portnumber*)
		pIpAddr			: UDINT;	(*pointer where to store the socket ip address*)
	END_STRUCT;
END_TYPE
