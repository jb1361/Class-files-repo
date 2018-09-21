import {Bloom} from '../Bloom';
import {PswChecker} from '../pwchecker';

export class HomeWorkController {

    public checker = new PswChecker();
    public bloomFilter = new Bloom();

    public passwordHealth(password: JSON) {
        const reqBody = JSON.stringify(password);
        return this.checker.passwordRating(reqBody);
    }

    public amIPwnd(password: JSON) {
       return this.bloomFilter.check(JSON.stringify(password));
    }

    public addBloom(password: JSON) {
        this.bloomFilter.createHash(JSON.stringify(password));
    }
    public checkIfUsed(userName: JSON) {
        this.bloomFilter.check(JSON.stringify(userName));
    }
    public checkPassToBloom(userName: JSON) {
        this.bloomFilter.check(JSON.stringify(userName));
    }
}
