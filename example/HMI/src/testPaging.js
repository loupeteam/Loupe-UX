machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,  
  maxMessageFrequency: 120
});


setInterval(WEBHMI.updateHMI, 30)

//Test OLD API
machine.initCyclicRead("OldReadStyle" )
machine.setReadGroupMaxFrequency("global", 1)

//Test NEW API with parenting
machine.initCyclicReadGroup( 'CommsParent', "Page:MyVar.in.command" )
machine.initCyclicReadGroup( 'CommsParent', "Page:MyVar.in" )
machine.initCyclicReadGroup( 'CommsParent', "Page:MyVar" )
machine.initCyclicReadGroup( 'CommsParent', "test" )

//Disable a read group
machine.setReadGroupEnable( 'CommsParent', false)

//Set the max frequency of a read groups
// machine.setReadGroupMaxFrequency('CommsActive', 1)//uses default
machine.setReadGroupMaxFrequency('CommsParent', 2)
machine.setReadGroupMaxFrequency('CommsChild', 1)

//Test passing in a callback function
function myTestReadGroupCallback(group, wouldShow){
  group.enable = wouldShow
 return false
}
machine.setReadGroupEnableCallback( 'CommsLow',myTestReadGroupCallback)

//Test passing in a callback anonymous function
machine.setReadGroupEnableCallback( 'CommsChild', ( group, wouldShow )=>{
  group.enable = wouldShow
  return false
})

//Test passing in a callback anonymous function that always returns true
machine.setReadGroupEnableCallback( 'CommsParent', ( group, wouldShow )=>{
  return true
})


//Test the global callback function
machine.setReadEnableCallback( ( group, wouldShow )=>{
    return true
})

//Test the rest of the API
console.log(machine.getReadGroup('CommsLow'))
console.log(machine.getReadGroupList())
machine.printReadGroups()