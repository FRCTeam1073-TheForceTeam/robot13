echo Deleting Robot Builder temporary files
find . -name '*.~' -print0 | xargs -0 rm
echo Robot Builder temporary files deleted