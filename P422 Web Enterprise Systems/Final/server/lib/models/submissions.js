let mongoose = require('mongoose');
let bcrypt = require('bcrypt');

let submissionSchema = mongoose.Schema({
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
        type: String,
        default: 'homework'
    },
    upload: {
        type: Buffer,
        default: null
    },
    text: {
        type: String,
        required: true
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

let Submissions = mongoose.model('Submission', submissionSchema);

module.exports = Submissions;
