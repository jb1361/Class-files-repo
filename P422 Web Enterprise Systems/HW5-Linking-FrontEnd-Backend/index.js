var express = require('express');
var bodyParser = require('body-parser');
var app = express();
var mongoose = require('mongoose');
var request = require('request');
var cors = require('cors');
var path = require('path');

app.use(cors())

app.use(bodyParser.json());

app.use('/v1/users', require('./lib/userRoutes'));
app.use('/v1/courses', require('./lib/courseRoutes'));

app.use('/', express.static('./frontend/dist/frontend'));

app.get('*', (req, res) => {
	res.sendFile(path.join(__dirname, 'frontend/dist/frontend/index.html'));
});

mongoose.connect('mongodb://localhost/test');
var db = mongoose.connection;
app.locals.mdb = db;

app.listen(8080, function() {
	console.log('Listening on 8080');
});
