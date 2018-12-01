let express = require('express');
let router = express.Router();
let Quiz = require('./models/assignments');
let Submissions = require('./models/quizSubmission');

router.route('/')
	.post(function(req, res) {
		let newSubmission = new Submissions(req.body);
        newSubmission.section = req.body.section;
        newSubmission.save()
			.catch(err => {
				res.status(500);
				res.json(err);
			})
			.then(doc => {
				res.status(200);
				res.json(doc);
			});
	})
    .get(function(req, res) {
        var query = Submissions.find({});
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
	.delete(function(req, res) {
		var query = Submissions.deleteMany({});
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
module.exports = router;

