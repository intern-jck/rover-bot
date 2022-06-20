const { parse } = require('fast-csv');
const express = require('express');
const app = express();
const cors = require('cors');
app.use(cors());
app.use(express.json())

const { SerialPort } = require('serialport');
const port = 3000;

const nano = new SerialPort({
  path: '/dev/ttyUSB0',
  baudRate: 9600,
});

app.get('/bot-move/', (req, res) => {
    console.log(req.body);
    nano.write(`<${dir},${spd}>`);
});

app.listen(port, () => {
    console.log(`Listening at http://localhost:${port}`);
});
