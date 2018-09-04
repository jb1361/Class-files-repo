export class PswChecker {
    public lengthAboveEight(x: string) {
        return x.length > 8;
    }
    public containsNumber(x: string) {
        return x.replace(/[^0-9]/g, '').length > 0;
    }
    public containsUppercase(x: string) {
        return x.replace(/[^A-Z]/g, '').length > 0;
    }
    public containsSpecialCharacter(x: string) {
        return x.toLowerCase().replace(/[a-zA-Z0-9]+/g, '').length > 0;
    }
    public passwordRating(x: string) {
        const specialCharacters = x.toLowerCase().replace(/[a-zA-Z0-9]+/g, '').length;
        const capitalLetters = x.replace(/[^A-Z]/g, '').length;
        const numbers = x.replace(/[^0-9]/g, '').length;
        return (specialCharacters + capitalLetters + numbers);
    }
}
