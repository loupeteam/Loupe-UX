machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
  // maxMessageFrequency: 120
});


setInterval(WEBHMI.updateHMI, 30)

machine.initCyclicReadGroup( 'test', "Page:MyVar.in.command" )
machine.initCyclicReadGroup( 'test', "Page:MyVar.in" )
machine.initCyclicReadGroup( 'test', "Page:MyVar" )

machine.setReadGroupEnable( 'test', false)

machine.setPageMaxFrequency('test1', 2)
machine.setPageMaxFrequency('test3', 1)
