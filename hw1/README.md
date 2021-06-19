# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: In CommonJS, when we ask the chicken, the egg is not undefined so we ask the egg, but in the egg, the chicken is undefined so the egg says it was first. In ESM, when we ask the chicken, the egg is not undefined so we ask the egg. In the egg, the chicken is also not undefined so we ask the chicken and the cycle repeats. It seems that ESM allows 2 modules to reference one another until the stack is full and CommonJS doesn't allow model B to reference module A after module A has already referenced module B.

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: In ESM, the counter gets updated after increment is called, while in CommonJS the counter doesn't change its value (0). Both throw an error when the line "++counter" is executed. It seems that in ESM the object imported is passed as a refference, so the updates in the exporting module are visible in the importing module too, while in CommonJS only the value of the object is passed, so updates in the exporting module are not reflected in the importing module.
