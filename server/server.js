const express = require('express');
const fs = require('fs');
var cors = require('cors');
const app = express();
app.use(express.json());
app.use(cors());

app.use(express.static('public'));
app.use('/bot-pics', express.static('bot-pics'));

const videoStream = require('./videoStream');
const { SerialPort } = require('serialport');
const port = 3000;

// Setup connection to Arduino
const nano = new SerialPort({
  path: '/dev/ttyUSB0',
  baudRate: 115200,
});

// Start video stream
videoStream.acceptConnections(app, {
  width: 720,
  height: 480,
  fps: 16,
  encoding: 'JPEG',
  quality: 5,
}, '/rover-cam.mjpg', true);

app.get('/cam-pic', (req, res) => {
  
  res.set('Content-Type', 'image/jpeg');
  const lastFrame = videoStream.getLastFrame();
  
  console.log(lastFrame);
  const buffer = Buffer.from(lastFrame, 'base64');
  const imgId = Date.now();
  const imgPath = `bot-pics/img-${imgId}.png`;
  fs.writeFileSync(imgPath, buffer);
  //~ console.log(img);
  res.send(imgPath);
});

app.put('/bot-move', (req, res) => {
  const botState = req.body;
  const date = new Date().toISOString();
  console.log(botState, date);
  nano.write(`<${req.body.dir},${req.body.str},${req.body.spd}>`);
  res.sendStatus(200);
});

app.listen(port, () => {
  console.log(`Listening at http://localhost:${port}`);
});
