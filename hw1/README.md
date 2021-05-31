# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: In the `esm-*` examples the cyclic dependency causes stack overflow, meanwhile in the `cjs-*` examples the cyclic dependency outputs `Egg was first`. My guess is that this is because the commonjs modules are immediately being run(the `require` is synchronous), and by the time `Egg.whoWasFirst` is called the `Chicken` class hasn't yet fully been interpreted and is undefined.

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: The esm example outputs `0 1` and then a `TypeError`, the `cjs` examples outputs `0 0` and the a `TypeError`. I'd say this is because the commonjs module doesn't actually have a global variable, and the `x` will be local the `index.js` file.
