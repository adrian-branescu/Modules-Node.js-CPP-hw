# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: With CJS the programm is terminated with a warning and prints "Egg is first", while the ESM version creates an infinite loop. Allowing circular dependencies is an advantage of ESM because sometimes it's better not to automatically stop the programm, but to let the programmers decide. 

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: ESM uses live bindings - which means that the variable change made by the exporting module is seen in the importing module as well. In the ESM example, the value for counter is incremented from 0 to 1 after the function call, while in the Commom JS example it remains 0 even after the function call.

https://railsware.com/blog/how-to-analyze-circular-dependencies-in-es6/ 

https://hacks.mozilla.org/2018/03/es-modules-a-cartoon-deep-dive/