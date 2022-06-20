const express = require('express');
var cors = require('cors');
const app = express();
app.use(cors());
const { SerialPort } = require('serialport');
const port = 3000;


const nano = new SerialPort({
  path: '/dev/ttyUSB0',
  baudRate: 115200,
});

app.get('/bot-move/:dir/:spd', (req, res) => {
    console.log(req.params.spd);
    nano.write(`<${req.params.dir},${req.params.spd}>`);
});

app.listen(port, () => {
    console.log(`Listening at http://localhost:${port}`);
});
