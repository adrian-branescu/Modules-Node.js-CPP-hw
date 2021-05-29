# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1:As observed in the results, ESM ends up in a stack size exceeding loop while CJS end up only with a cycle (chicken->egg-> result). 
I think in this case there will be a conflict about the required modules: A will require B but then B will require A and B will receive an unfinished copy of the module A. 
In our example:
When Chicken requires Egg, Egg will require Chicken and thereforethe module Egg will require an unfinished, unreferenced Chicken  - so that Egg won't have a defined function named Chicken.

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: ESM ended with the value incremented from 0 to 1 while CSJ resulted with 0 to again 0. 
The difference stands in the referencee kept along the calls. An ESM module would rather keep an alive referencee (live binding) of the "state" of the module. That's why counter won't stay at the 0 value. At every increment() call, the last value of counter would be taken into consideration. What the ESM module exports is a kept alive referencee, therefore the changes will be visible outside the module.
CJS does the opposite: the "counter" value won't be returned as something else but the one specified in exports (the 0 value). Any change made inside will be lost once exported. 
