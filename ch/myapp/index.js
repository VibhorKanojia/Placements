
var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io').listen(http);


app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', function(socket){  
  socket.on('chat message', function(msg){
    console.log('message: ' + msg);
  });
});

http.listen(3700, function(){
  console.log('listening on *:3000');
});
