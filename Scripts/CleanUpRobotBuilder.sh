echo Deleting Robot Builder temporary files
cd ..
find . -name '*.~' -print0 | xargs -0 rm
rm ~botBuilderConfiguration.yml
echo Robot Builder temporary files deleted