// import {Bloom} from './lib/Bloom';
// import {PswChecker} from './lib/pwchecker';
// const checker = new PswChecker();


 import express = require('express');
 const router = ('./routes');
 const app = express();

// const config = require('./config');


app.use('/', express.static('client/src'));
router.route(app);


app.listen(4200, function () {
    console.log(`listening on port 4200`);
});
