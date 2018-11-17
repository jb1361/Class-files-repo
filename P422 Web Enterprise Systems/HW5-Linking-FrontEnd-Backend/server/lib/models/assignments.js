var mongoose = require('mongoose');
var bcrypt = require('bcrypt');

var validTypes = ['ungraded', 'any', 'pdf', 'zip']

var typeValidator = function(type) {
	var res = validTypes.find(function(t) {
		return t === type;
	});
	return !!res; // !! here serves to convert the string or undefined to bool
};

var assignmentSchema = mongoose.Schema({
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
	description: {
		type: String
	},
	due: {
		type: Date
	},
	maxPoints: {
		type: Number,
		default: 100,
		required: true
	},
	type: {
		type: String,
		default: 'any',
		validate: typeValidator
	}
});

assignmentSchema.query.bySectionAndName = function(name, section) {
	return this.where({section: section, name: name});
};

var Assignments = mongoose.model('Assignment', assignmentSchema);

module.exports = Assignments;


