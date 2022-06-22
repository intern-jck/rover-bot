const fs  = require('fs');

const appendToCSV = (file, values) => {

  console.log(file, values);
  let writer;
  
  if (fs.existsSync(file)) {
    writer = csvWriter({sendHeaders: false});
  } else {
    writer = csvWriter({headers: ["direction", "speed"]});
  }

  writer.pipe(fs.createWriteStream(file, {flags: 'a'}));
  writer.write({
    direction: values.direction,
    speed: values.speed
  });
  writer.end();
}



module.exports = { appendToCSV };
