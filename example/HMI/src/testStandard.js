var machine = new LUX.HMI();

/*
var machine = new LUX.Machine({
  port: 8000,
  ipAddress: '127.0.0.1',
  maxReconnectCount: 5000,
});
*/
machine.testData = `<h1>Example Loaded</h1><p>Example HMI</p>`;
machine.testBool = false;
var Configuration = new LUX.HMI(()=>{


})

setInterval(LUX.updateHMI, 30)