module.exports.route = (app) => {
  app.use('/api', require('../controllers/HomeworkController'));
};