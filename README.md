# Homework

In order to build the container image:
```bash
docker build -t node-hw .
```

In order to run the container:
```bash
docker run -it --rm --name node-hw -v$(pwd):/usr/project node-hw
```
