var mongoose = require('mongoose');
var bcrypt = require('bcrypt');

var validTypes = ['ungraded', 'any', 'pdf', 'zip'];

let typeValidator = function (type) {
  let res = validTypes.find(function (t) {
    return t === type;
  });
  return !!res; // !! here serves to convert the string or undefined to bool
};

let quizSchema = mongoose.Schema({
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
  questions: {
    type: {
      question: {
        type: {
          questionName: String,
          options: {
            type: {
              option0: String,
              option1: String,
              option2: String,
              option3: String
            }
          },
          answer: Number
        }
      }
    },
    required: true
  }
});

quizSchema.query.bySectionAndName = function(name, section) {
  return this.where({section: section, name: name});
};

let Quizes = mongoose.model('Quiz', quizSchema);

module.exports = Quizes;


