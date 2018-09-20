import {Request, Response} from 'express';
import { HomeWorkController } from '../controllers/HomeworkController';

export class Routes {

    public homeworkController: HomeWorkController = new HomeWorkController()
    public routes(app: any): void {

        app.route('/healthcheck').get((req: Request, res: Response) => {
                res.status(200).send({
                    message: 'API is healthy.',
                });
            });
        app.route('/api/v1/passwords/passwordHealth').post((req: Request, res: Response) => {
                res.status(200);
                res.json('health: ' + this.homeworkController.passwordHealth(req.body));
            });
        app.route('/api/v1/passwords/pwnd').post((req: Request, res: Response) => {
            res.status(200);
            if (this.homeworkController.amIPwnd(req.body)) res.json('seen: true');
            else res.json(false);
        });
        app.route('/api/v1/passwords/pwnd').put((req: Request, res: Response) => {
            this.homeworkController.addBloom(req.body);
            res.status(200);
        });
    }
}
