# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: esm-chicken-egg returns repeatedly the lines: 
```
Asking the Egg 
Asking the Chicken
```
until RangeError: Maximum call stack size exceeded is thrown.
csj-chicken-egg returns the following message:
```
Asking the Egg 
typeof Chicken is undefined 
Egg was first 
(node:49314) Warning: Accessing non-existent property 'Chicken' of module exports inside circular dependency
```
We will explain what happens in the cjs module example: firstly, the Chicken is required. Before getting to the class definition, inside Chicken.js Egg.js is required. Inside Egg.js Chicken.js is required again, but, because Chicken.js is not completely loaded, require(...) returns undefined. After that, Egg completes loading and so does Chicken. The problem is that Egg already has an undefined reference for Chicken.
In index.js the function whoWasFirst is called for the chicken. The Egg inside Chicken is not undefined so it calls Egg.whoWasFirst(). In Egg.whoWasFirst Chicken is still undefined. Therefore, it prints the message  "Egg was first".
We notice that the export, in this case, happens by value and the changes of Chicken.js have no effect on the exported value of Chicken in Egg.js.

esm-chicken-egg doesn't have this behavior because we use __export__, which references the object that will be returned by require. Therefore, when Chicken is finally loaded, Egg knows that Chicken changed - it doesn't think Chicken is still undefined.


There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: The result of the esm-live-binding module is
```
0
1
TypeError: Assignment to constant variable
```
The result of cjs-live-binding is 
```
0
0 
TypeError: Assignment to constant variable
```
We notice that in the esm module the counter has updated its value.
This happens because in cjs modules variables are not automatically changed - there's no live binding created. While the cjs modules export values, the esm modules export live bindings - live connections to values. Therefore the change of the counter variable can be seen in esm-live-biding.