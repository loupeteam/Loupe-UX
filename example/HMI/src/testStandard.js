var machine = new WEBHMI.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
});

var Configuration = new WEBHMI.HMI(()=>{


})

setInterval(WEBHMI.updateHMI, 30)