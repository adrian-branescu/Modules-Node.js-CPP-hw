import { Egg } from './Egg.js';

class Chicken {

    static whoWasFirst() {

        if (typeof Egg !== 'undefined') {

            console.log(`Asking the ${Egg.name}`);

            return Egg.whoWasFirst();
        }

        console.log(`typeof Egg is ${typeof Egg}`);

        // btw, here 'this' refers to the class itself as the method is static
        console.log(`${this.name} was first`);
    }
}

export { Chicken };
