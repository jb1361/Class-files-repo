import {Bloom} from './lib/Bloom';
import {PswChecker} from './lib/pwchecker';
const checker = new PswChecker();

'use strict';
const checkJwt = require('./middleware').checkJwt;
//// Load dependencies
const bodyParser = require('body-parser');
const mongoose = require('mongoose');
const express = require('express');
const router = require('./routes');
const app = express();
const cors = require('cors');
const middleware = require('./middleware');
// load environment

const config = require('./config');

if (!process.env.AUTH0_DOMAIN || !process.env.AUTH0_AUDIENCE) {
    throw 'Make sure you have AUTH0_DOMAIN, and AUTH0_AUDIENCE in your .env file';
}

// connect to mongodb
mongoose.connect(`mongodb://${config.db.host}/${process.env.DB_NAME}`);


// configure server
app.use(cors({
    origin: '*',
    credentials:true
}));

app.use('/', express.static('client/src'));
app.use(bodyParser.json());
middleware.applyMiddleware(app);
router.route(app);


app.listen(config.port, function () {
    console.log(`listening on port ${config.port}`);
});
