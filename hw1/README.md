# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: The ESM module triggers the loop and the loop goes on until the stack overflows and a RangeError is returned, whereas the commonJS module
exits the loop immediately with a warning. The warning states that there's an attempt to access a non existing property of module exports, because the Chicken class is not instantiated. The cjs module has a better behaviour in this context because usually these cyclic dependencies are not desired and need to be fixed, so the module gives a warning and gets out ot the infinite loop.

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: ESM imports variables of any type as constants, therefore their value cannot be changed directly so we need to export a function that is imported in the script where the variable change is needed. This is not the case when using a cjs module, where a value can be changed directly if importing it with the 'let' keyword, but calling a function that changes the value defined in the foreign (imported) script does nothing.
