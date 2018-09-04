import 'jasmine';
import {Bloom} from '../lib/Bloom';
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

describe('Bloom filter', () => {
    const bloom = new Bloom('password');
    it('password found in bloom filter pass', () => {
        const test = bloom.check('password');
        expect(test).toBe(true);
    });
    it('password above eight characters fail', () => {
        const test = bloom.check('password1');
        expect(test).toBe(false);
    });
    bloom.createHash('PasswordTest2');
    it('password number 2 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest2');
        expect(test).toBe(true);
    });
    bloom.createHash('PasswordTest3');
    bloom.createHash('PasswordTest4');
    bloom.createHash('PasswordTest5');
    bloom.createHash('PasswordTest6');
    bloom.createHash('PasswordTest7');
    bloom.createHash('PasswordTest8');
    bloom.createHash('PasswordTest9');
    bloom.createHash('PasswordTest10');
    it('password number 3 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest3');
        expect(test).toBe(true);
    });
    it('password number 4 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest4');
        expect(test).toBe(true);
    });
    it('password number 5 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest5');
        expect(test).toBe(true);
    });
    it('password number 6 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest6');
        expect(test).toBe(true);
    });
    it('password number 7 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest7');
        expect(test).toBe(true);
    });
    it('password number 8 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest8');
        expect(test).toBe(true);
    });
    it('password number 9 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest9');
        expect(test).toBe(true);
    });
    it('password number 10 found in bloom filter pass', () => {
        const test = bloom.check('PasswordTest10');
        expect(test).toBe(true);
    });
    it('password number 11 found in bloom filter fail', () => {
        const test = bloom.check('Passwordsdgedfhtgfjh#$%#%');
        expect(test).toBe(false);
    });
});

