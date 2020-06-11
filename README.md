# EasyVPK
EasyVPK is an easy to use hombrew application for the PSVITA that downloads vpks and data files from [VitaDB](https://vitadb.rinnegatamante.it/#/).

## "Planned features"
- Installing Homebrew apps that come with plugins (for now they get copied to ux0:VPKS/ so you can install them using VitaShell)

## Building

Prerequisites:
- [VitaSDK](https://vitasdk.org/)
- [libsqlite](https://github.com/VitaSmith/libsqlite)

Compiling:
```
cmake .
make
```

## Credits
- [THEN00P](https://github.com/THEN00P) for creating EasyPlugin
- [Rinnegatamante](https://github.com/Rinnegatamante) for helping with VitaDB and other shenanigans
