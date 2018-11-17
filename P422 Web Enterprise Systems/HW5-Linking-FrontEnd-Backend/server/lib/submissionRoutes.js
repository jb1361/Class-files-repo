let express = require('express');
let router = express.Router();
let Assignments = require('./models/assignments');
let Submissions = require('./models/submissions');

router.route('/')
	.post(function(req, res) {
		var newSubmission = new Submissions(req.body);
		newAssignment.section = req.body.section;
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

module.exports = router;

