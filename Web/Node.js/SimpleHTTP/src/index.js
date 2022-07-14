import express from 'express';
const app = express();

app.all('*', function (req, res, next) {
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Methods', 'PUT,GET,POST,DELETE,OPTIONS');
  res.header('Access-Control-Allow-Headers', 'X-Requested-With');
  res.header('Access-Control-Allow-Headers', 'Content-Type');
  next();
});

app
  .get('/api', (req, res) => {
    res.send({
      name: 'fish',
      id: 233,
    });
  })
  .post('/api', (req, res) => {
    console.log(req);
    res.send(req.body);
  })
  .listen('1023', () => {
    console.log('running on http://localhost:1023/api');
  });
