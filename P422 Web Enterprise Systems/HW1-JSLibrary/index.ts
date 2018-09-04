import {PswChecker} from './lib/pwchecker';
const checker = new PswChecker();
console.log(checker.lengthAboveEight('testtestt'));
console.log(checker.containsNumber('testte1stt'));
console.log(checker.containsUppercase('containsUppercase'));
console.log(checker.containsSpecialCharacter);
