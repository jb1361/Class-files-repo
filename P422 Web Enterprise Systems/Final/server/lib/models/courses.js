let mongoose = require('mongoose');
let bcrypt = require('bcrypt');

let courseSchema = mongoose.Schema({
    section: {
        type: String,
        required: true,
        unique: true,
        index: true,
    },
    title: {
      type: String,
      required: true,
    },
    description: {
        type: String
    },
    bookInfo: {
        type: String
    },
    meetingTime: {
        type: String
    },
    gradingScale: {
        type: [String]
    },
    calendar: {
        type: [String]
    },
    universityInfo: {
        type: String
    }
});

courseSchema.query.bySection = function(section) {
	return this.where({section: section});
};

let Courses = mongoose.model('Course', courseSchema);

module.exports = Courses;

