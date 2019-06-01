# Fiel de Fier

## Table of Contents (Optional)

> If you're `README` has a lot of info, section headers might be nice.

- [Installation](#installation)
- [Features](#features)
- [Contributing](#contributing)
- [Team](#team)
- [FAQ](#faq)
- [Support](#support)
- [License](#license)

---

**About project**

- build status
- issues (waffle.io maybe)
- devDependencies
- npm package
- coverage
- slack
- downloads
- gitter chat
- license
- etc.

> Tips

- HAVE WHITE SPACE
- MAKE IT PRETTY
- GIFS ARE REALLY COOL

> GIF Tools

- Use <a href="http://recordit.co/" target="_blank">**Recordit**</a> to create quicks screencasts of your desktop and export them as `GIF`s.
- For terminal sessions, there's <a href="https://github.com/chjj/ttystudio" target="_blank">**ttystudio**</a> which also supports exporting `GIF`s.

**FdF manipulations**

![Recordit GIF](http://g.recordit.co/gx9TAVBBAV.gif)

**Vietnam map manipulations + meme bonus**

![Recordit GIF](http://g.recordit.co/4J3VDbQ1d6.gif)

---


## Installation

- You have to download Minilibx library to run FdF on your Mac.

### Clone

- Clone this repo to your local machine using `https://github.com/natqegu/fdf.git`

### Setup

> run the project using Makefile feature

```shell
$ make
```

> now you can run executable file 'fdf' with optional map

```shell
$ ./fdf maps/42.fdf
```

> you can clean a workspace of object files, created during compilation

```shell
$ make clean
```

> and also delete every file created during compilation

```shell
$ make fclean
```

---

## FAQ

- **Can I run the project on Windows?**
    - No!
- **Can I create my own maps?**
    - Yes, for that you have to create your own file with '.fdf' extention, or clone Map generator 'https://github.com/jgigault/42MapGenerator.git'.