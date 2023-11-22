var machine = new LUX.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
});

var Configuration = new LUX.HMI(()=>{


})

setInterval(LUX.updateHMI, 30)