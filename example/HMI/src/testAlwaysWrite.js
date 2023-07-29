machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
  maxMessageFrequency : 0.01
});


setInterval(WEBHMI.updateHMI, 30)

//Write constantly for testing
let startTime = Date.now()
setInterval(()=>{
  machine.writeVariable('demo:test.random', (Date.now() - startTime) / 1000)
}, 10)