# Lightroom Spotlight Importer

A Mac Spotlight Importer for Adobe Lightroom Catalogs. Allows users to search for filenames inside catalogs from within the Spotlight window.

## Adobe Lightroom ##

The Adobe Lightroom `.lrcat` catalog files are [sqlite](http://tro.pe/K0QToL) databases. The catalog files do not store the picture files themselves but a reference to them on disk. Executing the following query returns the filenames that are stored in the catalog file:

	SELECT originalFilename FROM AgLibraryFile

## Spotlight Importer ##

Apple provides a mechanism for developers to create custom importers for lesser known or custom file types. The documentation from Apple can be found [here][1].


## FMDB ##

LSI uses the [FMDB][2] Sqlite wrapper for Objective-C.

## Screenshot ##

![screenshot](http://www.codenoevil.com/wp-content/uploads/2012/05/Screen-Shot-2012-05-09-at-8.39.59-PM.png)


[1]: http://tro.pe/K0RtTG "Spotlight Importer Programming Guide"
[2]: http://tro.pe/K0U5B1 "FMDB"

