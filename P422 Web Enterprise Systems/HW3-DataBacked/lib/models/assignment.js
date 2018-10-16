const mongoose = require('mongoose');
const Schema = mongoose.Schema;

// Schema Attributes:
const assignmentSchema = new Schema({
    assignmentName: String,
    className: String,
    description: String,
    points: Number,
    fileTypes: ['none','docx','zip','pdf'],
    dueDate: Date,
    openDate: Date,
    closedDate: Date
},{ strict: false, timestamps: { createdAt: 'createdAt', updatedAt: 'updatedAt' } });


const Assignment = mongoose.model('Assignment', assignmentSchema);

module.exports.Model = Assignment;

// module.exports.seed = function() {
//     //Seed DB:
//     assignment.count({}, function (err, count) {
//         if (err){
//             throw err;
//         }
//         if(count > 0) return;
//         const assignmnets = require('../mock/assignments');
//         assignment.create(assignments, function (err, newAssignment) {
//             if (err) {
//                 throw err;
//             }
//             console.log("DB seeded")
//         });
//     });
// };