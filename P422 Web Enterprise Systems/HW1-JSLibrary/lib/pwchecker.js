export class pswChecker {
    lengthAboveEight(x) {
        return x.length > 8;
    }
    containsNumber(x) {
        return /\d/.test(x);
    }
    containsUppercase(x) {
        for(let i =0; i < x.length; i++) {
            if (character === character.toUpperase()) return true;
        }
        return false;
    }
}