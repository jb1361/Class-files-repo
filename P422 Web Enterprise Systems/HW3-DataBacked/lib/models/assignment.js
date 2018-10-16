const mongoose = require('mongoose');
const Schema = mongoose.Schema;

// Schema Attributes:
const assignmentSchema = new Schema({
    assignmentName: {type: String, required: true},
    className: {type: String, required: true},
    description: String,
    points: {type: Number, required: true, min : 1},
    fileTypes: ['none','docx','zip','pdf'],
    dueDate: {type: Date},
    openDate:  {type: Date},
    closedDate:  {type: Date}
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