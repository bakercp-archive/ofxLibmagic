ofxLibMagic
===========

File type discovery via libmagic (http://sourceforge.net/projects/libmagic/)!

You give it a binary file.  It will return a MIME type and description.


For Linux / Ubuntu
---

```
apt-get install libmagic-dev
```

N.B. For the moment, addons_config.mk is broken.  So, to use, add -lmagic to your PROJECT_LDFLAGS.  This will be fixed soon.


For Windows
---
https://github.com/sleuthkit/c_FileTypeSigModule/blob/master/README_BuildingLibMagicWin32.txt

Cool Thumnail: http://coolmagic.com/magician.jpg