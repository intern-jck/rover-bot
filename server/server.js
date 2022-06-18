//const express = require('express');
//const app = express();
const { SerialPort } = require('serialport');
const port = 3000;
const WLAN_0 = '192.168.1.93';
const WLAN_1 = '192.168.1.110';

const nano = new SerialPort({
  path: '/dev/ttyUSB0',
  baudRate: 115200,
});


setInterval(() => (nano.write('<1,100>')), 2000);



//~ nano.on('readable', () => {
    //~ console.log('DATA:', nano.read());
//~ });


//nano.on('data', (data) => {
//    console.log('NANO SENT:', data);
//});

/*
app.post('/rover-move', (req, res) => {
    console.log(req.data);
});


app.listen(port, () => {
    console.log(`Listening at port ${port}`);
});
*/
