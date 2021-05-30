# Modules

ESM is the new standard for Javascript modules. The main selling point is that it allows code reuse in a standard manner no matter the platform that embeds the Javascript engine: Browser, Node.js, Mobile etc.

CommonJS format, although not standard, was extremly popular in both Node.js and Browser world until ESM appeared.
It's main disadvantage is that the Node.js module cannot be reused as it is in Browser, some transpiling and packaging is necessary - babel and webpack being the most used tools for this task.

Besides the short description above you will also notice the difference between the two regarding cyclic dependency handling by running the entry-points of the two chicken-egg modules.

Note that the cyclic dependency may happen often in real-life projects, although not desired. I chose to trigger an endless loop, but usually it's not the case - the cyclic dependency may be legit and benign in its nature.

Q1: What difference do you observe between the two and try to explain why this happens?

A1: In the CJS case, it seems like only 1 level of recurrence is "rendered". When we ask the egg who was first, it tries to call the chicken, which requires another egg instance, which is not found. In the ESM case, all of the layers are taken care of. As a comparison, it seems like the CJS is inserting the code required once and that's it.

There is another major difference between the two formats regarding how the symbols exported by a module are consumed by its clients. In order to observe it, run the entry-points of the two live-binding modules.

Q2: What difference do you observe between the two and try to explain why this happens?

A2: In the CJS case, we get "0, 0" and in the EJS scenario we get "0, 1". I assume this is happening because CJS doesn't make a live connection between the files. It looks like it took the value from the required file, and from that point on, it acted like a different variable from the one inside the requred file (feels like 2 variables with the same purpose existed at the same time). Differently, EJS made a live link between the files, so when calling the function the variable modification spread to the entry point as well (since we are talking about the same variable in both places).
