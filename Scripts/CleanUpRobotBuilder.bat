@ECHO OFF
ECHO Deleting Robot Builder temporary files
CD ..
DEL /S *.h~
DEL /S *.cpp~
DEL /S *.yml~
DEL /S *.html~
DEL /S *.wrproject~
DEL /S *.cproject~
DEL /S *.project~
DEL /S *.wrmakefile~
DEL ~botBuilderConfiguration.yml
ECHO Robot Builder temporary files have been deleted