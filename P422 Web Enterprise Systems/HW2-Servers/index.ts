import * as bodyParser from 'body-parser';
import express from 'express';
import { Routes } from './lib/routes/routes';

class Main {

    public app: express.Application;
    public routePrv: Routes = new Routes();

    constructor() {
        this.app = express();
        this.config();
        this.routePrv.routes(this.app);
        this.app.listen(4200, () => {
            console.log(`listening on port 4200`);
        });
    }

    private config(): void {
        this.app.use(bodyParser.json());
        this.app.use(bodyParser.urlencoded({ extended: false }));
        // serving static files 
        this.app.use(express.static('public'));
        this.app.use(express.static('static'));
    }
}

export default new Main().app;
