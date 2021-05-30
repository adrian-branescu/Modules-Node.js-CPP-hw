# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: The first module, CommonJS version, doesn't finish its execution, due to a warning: "Accessing non-existent property 'Chicken' of module exports inside circular dependency". 
I think that this has been happening because of the sync loading in modules of CommonJS. When chicken.js loads egg.js, egg.js tries to load chicken.js, and in order to prevent an infinite loop, an unfinished copy of the chicken.js export's object is returned to the egg.js module. 
The execution of the ESM version is an endless loop, followed by a call stack size exceeded error. ESM has support for circular dependencies. 

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: In CommonJS, the variables are exported as copies, so the value of counter in the importing module (index.js) doesn't change if the exporting module (count.js) changes that variable later.
In ESM, the static import statement is used to import read only live bindings, and both modules point to the same location in memory. The value of counter is changed after the increment function is called. 
Both types of modules import the variables as constants, so the value can't be change in index.js, because of that the programs are interrupted by an error: "Assignment to constant variable."
