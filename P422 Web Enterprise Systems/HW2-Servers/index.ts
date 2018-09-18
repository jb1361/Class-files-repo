// import {Bloom} from './lib/Bloom';
// import {PswChecker} from './lib/pwchecker';
// const checker = new PswChecker();

// const checkJwt = require('./middleware').checkJwt;
// //// Load dependencies
// const bodyParser = require('body-parser');
// const mongoose = require('mongoose');
 import express = require('express');
 const router = ('./routes');
 const app = express();
// const cors = require('cors');
// const middleware = require('./middleware');
// // load environment

// const config = require('./config');


app.use('/', express.static('client/src'));
app.use(bodyParser.json());
middleware.applyMiddleware(app);
router.route(app);


app.listen(config.port, function () {
    console.log(`listening on port ${config.port}`);
});
