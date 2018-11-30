let express = require('express');
let router = express.Router();
let Courses = require('./models/Courses');

router.param('section', function(req, res, next, value) {
	req.section = value;
	next();
});

router.route('/')
	.get(function(req, res) {
		var query = Courses.find();
		if (req.query && req.query.role) {
			query = query.byRole(req.query.role);
		}
		query.exec().catch(err => {
				res.status(500);
				res.json(err);
    }).then(docs => {
					res.status(200);
					res.json(docs);
    });
	})
	.post(function(req, res) {
		var newCourse = new Courses(req.body);
		newCourse.save()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(doc => {
				res.status(200);
				res.json(doc);
			});
	})
	.delete(function(req, res) {
		var query = Courses.deleteMany({});
		query.exec()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(docs => {
				res.status(200);
				res.json(docs);
		});
  });
router.route('/courseSecction')
	.get(function(req, res) {
		var query = Courses.find(Courses.title);
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
	});
router.route('/:section')
	.get(function(req, res) {
		Courses.findOne().bySection(req.params.section).exec()
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
		if (req.params.section !== String(req.body.section)) {
			res.status(400);
			return res.jsonp("Your section IDs don't match.");
		}

		Courses.findOne().bySection(req.body.section).exec()
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
				var u = new Courses(req.body);
				u.save()
					.catch(err => res.status(400).json({error: err}))
					.then(doc => res.status(200).json(doc));
			});
	})
	.delete(function(req, res) {
		Courses.deleteOne({section: req.params.section}).exec()
			.catch(err => res.status(500).json({err: err}))
			.then(() => res.status(204).send());
	});

module.exports = router;

