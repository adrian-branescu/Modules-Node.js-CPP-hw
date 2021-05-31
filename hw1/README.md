# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: The CommonJS version outputs "Asking the Egg; typeof Chicken is undefined; Egg was first", while the ESM version enters in an infinite loop, printing "Asking the Chicken; Asking the Egg; Asking the Chicken; Asking the Egg" and so on.
	The problem with CommonJS is that Chicken requires Egg and Egg requires Chicken, resulting in an undefined Chicken. On the other hand, the ESM version can have both the Chicken and the Egg defined at the same time, enabling the desired endless loop.

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: The CommonJS version outputs "0; 0", while the ESM version outputs "0; 1". The increment succeeds in the latter due to live bindings, a concept introduced in ESM, providing a common memory address for both exporter and importer. In CommonJS module exports are simply copied, hiding changes made, like the increment in the given example.
