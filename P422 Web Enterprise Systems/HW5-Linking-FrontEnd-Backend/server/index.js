let express = require('express');
let bodyParser = require('body-parser');
let app = express();
let mongoose = require('mongoose');
let request = require('request');
let cors = require('cors');
let path = require('path');

app.use(cors());

app.use(bodyParser.json());

app.use('/v1/users', require('./lib/userRoutes'));
app.use('/v1/courses', require('./lib/courseRoutes'));
app.use('/v1/assignments', require('./lib/assignmentRoutes'));
app.use('/', express.static('./client/dist/frontend'));

app.get('*', (req, res) => {
	res.sendFile(path.join(__dirname, 'frontend/dist/frontend/index.html'));
});

mongoose.connect('mongodb://localhost/test');
let db = mongoose.connection;
app.locals.mdb = db;

app.listen(8080, function() {
	console.log('Listening on 8080');
});
