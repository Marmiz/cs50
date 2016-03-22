# Objectives

* Introduction to JavaScript, Ajax, JSON.

* Exposure to objects and methods.

* Grapple with real-world APIs and libraries.

---

**mashup** integrates Google Maps with Google News with a MySQL database containing thousands of postal codes, GPS coordinates, and more. Quite like this here version by the staff!

https://mashup.cs50.net/

Not only can you search for places via the text box up top, you can also click on and drag the map elsewhere. Scattered across the map, meanwhile, are newspaper icons that, when clicked, provide links to local news!

You may notice that some markers (and labels) overlap others or are otherwise at the wrong coordinates. The GeoNames geographical database that we’re using is actually imperfect, whereby some places' coordinates are off. For instance, East Boston isn’t in Back Bay. And Readville isn’t in Boston Harbor. Not to worry if you see those same symptoms in your mashup, assuming the source of the problem is indeed the data itself!

---

##### Import


Is a command-line script in PHP that accepts as a command-line argument the path to a file (which can be assumed to be formatted like US.txt) that iterates over the file’s lines, inserting each as new row in places.
To run this script, you’ll want to execute a command like

```
./import /path/to/US.txt
```

##### Search.php

search.php outputs a JSON array of objects, each of which represents a row from places that somehow matches the value of geo.

##### Configure

configure, the function in scripts.js, displays matches in the searchbox.

##### AddMarker

addMarker (in scripts.js) adds a marker for place on the map, where place is a JavaScript object that represents a row from places, your MySQL table.
When a marker is clicked, it should trigger the mashup’s info window to open, anchored at that same marker, the contents of which should be an unordered list of links to article for that article’s location (unless articles.php outputs an empty array).

##### RemoveMarker

Remove all marker from the table.

###### Personal Flavour

As personal touch, I've created the option to toggle on and off the markers on the map.
