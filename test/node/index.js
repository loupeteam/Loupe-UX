
//Require Jquery and WebHMI
const { JSDOM } = require( "jsdom" );
const { window } = new JSDOM( "" );
global.$ = global.jQuery = require("jquery")( window );
const WEBHMI = require("../../src/HMI/webhmi");

const ads = require('ads-client')

// const client = new ads.Client({
//     localAmsNetId: '10.200.168.205.1.1',  //Can be anything but needs to be in PLC StaticRoutes.xml file
//     localAdsPort: 32750,                //Can be anything that is not used
//     targetAmsNetId: '5.80.227.36.1.1',
//     targetAdsPort: 851,
//     routerAddress: '169.254.102.218',     //PLC ip address
//     routerTcpPort: 48898,                //PLC needs to have this port opened. Test disabling all firewalls if problems
//   })

const client = new ads.Client({
    targetAmsNetId: '127.0.0.1.1.1', //or 'localhost'
    targetAdsPort: 851,
  })

  client.connect().catch((err) => {
    console.log(err)
})

let dataManager = new WEBHMI.HMI(()=>{

})


//Import PLC structure from JSON file
const fs = require('fs');
let rawdata = fs.readFileSync('./plc.json');
let plc = JSON.parse(rawdata);

WEBHMI.extend(true, dataManager, plc);

//Intermittently write to the PLC to the file
setInterval(() => {
    fs.writeFile("./plc.json", JSON.stringify(dataManager, null, 2), function (err) {
        if (err) {
            return console.log(err);
        }
//        console.log("The file was saved!");
    });
}, 1000);


//Implement a websocket server
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({ port: 8000 });
let data
wss.on('connection', function (ws) {
    ws.on('message', function (message) {
//        console.log('received: %s', message);
        let msg = JSON.parse(message);
        if (msg.type == "write") {
  //          console.log("Write request: " + msg.data);
            msg.type = "writeresponse";
            msg.data = setProcessVariable(msg.data);       
            ws.send(JSON.stringify(msg));
        }
        if (msg.type == "read") {
            msg.type = "readresponse";
            getProcessVariable(msg.data).then((data) => {
                msg.data = data;
                let resp = JSON.stringify(msg)
                ws.send(resp);    
            });       
        }
    });
});

async function getProcessVariable( data ){
    for (let i = 0; i < data.length; i++) {
        let name = data[i]
        let val = dataManager.value(name);
        if(typeof val == "undefined"){
            dataManager.value(name, 0);            
            val = dataManager.value(name);
        }
        const element = {};
        await client.readSymbol(name).then((data)=>{
            element[name] = data.value
        }).catch((err) => {
            element[name] = val
         })
        data[i] = element;
    }
    return data;
}

function setProcessVariable( data ){
    WEBHMI.extend(true, dataManager, data);
    //Go through each member of the data object and write it to the PLC
    var scopeArray = Object.getOwnPropertyNames(data);
    for(let scopeIn in scopeArray ){
        let scope = scopeArray[scopeIn];
        let variable = data[scope];

        var variableListArray = Object.getOwnPropertyNames(variable);
        for(let member in variableListArray ){
            let name = variableListArray[member];
            let val = variable[name];
    
            client.writeSymbol(scope + '.' + name, val, true).then((d)=>{
                console.log(d)
            }).catch((err) => {
                console.log(err)
            })
        }
    }
        
    return data;
}