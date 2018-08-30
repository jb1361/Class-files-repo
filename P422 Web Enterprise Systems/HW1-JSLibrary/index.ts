import {PswChecker} from './lib/pwchecker';
let checker = new PswChecker();
console.log(checker.lengthAboveEight('testtestt'));
console.log(checker.containsNumber('testte1stt'));
console.log(checker.containsUppercase('containsUppercase'));
console.log(checker.containsSpecialCharacter('containsSpecialCharacter'));
