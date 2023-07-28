Install your local application by adding to the package.json at this level:
```
    "app":"file:./"
```

If this repo is for developing a widget also add:   
```
    "@loupeteam/widgets-[mywidget]":"file:../../src/hmi"
```

Your package json will be something like this:
```
{
  "name": "myhmi",
  "version": "0.0.1",
  "description": "User HMI",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "repository": {
    "type": "git",
    "url": "git+https://github.com/loupeteam/userrepo.git"
  },
  "dependencies": {
    "app":"file:./",
    "@loupeteam/widgets-[mywidget]":"file:../../src/HMI"
  },
}
```


After these are added:
```
npm install
```

