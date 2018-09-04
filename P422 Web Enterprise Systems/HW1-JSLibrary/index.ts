import {PswChecker} from './lib/pwchecker';
const checker = new PswChecker();
console.log(checker.lengthAboveEight('testtestt'));
console.log(checker.containsNumber('testte1stt'));
console.log(checker.containsUppercase('containsUppercase'));
console.log(checker.containsSpecialCharacter('specialcharacter?'));
console.log(checker.passwordRating('TestinCg1223???'));
