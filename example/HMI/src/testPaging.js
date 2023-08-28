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


function mycb(group, wouldShow){
  group.enable = wouldShow
 return false
}
machine.setReadGroupEnableCallback( 'test1',mycb)
machine.setReadGroupEnableCallback( 'test', ( group, wouldShow )=>{
  group.enable = wouldShow
  return false
})

machine.setReadEnableCallback( ( group, wouldShow )=>{
  if(wouldShow){
    return true
  }
  else{
    return false
  }
})

machine.setReadGroupMaxFrequency('test1', 2)

machine.getReadGroup('test1')
machine.getReadGroupList()
machine.printReadGroups()