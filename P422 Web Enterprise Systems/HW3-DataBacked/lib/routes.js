var _ = require('lodash');
var express = require('express');
var router = express.Router();
var Users = require('./models/Users');
var Assignments = require('./models/assignment').Model;

router.route('/users')
	.get(function(req, res) {
		var options = {};
		var db = req.app.locals.db;

		if (req.query && req.query.role) {
			options.role = req.query.role;
		}

		Users.all(db, options, function(err, users) {
			if (err) {
				res.status(500);
				res.json(err);
				return;
			}

			res.status(200);
			users = _.map(users, function(u) { return u.valueOf(); });
			res.json(users);
		});
	})
	.post(function(req, res) {
		var newUserInfo = req.body;
		var db = req.app.locals.db;

		var newUser = new Users(db, newUserInfo);
		newUser.save(function(err) {
				if (err) {
					res.status(400);
					return res.json(err);
				}

				res.status(200);
				res.json(newUser.valueOf());
			});
	});

router.route('/users/:userId')
	.get(function(req, res) {
		var db = req.app.locals.db;
		var user = new Users(db, {uid: req.params.userId});
		user.get(function(err, user) {
				if (err) {
					res.status(404);
					return res.json(err);
				}

				res.status(200);
				res.json(user.valueOf());
			});
	})
	.put(function(req, res) {
		var newUserInfo = req.body;
		var db = req.app.locals.db;

		if (req.params.userId !== String(req.body.uid)) {
			res.status(400);
			return res.json("Your user IDs don't match.");
		}

		var newUser = new Users(db, newUserInfo);
		newUser.save(function(err) {
				if (err) {
					res.status(400);
					return res.json(err);
				}

				res.status(200);
				res.json(newUser.valueOf());
			});
	});

router.route('/assignments/')
	.get(function(req, res) {
		if(req.param('class')) {
            Assignments.find({className: req.param('class')},function(err, assignments) {
                if(err) res.status(500).json(err);
                else if (assignments.length === 0) return res.status(204).json('No Assignment found.');
                else res.status(200).json(assignments);
            });
        }
        else {
        	Assignments.find({},function(err, assignments) {
        		if(!err) res.status(200).json(assignments);
                else if (assignments.length === 0) return res.status(204).json('No Assignment found.');
        		else res.status(500).json(err);
			});
		}
	})
	.post(function(req, res) {
		var data = req.body;
        Assignments.create({
            className: data.className,
            assignmentName: data.assignmentName,
            description: data.description,
            points: data.points,
            fileType: data.fileTypes,
            dueDate: data.dueDate,
            openDate: data.openDate,
            closedDate: data.closedDate
        },function (err) {
            if(err) return res.status(400).json(err);
            else return res.status(201).json('Assignment Created');
        });
    });
router.route('/assignments/:className/:assignmentName/')
	.get(function (req, res) {
        Assignments.find({className: req.params['className'], assignmentName: req.params['assignmentName']},function(err,assignment) {
            if(err) return res.status(400).json(err);
            else if (assignment.length === 0) return res.status(204).json('No Assignment found.');
            else return res.status(200).json(assignment);
        });
    })
	.delete(function (req, res) {
		Assignments.deleteOne({className: req.params['className'], assignmentName: req.params['assignmentName']},function(err) {
			if(err) return res.status(400).json(err);
			else return res.status(200).json('Assignment Deleted');
		});
	});

module.exports = router;
