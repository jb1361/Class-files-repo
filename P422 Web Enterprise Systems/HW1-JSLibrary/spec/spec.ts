import 'jasmine';
import {PswChecker} from '../lib/pwchecker';

describe('Password Checker', () => {
    const checker = new PswChecker();
    it('password above eight characters pass', () => {
         const test = checker.lengthAboveEight('password1');
         expect(test).toBe(true);
    });
    it('password above eight characters fail', () => {
        const test = checker.lengthAboveEight('password');
        expect(test).toBe(false);
    });
});
