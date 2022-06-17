# Homework

In order to also clone the git submodule referenced inside this repo use:
```bash
git clone --recursive <repo-url>
```

In order to build the container image:
```bash
docker build -t node-hw .
```

In order to run the container:
```bash
docker run -it --rm --name node-hw -v$(pwd):/usr/project node-hw
```
