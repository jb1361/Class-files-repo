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
    it('password contains number pass', () => {
        const test = checker.containsNumber('password1');
        expect(test).toBe(true);
    });
    it('password contains number fail', () => {
        const test = checker.containsNumber('password');
        expect(test).toBe(false);
    });
    it('password contains uppercase letter pass', () => {
        const test = checker.containsUppercase('Password');
        expect(test).toBe(true);
    });
    it('password contains uppercase letter fail', () => {
        const test = checker.containsUppercase('password');
        expect(test).toBe(false);
    });
    it('password contains special character pass', () => {
        const test = checker.containsSpecialCharacter('password!');
        expect(test).toBe(true);
    });
    it('password contains special character fail', () => {
        const test = checker.containsSpecialCharacter('password');
        expect(test).toBe(false);
    });
    it('password rating above or equal to 8', () => {
        const test =  checker.passwordRating('Testing1223???');
        expect(test).toBeGreaterThanOrEqual(8);
    });
});
