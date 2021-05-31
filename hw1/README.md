# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: In CommonJS, require() is synchronous and the modules are loaded synchronously as well and processed
in the order the JavaScript runtime finds them. I think this means that from index exists an instance
of Chicken and from Chicken an instance of Egg. But when Egg wants to call a new instance of Chicken,
it doesn't exist, because the require cannot be loaded again.

    Trigger the chicken - egg endless loop ..
    Asking the Egg
    typeof Chicken is undefined
    Egg was first
    Warning: Accessing non-existent property 'Chicken' of module exports inside circular dependency

In ESM, the module loader runs in asynchronous phases. So there are creating as many instances as possible.
Here appears the loop

    Trigger the chicken - egg endless loop ..
    Asking the Chicken
    Asking the Egg
    Asking the Chicken
    Asking the Egg
    Asking the Chicken
    Asking the Egg...
and the error is produce by the stack (isStackOverflowError()).

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: In the CommonJS example, we can see that the program returns:

    0
    0
    ++counter; TypeError: Assiment to constant variable

This happens because importing modules cannot see changes 
happened on the exporter side(the variables are copies of the original ones) 

In ESM when the exporting module changes a value, the change will be  visible from the importer side too.

    0
    1
    ++counter; TypeError: Assiment to constant variable




