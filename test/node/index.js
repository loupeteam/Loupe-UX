
//Require Jquery and WebHMI
const { JSDOM } = require( "jsdom" );
const { window } = new JSDOM( "" );
global.$ = global.jQuery = require("jquery")( window );
const WEBHMI = require("../../src/HMI/webhmi");

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
        console.log("The file was saved!");
    });
}, 1000);


//Implement a websocket server
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({ port: 8000 });
let data
wss.on('connection', function (ws) {
    ws.on('message', function (message) {
        console.log('received: %s', message);
        let msg = JSON.parse(message);
        if (msg.type == "write") {
            console.log("Write request: " + msg.data);
            msg.type = "writeresponse";
            msg.data = setProcessVariable(msg.data);       
            ws.send(JSON.stringify(msg));
        }
        if (msg.type == "read") {
            msg.type = "readresponse";
            msg.data = getProcessVariable(msg.data);       
            let resp = JSON.stringify(msg)     
            ws.send(resp);
        }
    });
});

function getProcessVariable( data ){
    for (let i = 0; i < data.length; i++) {
        let name = data[i]
        let val = dataManager.value(name);
        if(typeof val == "undefined"){
            dataManager.value(name, 0);            
            val = dataManager.value(name);
        }
        const element = {};
        element[name] = val

        data[i] = element;
    }
    return data;
}

function setProcessVariable( data ){
    WEBHMI.extend(true, dataManager, data);
    return data;
}