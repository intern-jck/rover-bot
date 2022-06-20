const fs = require('fs');
const PORT = 3000;
const { SerialPort } = require('serialport');
const express = require('express');
const app = express();
const cors = require('cors');
app.use(cors());
app.use(express.json());

const botData = '/home/pi/rover-bot/data.txt';

// Connect to Arduino Nano
const nano = new SerialPort({
  path: '/dev/ttyUSB0',
  baudRate: 9600,
});

app.get('/bot-test/:value', (req, res) => {
  console.log(req.params);
  nano.write(`${req.params.value}`);
  const date = new Date().toISOString();
  const data = date + ' : ' + req.params.value + ',\n';
  
  fs.appendFile(botData, data, (error) => (console.log(error)));
  res.sendStatus(200);
});

app.listen(PORT, () => {
  console.log(`Listening at http://localhost:${PORT}`);
});

