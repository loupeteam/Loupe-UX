machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
  // maxMessageFrequency: 120
});


setInterval(WEBHMI.updateHMI, 30)

machine.initCyclicRead("Page:MyVar.in.command" )
machine.initCyclicReadGroup( 'test', "Page:MyVar.in.command" )
machine.initCyclicReadGroup( 'test', "Page:MyVar.in" )
machine.initCyclicReadGroup( 'test', "Page:MyVar" )

machine.setReadGroupEnable( 'test', false)

machine.setReadGroupMaxFrequency('test1', 2)
machine.setReadGroupMaxFrequency('test3', 1)


function mycb(group){
 return shouldManage
}
machine.setReadGroupEnableCallback( 'test', mycb)
machine.setReadGroupEnableCallback( 'test1',mycb)
machine.setReadGroupEnableCallback( 'test', ( group )=>{
  return shouldManage
})

machine.setReadGroupMaxFrequency('test1', 2)

machine.getReadGroup('test1')
machine.getReadGroupList()
machine.printReadGroups()