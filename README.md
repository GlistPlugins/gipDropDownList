# gipDropDownList
This plugin creates a Drop Down List where you can retrive the content of the selected item as a string.

## Installation
Fork & clone this project into ~/dev/glist/glistplugins

## Usage
1. First copy the assets folder in the plugin directory to the GlistApp assets folder.
2. Add gipDropDownList into plugins of your GlistApp/CMakeLists.txt
  >set(PLUGINS gipDropDownList)
3.Include gipDropDownList.h in GameCanvas.h
  >#include "gipDropDownList.h"
4. Crate an instance of the list inside your header file by typing:
  >gipDropDownList list;
5. Create the list inside setup() function of the GameCanvas:
  >list.create(100, 100);
6. Add some items inside it inside setup() function of the GameCanvas:
  >list.addItem("Hello World");
7. Draw it on the screen inside draw() function of the GameCanvas:
  >list.draw();

## License
Apache 2.0
