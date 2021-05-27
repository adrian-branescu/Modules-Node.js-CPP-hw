const { Chicken } = require('./Chicken.js');

class Egg {

    static whoWasFirst() {

        if (typeof Chicken !== 'undefined') {

            console.log(`Asking the ${Chicken.name}`);

            return Chicken.whoWasFirst();
        }

        console.log(`typeof Chicken is ${typeof Chicken}`);

        // btw, here 'this' refers to the class itself as the method is static
        console.log(`${this.name} was first`);
    }
}

module.exports = {
    Egg
};
