# Node.js C++ Addons

You will have to make an addon to expose in Node.js the [C++ library](https://github.com/adrian-branescu/Modules-Node.js-CPP-lab/tree/cpp-3/lab/cpp/my-sqrt-lib) used in class presentation.

Make sure the binding works fine by calling `mysqrt` function from Javascript code.

As a starting point, you should read https://nodejs.org/docs/latest/api/addons.html

Note that there are multiple ways of achieving this, but you must use Node-API (or N-API), not Native Abstractions for Node.js (or nan), nor directly V8 API.

N-API is the official recommended way to build C++ Addons and abstracts away API changes that happen when updating Node.js to a newer version (and implicitly the V8 engine).

I think I was supposed to solve the assignment using the shared library but I didn't manage to do so (I'd like to find out how). Instead I added the header and the .cxx file to this folder to access them in my addon. Calling the mysqrt function from JavaScript works, but I don't think I was supposed to do it this way.
