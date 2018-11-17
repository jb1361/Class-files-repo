var mongoose = require('mongoose');
var bcrypt = require('bcrypt');

var submissionSchema = mongoose.Schema({
	assignment: {
		name: {
			type: String,
			required: true
		},
		section: {
			type: String,
			required: true
		},
		submitter: {
			type: String,
			required: true
		}
	},
	fileName: {
		type: String
	},
	upload: {
		type: Buffer
	},
	text: {
		type: String
	},
	submittedDate: {
		type: String,
		required: true,
		default: Date.now
	},
	grade: {
		type: Number,
		default: 0
	}
});

submissionSchema.query.byAssignment = function(section, name) {
	return this.where({
		assignment: {
			name: name,
			section: section
		}
	});
};

submissionSchema.query.byAssignmentAndSubmitter = function(section, name, submitter) {
	return this.where({
		assignment: {
			name: name,
			section: section,
			submitter: submitter
		}
	});
};

var Submissions = mongoose.model('Submission', submissionSchema);

module.exports = Submissions;
