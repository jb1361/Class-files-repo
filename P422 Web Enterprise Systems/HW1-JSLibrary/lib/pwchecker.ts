export class PswChecker {
    public lengthAboveEight(x: string) {
        return x.length > 8;
    }
    public containsNumber(x: string) {
        return /\d/.test(x);
    }
    public containsUppercase(x: string) {
        for (let i = 0; i < x.length; i++) {
            if (x[i] === x[i].toUpperCase()) return true;
        }
        return false;
    }
    public containsSpecialCharacter(x: string) {
        x = x.toLowerCase().replace(/[^a-zA-Z0-9]+/g, '');
        console.log('test: ', x);
        return (x.length > 0);
    }
}

// String.prototype.cleanup = function() {
//     return this.toLowerCase().replace(/[^a-zA-Z0-9]+/g, "-");
// }
