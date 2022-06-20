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

app.get('/bot-test/:value', (req, res) => {
    console.log(req.params);
    nano.write(`${req.params.value}`);
    res.sendStatus(200);
});

app.listen(port, () => {
    console.log(`Listening at http://localhost:${port}`);
});

