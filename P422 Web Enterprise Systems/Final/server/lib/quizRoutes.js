let express = require('express');
let router = express.Router();
let Quiz = require('./models/quiz');
let quizSubmission = require('./models/quizSubmission');

router.route('/')
    .get(function(req, res) {
      var query = Quiz.find({});
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
      var newQuiz = new Quiz(req.body);
      newQuiz.section = req.body.section;
      newQuiz.save()
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
      var query = Quiz.deleteMany({});
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

router.route('/:quizName')
    .get(function(req, res) {
      Quiz.findOne({
        section: req.query.section,
        name: req.params.quizName
      }).exec()
          .catch(err => {
            res.status(404);
            res.jsonp(err);
          })
          .then(doc => {
            res.status(200);
            res.jsonp(doc);
          })
    });

router.route("/:quizName/grades")
// GET should only be used by teachers
    .get(function(req, res) {
      quizSubmission.find().exec()
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
      var newSubmission = new quizSubmission(req.body);
      newSubmission.quiz.section = req.body.section;
      newSubmission.quiz.name = req.params.quizName;
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

router.route('/get-by-section/:section')
    .get(function(req, res) {
      Quiz.find({
        section: req.params.section
      }).exec()
          .catch(err => {
            res.status(404);
            res.jsonp(err);
          })
          .then(doc => {
            res.status(200);
            res.jsonp(doc);
          })
    });

router.route('/get-by-name/:name')
    .get(function(req, res) {
      Quiz.find({
        name: req.params.name
      }).exec()
          .catch(err => {
            res.status(404);
            res.jsonp(err);
          })
          .then(doc => {
            res.status(200);
            res.jsonp(doc);
          })
    });

module.exports = router;

