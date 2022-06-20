const express = require('express');
var cors = require('cors');
const app = express();
app.use(express.json())
app.use(cors());
const { SerialPort } = require('serialport');
const port = 3000;


const nano = new SerialPort({
  path: '/dev/ttyUSB0',
  baudRate: 115200,
});

app.put('/bot-move', (req, res) => {
    console.log(req.body.key, req.body.spd);
    nano.write(`<${req.body.key},${req.body.spd}>`);
    res.sendStatus(200);
});

app.listen(port, () => {
    console.log(`Listening at http://localhost:${port}`);
});
