var express = require('express');
var router = express.Router();
var Assignments = require('./models/assignments');
var Submissions = require('./models/submissions')

router.route('/')
	.get(function(req, res) {
		var query = Assignments.find({section: req.section});
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
		var newAssignment = new Assignments(req.body);
		newAssignment.section = req.section;
		newAssignment.save()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(doc => {
				res.status(200);
				res.json(doc);
			});
	});

router.route('/:assignmentName')
	.get(function(req, res) {
		Assignments.findOne({
				section: req.section,
				name: req.params.assignmentName
			}).exec()
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
		if (req.params.name !== String(req.body.name)) {
			res.status(400);
			return res.jsonp("Your assignment names don't match.");
		}
		if (req.params.section !== String(req.body.section)) {
			res.status(400);
			return res.jsonp("Your sections don't match.");
		}

		Assignments.findOne().bySectionAndName(req.section, req.body.name)
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
				var u = new Assignments(req.body);
				u.save()
					.catch(err => res.status(400).json({error: err}))
					.then(doc => res.status(200).json(doc));
			});
	});

router.route("/:assignmentName/grades")
	// GET should only be used by teachers
	.get(function(req, res) {
		Submissions.byAssignment(req.section, req.params.assignmentName).exec()
			.catch(err => {
				res.status(404);
				res.jsonp(err);
			})
			.then(doc => {
				res.status(200);
				res.jsonp(doc);
			})
	})
	// POST will be used to submit assignments
	.post(function(req, res) {
		var newSubmission = new Submissions(req.body);
		newSubmission.assignment.section = req.section;
		newSubmission.assignment.name = req.params.assignmentName;
		newSubmission.save()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(doc => {
				res.status(200);
				res.json(doc);
			});
	});

module.exports = router;

