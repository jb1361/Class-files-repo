describe("Password Checker", function() {
    const PswChecker = require('../lib/pwchecker');
    const checker = new PswChecker();
    it("password above eight characters pass", function() {
        let test = checker.lengthAboveEight('password1');
        expect(test).toBe(true);
    });
    // it("password above eight characters fail", function() {
    //     let test = checker.lengthAboveEight('password');
    //     expected(test).toBe(false);
    // });
});