let express = require('express');
let router = express.Router();
let Users = require('./models/Users');

router.route('/')
	.get(function(req, res) {
		var query = Users.find();
		if (req.query && req.query.role) {
			query = query.byRole(req.query.role);
		}
		query.exec()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(docs => {
					res.status(200);
					res.json(docs);
				});
	})
	.post(function(req, res) {
		var newUserInfo = req.body;
		var newUser = new Users(newUserInfo);
		newUser.save()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(doc => {
				res.status(200);
				res.json(doc);
			});
	});

router.route('/:userId')
	.get(function(req, res) {
		Users.findOne({uid: req.params.userId}).exec()
			.catch(err => {
				res.status(404);
				res.jsonp(err);
			})
			.then(doc => {
				res.status(200);
				res.jsonp(doc);
			})
	})
	.put(function(req, res) { // start paying attention here
		if (req.params.userId !== String(req.body.uid)) {
			res.status(400);
			return res.jsonp("Your user IDs don't match.");
		}

		// First, find any documents that may be in the system
		// I added .byUID in the model for ease. You can do the same by mimicking the .byRole method we created
		Users.findOne().byUID(req.body.uid)
			.exec()
			.catch(err => res.status(500).json({error: err})) // if something failed, it's probably our fault at this stage, 500
			.then(doc => {
				// If we got a doc back, we can update it and save it
				if (doc) {
					// doc.set will wholesale update the document with new contents
					doc.set(req.body);
					return doc.save()
						.catch(err => res.status(400).json({error: err})) // errors here are probably schema issues, validate will run
						.then(doc => res.status(200).json(doc)); // otherwise, return the doc
				}
				// If we didn't find a doc, then we need to create a new one
				var u = new Users(req.body);
				u.save()
					.catch(err => res.status(400).json({error: err}))
					.then(doc => res.status(200).json(doc));
			});
	});

module.exports = router;

