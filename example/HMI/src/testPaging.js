machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
  // maxMessageFrequency: 120
});


setInterval(WEBHMI.updateHMI, 30)

machine.initCyclicPageRead( 'test', "Page:MyVar.in.command" )
machine.initCyclicPageRead( 'test', "Page:MyVar.in" )
machine.initCyclicPageRead( 'test', "Page:MyVar" )

machine.setPageEnable( 'test', false)

machine.setPageMaxFrequency('test1', 2)
machine.setPageMaxFrequency('test3', 1)
