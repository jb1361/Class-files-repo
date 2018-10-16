var MongoClient = require('mongodb').MongoClient;
var express = require('express');
var bodyParser = require('body-parser');
var app = express();
var mongoose = require('mongoose');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use('/v1', require('./lib/routes'));

function connectToMongo(url, db, cb) {
	var options = {
		useNewUrlParser: true
	};

	MongoClient.connect(url, options, function(err, client) {
		if (err) {
			console.log('Error connecting to Mongo');
			return cb(err);
		}
		console.log('Connected successfully to server');

		cb(null, client.db(db));
	});
}

connectToMongo('mongodb://localhost:27017', 'assignments', function(err, client) {
	if (err) {
		console.log(err);
		return;
	}
	mongoose.connect('mongodb://localhost:27017/assignments',function(err) {
        if (err) {
            console.log(err);
            return;
        }
        else console.log('Mongoose Connected');
	});
	app.locals.db = client;
	app.listen(8080, function() {
		console.log('Listening on 8080');
	});
});

