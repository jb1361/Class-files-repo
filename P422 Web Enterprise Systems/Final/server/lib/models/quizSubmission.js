var mongoose = require('mongoose');
var bcrypt = require('bcrypt');

var validTypes = ['ungraded', 'any', 'pdf', 'zip'];

let typeValidator = function (type) {
  let res = validTypes.find(function (t) {
    return t === type;
  });
  return !!res; // !! here serves to convert the string or undefined to bool
};

let quizSubmissionSchema = mongoose.Schema({
  name: {
    type: String,
    required: true,
    index: true
  },
  section: {
    type: String,
    required: true,
    index: true
  },
  grade: {
    type: Number,
    required: true
  }
});

quizSubmissionSchema.query.bySectionAndName = function(name, section) {
  return this.where({section: section, name: name});
};

let QuizSubmission = mongoose.model('QuizSubmission', quizSubmissionSchema);

module.exports = QuizSubmission;


